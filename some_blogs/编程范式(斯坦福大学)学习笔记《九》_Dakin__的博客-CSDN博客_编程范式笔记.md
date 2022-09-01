## 编程范式(斯坦福大学)学习笔记《九》

![](https://csdnimg.cn/release/blogv2/dist/pc/img/original.png)

[Dakin\_\_](https://blog.csdn.net/Dakin_) ![](https://csdnimg.cn/release/blogv2/dist/pc/img/newCurrentTime2.png) 于 2018-07-17 18:24:21 发布 ![](https://csdnimg.cn/release/blogv2/dist/pc/img/articleReadEyes2.png) 408

版权声明：本文为博主原创文章，遵循 [CC 4.0 BY-SA](http://creativecommons.org/licenses/by-sa/4.0/) 版权协议，转载请附上原文出处链接和本声明。

接下来的课程会涉及到[计算机体系结构](https://so.csdn.net/so/search?q=%E8%AE%A1%E7%AE%97%E6%9C%BA%E4%BD%93%E7%B3%BB%E7%BB%93%E6%9E%84&spm=1001.2101.3001.7020)和汇编语言，解释C/C++代码片段是如何编译成汇编代码的，内存模型，函数调用，函数返回的类型等。

___

4字节变量的例子：

```
int i;int j;i=10;j=i+7;j++;
```

对应的汇编代码：

```
M[R1+4]=10;R2=M[R1+4];R3=R2+7;M[R1]=R3;R2=M[R1];R2=R2+1;M[R1]=R2;
```

_注意：_

1.大写的M代表整个RAM的名字，可以将整个RAM看做一个非常大的字节数组，M则是这个数组的名字，R1存储着基地址，4是偏移量。

2.不能直接进行M\[R1\]++操作，因为这里的[汇编语言](https://so.csdn.net/so/search?q=%E6%B1%87%E7%BC%96%E8%AF%AD%E8%A8%80&spm=1001.2101.3001.7020)指令不允许任意内存地址作为ALU运算操作的操作数，必须先使用load操作，然后使用寄存器的值作为操作数执行ALU操作，然后再将结果写回内存中。这样的操作会令我们的汇编语言更加简单，并且当指令简单时，时钟频率也会较快。

3.默认情况下load、store以及ALU操作处理的都是4字节的数据，因为在C\\C++语言中指针和int类型是非常常用的类型，因此硬件对这种4字节的内存的存取进行了优化。

___

非4字节变量的例子：

```
int i;short s1;short s2;i=200;s1=i;s=s1+1;
```

对应的汇编代码：

```
M[R1+4]=200;R2=M[R1+4];M[R1+2]=.2 R2;R2=.2 M[R1+2];R3=R2+1;M[R1]=.2 R3;
```

_注意_：

使用.2屏蔽掉默认处理4个字节这个规则，因为默认的规则假定所有这类的指令都隐含一个.4，当想要移动2个字节或者1个字节时就需要写上.2或者.1。

___

```
int arr[4];int i;for(i=0;i<4;i++) {    arr[i]=0;}i--;
```

对应的汇编代码：

```
M[R1]=0;R2=M[R1];BGE(R2,4，PC+40)R3=M[R1];R4=R3*4;R5=R1+4;R6=R4+R5;M[R6]=0；R2=M[R1];R2=R2+1;M[R1]=R2;JMP PC-40R2=M[R1]；R2=R2-1；M[R1]=R2;
```

_注意：_

1.分支指令（branch instructions）的缩写：BEQ，BNE，BLT，BLE，BGT，BGE。

2.在所有的汇编代码中都不能使用sizeof(int)，必须手动计算C和C++中的类型所占空间大小。

___

指令编码：

```
R1=M[R2+4];R1=1000;R3=R6*R10;M[R1-20]=R19;
```

这四条指令的用6为字节表示opcode（也就是硬件能够看懂的01机器码）都不同，硬件会在时钟周期的前一部分查看前6位是什么，然后再决定如何解释剩下的26位。

___

```
struct fraction{int num;int denum;}struct fraction pi;pi.num=22;pi.denum=7;((struct fraction*)&pi.denum)->denum=451;
```

对应的汇编代码：

```
M[R1+8]=451M[R1]=22;M[R1+4]=7;
```

在生成的汇编代码中是没有与强制类型转换相对应的指令，强制转换作用是只是允许编译器能够产生汇编代码。强制类型转换让编译器允许绕过类型检查的机制进而通过编译生成代码。