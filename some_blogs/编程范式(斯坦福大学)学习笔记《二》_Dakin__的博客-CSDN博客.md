## 编程范式(斯坦福大学)学习笔记《二》

![](https://csdnimg.cn/release/blogv2/dist/pc/img/reprint.png)

[Dakin\_\_](https://blog.csdn.net/Dakin_) ![](https://csdnimg.cn/release/blogv2/dist/pc/img/newCurrentTime2.png) 于 2018-07-06 17:11:26 发布 ![](https://csdnimg.cn/release/blogv2/dist/pc/img/articleReadEyes2.png) 509

[斯坦福大学开放课程：编程范式学习笔记《二》](http://www.cppblog.com/deercoder/archive/2012/05/13/174774.html)

本课讲述了C/C++关于int，float等数据的底层表示，以及赋值操作所进行的处理。本节内容比较简单，应该属于组成原理的基础知识，各种码的表示和底层实现，但是，讲述还不错，特别是为何要这样形成补码，比单纯记忆强多了，这样才理解了取反加1的原因，比当初上课的时候要理解深刻多了。

bool    1byte  
char    1 byte  
short   2 bytes  
int        2-4 bytes  
float     4bytes  
double  8bytes

binary  digit ==> bit  
1byte = 8种bit的组合，即共有2的8次方这么多种选择。  
每一位都有权值，对应的，2的0次方依次往上递增。

short：2 bytes表示，共有2的16次方表示  
但是并不是完全表示正数，最开始的符号位，1为负数，0为正数（实际上就是反码的表示方法）  
缺陷： +7 + （-7），最终得到的数值用反码来表示的话不是0。  
因此，计算机处理起来很麻烦，以备淘汰

更优的办法是：补码表示，取反加1.  
为何？ 从计算机表示的角度出发，+7 加上什么为0呢？ 接近0的数是，全部为1的（-1），然后加上1就可以溢出符号位，从而表示为0.  
因此顺理成章的，负数的表示就是，正数的基础上，取反， 然后加1.

一个例子：  
char ch = 'A';  
short s = ch;（不需要类型转换）  
cout << s结果是，65.  
如何做的呢？计算机，just copy   
bit pattern copy的形式，不管你的类型如何，直接进行拷贝，由于short比char多一个字符，所以拷贝的前一个byte直接用全0来复制。

现在，另外考虑一个例子，截断。  
short s = 67;  
char ch = s;  
问题是，short比char 要多一个byte，那么赋值的话，是尽可能的接近吗？  
NO，计算机不懂值得大小，只会单纯的copy，因此，截断后面的1byte赋值过去而已。

同样的，讲short赋值给int的时候也是这样处理的，高位全部copy为0，地位直接copy。而int赋值给short的时候，就是单纯的截断处理而已。  
现在的问题来了，如果是负数呢？  
short s =-1;  
int i = s;  
这个时候，前面的高位字节直接赋值为0的话，事实上数值的大小是变化的。因此计算机的做法是，拷贝符号位复制到高位。这样正数，就是拷贝的0，所以高位全为0，而负数的话高位1，拷贝的话，高位全1.最终保证i的值仍然是-1.

接下来学习float的表示。  
我们可以自定义一种解释float的方法。权重依次降低，比如从2的31次方到2的0次方，变为2的29次方到2的-1次方，最开始的那一位表示为+/-符号位，这样就可以表示一定的浮点数，同样的，再次降低权重就可以表示更低的数据了。  
但是，实际上计算机的表示不是这样的

采用了一种很奇怪的表示方法，即符号位（1位） + exp位（8位） + 浮点部分（23位）。  
符号位表示政府，exp为8位的正数表示，浮点数表示0.XXXXX（0到1之间的数据）  
最终浮点的值是，2的（exp - 127）次方 乘以 1.XXXX表示。

最后两个例子表示值拷贝的过程。  
int i = 5;  
float f = i;  
输出的结果是f仍然是5，why？ 因为不是bit copy，这里是直接进行赋值，而类型不同，因此会先计算出来值得带下，然后转换一种类型表示出来。  
也就是把5的int类型表示为float的类型，bit pattern是完全发生了变化的。

另外一个例子。  
int i = 37;  
float f = \*(float \*) &i;  
这种是把i的地址取出来，认为它表示的是float，因为（float \*）的作用，然后解释为float类型输出它的值，注意的是，bit pattern并不会发生变化。

float f = 7.0;  
short s = \*(short \*) &f;  
由于是不同的类型，short只会截取自己那么大size的byte来进行翻译，所以float类型尽管4bytes，但是认为是short类型的话，仍然截取的是2bytes。  
从而输出short的值应该是一个比较小的值。注意，bit pattern并不会改变，只是取出来地址而已。

总结的关键是：just copy bit pattern!