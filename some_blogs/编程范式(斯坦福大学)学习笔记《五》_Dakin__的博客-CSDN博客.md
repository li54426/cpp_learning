**线性搜索**

```
void *lsearch(void* key,void base,int n,int elemSize, int (*cmpfn)(void *,void *)){for(int i<0;i<n;i++) {void* elemAddr=(char*)base+i*elemSize;if(cmpfn(key,elemAddr)==0)return elemAddr;    }return NULL;}  
```

代码第三行：为什么要对base指针进行强制类型转换，转换成char呢？这跟上一篇文章中的讲到的原因一样，对于int类型的指针来说，我们知道每次进行++操作，指针会自增4字节，然而对于void类型指针进行加法操作，编译器不知道每次要加多少。所以我们将base指针强制转换成char，这样编译器就知道指针加法的基数是1。

```
int array[]={4,2,3,7,11,6};int size=6;int number=7;int* found=lsearch(&member,array,6,sizeof(int)，intCmp);if(found==NULL){...}else{...}
```

下面我们来看cmpFn的实现，假如我们要查找的类型是int，则：

```
int intCmp(void* vp1,void* vp2){int* ip1 = vp1;int* ip2 = vp2;return *ip1 - *ip2;}
```

不过必须认识到：这种写法并不是支持泛型的最简明的方式，他只是C语言及其规范中能用的最好的方式，但这种方式执行速度更快，而且只需要一份代码副本来完成所有的线性搜索。

OK,假如现在我们有一个字符串数组：

```
char *notes={"Ab","F#","B","Gb","D"}；
```

利用上面的lSearch代码，我们要查找"Eb"，则调用形式应该是： 

```
char *favoriteNote="Eb"；char **found = lsearch(&favoriteNote,notes,5,sizeof(char *),StrCmp)；
```

其中strCmp是我们要自己提供的。注意lsearch的的第一个参数是一个void类型，而favoriteNote是char类型，这里我们传递给它的则是favoriteNote的取地址，即一个（char\*\*）类型的变量,并且elemSize取的是char类型指针的大小。我们先实现strCmp，然后再来说为什么。

```
int StrCmp(void* ip1,void* ip2){char* s1=*(char **)vp1;char* s2=*(char **)vp2;return strcmp(s1,s2);}
```

这里我们将两个void指针强制转换成char\*\*类型，然后再进行解引用。这样做的意义在于，针对字符串数组来说，字符串是存储在常量区域的，字符串类型的变量是一个指针，而字符串数组存储的就是这些指针。对于notes\[1\]来说，它存储的是一个地址，这个地址指向的内存空间存储的是"F#"。假如我们直接写成：

```
char *s1=(char *)vp1;
```

那么，StrCmp比较的则是存储字符串的地址，而不是字符串本身。这也是为什么lsearch的第一个参数，我们传递的是favoriteNote的取地址，而不是直接的favoriteNote。

stack的纯C语言实现（只针对于int型）：

```
typedef struct{int *elems;int logicalLen;int allocLen;}stack;void StackNew(stack *s);         void StackDispose(stack *s);    void StackPush(stack *s, int value);       int StackPop(stack *s);         stack s；StackNew(&s);for(int i=0;i<5;i++){          StackPush(&s， i);}                              StackDispose(&s);
```

```
void StackNew（stack *s）{s->logicalLen=0;s->allocLen=4;s->elems=malloc(4*sizeof(int));assert(s->element != NULL)}void SatckDispose(){free(s->elems)；}
```