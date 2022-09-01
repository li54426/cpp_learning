## C++四种编程范式小结

## 1\. [面向过程](https://so.csdn.net/so/search?q=%E9%9D%A2%E5%90%91%E8%BF%87%E7%A8%8B&spm=1001.2101.3001.7020)（Procedure Programming, PP）

面向过程编程（Procedure Programming, PP），也被称为命令式编程，也是大家最为熟悉的一种传统的编程方式。从本质上讲，它是“冯.诺伊曼机“运行机制的抽象，它的编程思维方式源于计算机指令的顺序排列。

面向过程编程的步骤：  
首先，我们必须将待解问题的解决方案抽象为一系列概念化的步骤。然后通过编程的方式将这些步骤转化为程序指令集（算法），而这些指令按照一定的顺序排列，用来说明如何执行一个任务或解决一个问题。这就意味着，程序员必须要知道程序要完成什么，并且告诉计算机如何来进行所需的计算工作，包括每个细节操作。简言之，就是将计算机看作一个善始善终服从命令的装置。

代码如下：

```
int add(int a, int b) {
    return a + b;
}
```

## 2\. 面向对象（Object Oriented Programming, OOP）

面向对象编程（Object Oriented Programming, OOP），包含类、对象、封装、继承、多态、重载等机制，通过类和类之间的消息机制建模，提倡针对不同的场景问题构建不同的数据结构，通过方法的调用或消息的互通实现程序交互。就C++而言，OOP 的意思是利用类层级（classhierarchies）及虚函数进行编程，从而可以通过精制的接口操作各种类型的对象，并且程序本身也可以通过派生（derivation）进行功能增量扩展。

托马斯.库恩提出“科学的革命”的范式论之后，Robert Floyd在1979年图灵奖的颁奖演说中使用了编程范式一词。编程范式一般包括三个方面，以OOP为例：

包括三个方面，以OOP为例：

1.  学科的逻辑体系——规则范式：如类/对象、继承、动态绑定、方法改写、对象替换等等机制。
2.  心理认知因素——心理范式：按照面向对象编程之父Alan Kay的观点，“计算就是模拟”。OOP范式极其重视隐喻（metaphor）的价值，通过拟人化，按照自然的方式模拟自然。  
    3.自然观/世界观——观念范式：强调程序的组织技术，视程序为松散耦合的对象/类的集合，以继承机制将类组织成一个层次结构，把程序运行视为相互服务的对象们之间的对话。

```
class AddClass {
public :
    int operator()(int a, int b)
     {  // 类中重载（）
        return a + b;
    }
};
```

## 3\. 泛型编程（Generic Programming，GP）

所谓泛型编程就是独立于任何特定类型的方式编写代码，使用泛型程序时，需要提供具体陈旭实例所操作的类型或者值。我们经常用到STL容器、迭代器、和算法都是泛型编程的例子；

模板是C++支持参数化多态的工具，使用模板可以使用户为类或者函数声明一种一般模式，使得类中的某些数据成员或者成员函数的参数、返回值取得任意类型；  
模板是一种对类型进行参数化的工具；  
通常有两种形式：函数模板和类模板；  
函数模板针对仅参数类型不同的函数；  
类模板针对仅数据成员和成员函数类型不同的类；  
使用模板的目的就是能够让程序员编写与类型无关的代码。比如编写了一个交换两个整型int 类型的swap函数，这个函数就只能实现int 型，对double，字符这些类型无法实现，要实现这些类型的交换就要重新编写另一个swap函数。使用模板的目的就是要让这程序的实现与类型无关，比如一个swap模板函数，即可以实现int 型，又可以实现double型的交换。具体关于C++泛型编程例子

```
// 模板函数
template<typename T, typename U>
auto add3(T &&a, U &&b) -> decltype(a + b)
 {  
 // decltype为类型说明符
return a + b;
}
```

其中上面程序decltype(a + b)中decltype为C++11新标准引进的类型说明符，他的作用是返回操作数的数据类型，编译器分析表达式得到它的类型，去不实际计算表达式的值。这样可以通过表达式推断出要定义的变量类型，但是不用该表达式的值初始化变量，有点类似auto，auto在初始化可以用，如下：

```
auto f=[](int a,int b){return a+b;};//与上面lambda表达式的声明是等价的
```

## 4\. 函数编程（Lambda 表达式实现）

函数式编程，是将程序描述为表达式和变换，以数学方程的形式建立模型，并且尽量避免可变的状态。C++11中引入了lambda表达式的概念。一个lambda表达式标识一个可调用的代码单元，我们可以将其理解为一个未命名的内联函数。

一个lambda表达式具有如下形式：

**捕获列表->返回类型{函数体}**

我们可以忽略参数列表、箭头和返回类型，但必须永远包含捕获列表和函数体。我们可以按照下面的方式定义一个实现add的lambda表达式：

```
auto add4 = [](int a, int b) -> int { return a+b };
```

综上，1.2.3.4关于C++中用四种方式实现add（）到此完毕，附上最终运行代码：

```
/*************************************************************************
> File Name: add.cpp
> Author:
> Mail: 
> Created Time:
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

int add(int a, int b) {
    return a + b;
}

class AddClass {
public :
    int operator()(int a, int b) {
        return a + b;
    }
};

template<typename T, typename U>
auto add3(T &&a, U &&b) -> decltype(a + b) {
    return a + b;
}

auto add4 = [](int a, int b) -> int {
    return a + b;
};


int main() {
    AddClass add2;
    cout << add(3, 4) << endl;
    cout << add2(3, 4) << endl;
    cout << add3(3, 4) << endl;
    cout << add4(3, 4) << endl;

    A a;
    a = 3;
    return 0;
}
```