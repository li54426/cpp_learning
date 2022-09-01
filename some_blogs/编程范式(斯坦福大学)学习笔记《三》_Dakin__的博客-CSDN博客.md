## 编程范式(斯坦福大学)学习笔记《三》

![](https://csdnimg.cn/release/blogv2/dist/pc/img/original.png)

[Dakin\_\_](https://blog.csdn.net/Dakin_) ![](https://csdnimg.cn/release/blogv2/dist/pc/img/newCurrentTime2.png) 于 2018-07-09 21:16:29 发布 ![](https://csdnimg.cn/release/blogv2/dist/pc/img/articleReadEyes2.png) 630

版权声明：本文为博主原创文章，遵循 [CC 4.0 BY-SA](http://creativecommons.org/licenses/by-sa/4.0/) 版权协议，转载请附上原文出处链接和本声明。

本课继续讲解了C语言的[强制类型转换](https://so.csdn.net/so/search?q=%E5%BC%BA%E5%88%B6%E7%B1%BB%E5%9E%8B%E8%BD%AC%E6%8D%A2&spm=1001.2101.3001.7020)，之后介绍了结构体，数组以及结构体中的数组。

**\*和&的技巧**

例1：

```
double d = 3.1416;char ch = *(char*)&d；
```

取出d的地址，并重新解释为char型，然后[解引用](https://so.csdn.net/so/search?q=%E8%A7%A3%E5%BC%95%E7%94%A8&spm=1001.2101.3001.7020)。由于double为8bytes，而char为1bytes，因此ch表示的是原来double中截取1bytes的结果。

 例2：

```
short s = 45;double d = *(double*) & s;
```

取出s的地址，并重新解释为double型，从2bytes变成8bytes，解引用后赋值给d。

**字节存放顺序：大尾（big endian），小尾（small endian）**

字节存放有大尾和小尾之分。如果对应数据的高字节存放在低地址就是大尾，反之，高字节存放在高地址的就是小尾。

例如：

```
short int a = 0x1234
```

大尾存放时：

偏移地址      存放内容

0x0000       0x12

0x0001       0x34

小尾存放：

偏移地址      存放内容

0x0000       0x34

0x0001       0x12

**结构体**

```
struct fraction{int num;int denom;};fraction pi;pi.num= 22;pi.denom= 7;(fraction*) & (pi.denom)) -> num = 12;(fraction*) & (pi.denom)) -> denom = 33;
```

**数组**

```
int array[10];array[0]= 44;array[9]= 100;array[5]= 45;array[10]= 1;array[25]= 25;array[-4]= 77;
```

关于c语言中数组没有边界检查这个问题可以参考

[c/c++中索引超出数组边界问题](https://blog.csdn.net/dakin_/article/details/80967691)

强制类型转换时需要注意字节问题：

```
int arr[5];arr[3]= 128;((short*)arr)[6]= 2;cout<< arr[3] << endl;
```

**结构体中的数组**

```
struct student{char *name;char suid[8];int numUnits;};studentpupils[4];pupils[0].numUnits= 21;pupils[2].name= strdup (“Adam”);pupils[3].name= pupils[0].void +6;strcpy(pupils[1].suid,“40415xx”);strcpy(pupils[3].name,“123456”);pupils[7].suid[11]= “A”;
```

内存大致可以如下图所示：

![](https://img-blog.csdn.net/20180709211018473?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0Rha2luXw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

```
void swap(int *ap, int *bp) {int temp = *ap;*ap = *bp;*bp = temp;};
```

这个swap函数是为了说明：数据类型并不重要，重要是数据的二进制字节数。