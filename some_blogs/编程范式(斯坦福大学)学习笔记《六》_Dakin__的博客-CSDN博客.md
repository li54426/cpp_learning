这节课的内容是使用C来实现一个支持泛型栈。

[C语言实现支持泛型的栈](http://lib.csdn.net/article/c/19762)

一：首先我们先实现一个特定类型的栈(比如用来存储整型的栈)，来看一下实现栈一般都需要哪些内容： 我们分三个文件来实现(stack.h;stack.c;Main.c)。

stack.h  //声明文件,里面包括对Stack以及相应操作(函数)的定义。

```
typedef struct {int *element;int logLength;int allocLength; }stack;void stackNew(stack *s);void stackDispose(stack *s);void stackPush(stack *s, int value);int stackPop(stack *s);
```

通过这个头文件我们可以看出实现一个栈，我们需要一个栈空间，一个指示栈顶元素的标示，为了实现方便我们还添加了一个指示栈空间大小的元素。同时我们还有针对栈实现的操作：初始化栈，推入一个元素，退出一个元素，销毁栈。

下面Stack.c文件是对Stack.h里面声明的函数的实现。

```
#include <stdlib.h>#include <assert.h>#include "Stack.h"void stackNew(stack *s){s->logLength = 0;s->allocLength = 4;s->element = malloc(s->allocLength * sizeof(int));assert(s->element != NULL);return;}void stackDispose(stack *s){free(s->element);return;}void stackPush(stack *s, int value){if (s->logLength == s->allocLength){s->allocLength *= 2;s->element = realloc(s->element, s->allocLength * sizeof(int));assert(s->element != NULL);}s->element[s->logLength++] = value;return;}int stackPop(stack *s){assert(s->logLength > 0);    S -> loglength--;return s->element[s -> logLength];}
```

经过上面的代码我们就实现了具体栈上的操作。下面我们来对这个栈进行测试工作，看看咱们是否已经正确实现了这个栈。

Main.c

```
#include "Stack.h"int main(int argc, char const *argv[]){stack s;stackNew(&s);for (int i = 0; i < 4; ++i){stackPush(&s, i);}printf("%d\n", stackPop(&s));stackDispose(&s);return 0;}
```

二、按照上文所述，我们已经实现了一个可以存放整型数据的栈，并实现了栈上的操作(栈的初始化、入栈、出栈、销毁栈)，然而对于一个栈，我们不能仅仅用来存放整型数据呀，如果我想存放double类型的数据怎么办呢？一种方式是我们再实现一个double类型的栈，那如果我又想存放一个自定义类型的数据呢？看来上面的方式是行不通了，在这里我们将要实现一个支持泛型的栈，实现一个泛型栈的技巧则是利用void指针。首先我们要修改结构体stack的定义，将指向栈空间的指针元素element由int\*修改为viod\*，同时添加一个指示用户数据结构大小的变量int elemSize。然后我们还要修改关于stack一些操作的函数的声明：

//声明 初始化栈的函数

```
void stackNew(stack *s, int elemSize);
```

函数参数添加一项 int elemSize，这一项将用在为栈开辟空间时决定每一个元素的大小的。

```
void stackPush(stack *s, void *elemAddr);
```

添加参数 void \*elemAddr,用来指示要入栈元素的地址。

```
void stackPop(stack *s,void *elemAddr);
```

添加参数 void \*elemAddr,用来指示用来存储出栈元素的地址。

这就是stack.h所做的修改，到现在stack.h文件代码如下：

```
typedef struct {void *element;int elemSize;int logLength;int allocLength; }stack;void stackNew(stack *s, int elemSize);void stackDispose(stack *s);void stackPush(stack *s, void *elemAddr);void stackPop(stack *s,void *elemAddr);
```

继续，我们来修改stack.c文件，修改上述函数的具体实现。

1.stackNew函数要修改分配空间的代码，空间的大小不再是s->allocLength \* sizeof(int),而是s->allocLength \* elemSize。

```
void stackNew(stack *s, int elemSize){Assert(s -> elemSize > 0);s->logLength = 0;s->allocLength = 4;s->elemSize = elemSize;s->element = malloc(s->allocLength * elemSize);assert(s->element != NULL);return;}
```

2. stackDispose的实现

```
void stackDispose(stack *s){free(s->element);return;}
```

3. stackPush函数要修改空间增长的代码，元素入栈代码。为了代码的优雅，我们将空间增长代码也封装成一个函数stackGrow(),在获得栈顶指针的时候，我们不能再单纯的使用栈顶元素logLength指示了，我们需要从具体的内存地址中找到相应的栈顶位置。

```
void *target = (char *)(s->element) + s->logLength * s->elemSize;
```

**注意：**对于void\*来说，不能做指针算数运算，因此将其转换成char\*类型（unsigned long\*也行）再转void\*。

target指针指示的就是栈顶位置的内存地址，我们将其要入栈元素的地址拷贝到我们的栈顶地址中去：

```
memcpy(target, elemAddr, s->elemSize);
```

具体实现代码如下：

```
void stackPush(stack *s, void *elemAddr){if (s->logLength == s->allocLength){stackGrow(s);assert(s->element != NULL);}void *target = (char *)(s->element) + s->logLength * s->elemSize;memcpy(target, elemAddr, s->elemSize);s->logLength++;return;}
```

4.stackGrow函数别标示为局部的或是内部的， 该函数不能再其它文件中被调用。

```
static void stackGrow(stack *s){s->allocLength *= 2;s->element = realloc(s->element, s->allocLength * s->elemSize);return;}
```

5.stackPop函数的实现。

```
void stackPop(stack *s, void *elemAddr){assert(s->logLength > 0);void *source = (char *)(s->element) + (s->logLength - 1) * s->elemSize;memcpy(elemAddr, source, s->elemSize);s->logLength--;printf("Pop:%d ", s->logLength);}
```

那么stack.c总体的代码如下：

```
#include <stdlib.h>#include <stdio.h>#include <assert.h>#include <string.h>#include "Stack.h"static void stackGrow(stack *s){s->allocLength *= 2;s->element = realloc(s->element, s->allocLength * s->elemSize);return;}void stackNew(stack *s, int elemSize){s->logLength = 0;s->allocLength = 4;s->elemSize = elemSize;s->element = malloc(s->allocLength * elemSize);assert(s->element != NULL);return;}void stackDispose(stack *s){free(s->element);return;}void stackPush(stack *s, void *elemAddr){if (s->logLength == s->allocLength){stackGrow(s);assert(s->element != NULL);}void *target = (char *)(s->element) + s->logLength * s->elemSize;memcpy(target, elemAddr, s->elemSize);s->logLength++;return;}void stackPop(stack *s, void *elemAddr){assert(s->logLength > 0);void *source = (char *)(s->element) + (s->logLength - 1) * s->elemSize;memcpy(elemAddr, source, s->elemSize);s->logLength--;printf("Pop:%d ", s->logLength);}
```

接下来我们使用Main.c文件来测试：

```
#include <string.h>#include <stdio.h>#include <stdlib.h>#include "Stack.h"#pragma warning(disable:4996)int main(int argc, char const *argv[]){const char *friends[] = {"Alex","Bob","Caser"};stack strStack;stackNew(&strStack, sizeof(char *));for (int i = 0; i < 3; ++i){char *copy = strdup(friends[i]);stackPush(&strStack, &copy);}for (int j = 0; j < 3; j++){char *name;name = malloc(sizeof(char *));stackPop(&strStack, &name);printf("%s\n", name);free(name);}stackDispose(&strStack);printf("Over\n");return 0;}
```