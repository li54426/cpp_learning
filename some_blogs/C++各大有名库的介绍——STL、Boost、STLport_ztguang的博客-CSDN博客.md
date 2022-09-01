[http://italks.diandian.com/post/2013-01-16/40047993940](http://italks.diandian.com/post/2013-01-16/40047993940)

在C++中，库的地位是非常高的。C++之父 Bjarne Stroustrup先生多次表示了设计库来扩充功能要好过设计更多的语法的言论。现实中，C++的库门类繁多，解决的问题也是极其广泛，库从轻量级到重 量级的都有。不少都是让人眼界大开，亦或是望而生叹的思维杰作。由于库的数量非常庞大，而且限于笔者水平，其中很多并不了解。所以文中所提的一些库都是比 较著名的大型库。

### **1、C++标准库（STL）**

  
已被实践证明为有工业级别强度的佳作。  
1)、Dinkumware C++ Library 参考站点：[http://www.dinkumware.com/](http://www.dinkumware.com/)

 P.J. Plauger编写的高品质的标准库。P.J. Plauger博士是Dr. Dobb's程序设计杰出奖的获得者。其编写的库长期被Microsoft采用，并且最近Borland也取得了其OEM的license，在其 C/C++的产品中采用Dinkumware的库。

2)、RogueWave Standard C++ Library 参考站点：[http://www.roguewave.com/](http://www.roguewave.com/)

这个库在Borland C++ Builder的早期版本中曾经被采用，后来被其他库给替换了。  
3)、SGI STL 参考站点：[http://www.roguewave.com/](http://www.roguewave.com/)

SGI公司的C++标准模版库。

4)、STLport 参考站点：[http://www.stlport.org/](http://www.stlport.org/)  
SGI STL库的跨平台可移植版本。

### **2、准标准库Boost**

  
[Boost](https://so.csdn.net/so/search?q=Boost&spm=1001.2101.3001.7020)库是一个经过千锤百炼、可移植、提供源代码的C++库，作为标准库的后备，是C++标准化进程的发动机之一。 Boost中比较有名气的有这么几个库：  
**Regex**:正则表达式库  
**Spirit** :LL parser framework，用C++代码直接表达EBNF  
**Graph** :图组件和算法  
**Lambda** :在调用的地方定义短小匿名的函数对象，很实用的functional功能  
**concept check**:检查泛型编程中的concept  
**Mpl** :用模板实现的元编程框架  
**Thread** :可移植的C++多线程库  
**Python** :把C++类和函数映射到Python之中  
**Pool** :内存池管理  
**smart\_ptr** :5个智能指针，学习智能指针必读，一份不错的参考是来自CUJ的文章：  
**Smart Pointers in Boost**,哦，这篇文章可以查到，CUJ是提供在线浏览的。中文版见笔者在《Dr.Dobb's Journal软件研发杂志》第7辑上的译文。  
　Boost总体来说是实用价值很高，质量很高的库。并且由于其对跨平台的强调，对标准C++的强调，是编写平台无关，现代C++的开发者必备的工具。但 是Boost中也有很多是实验性质的东西，在实际的开发中实用需要谨慎。并且很多Boost中的库功能堪称对语言功能的扩展，其构造用尽精巧的手法，不要 贸然的花费时间研读。Boost另外一面，比如Graph这样的库则是具有工业强度，结构良好，非常值得研读的精品代码，并且也可以放心的在产品代码中多 多利用。参考站点：[http://www.boost.org](http://www.boost.org/)

### **3、网络通信**

参考网站：[http://www.pcs.cnu.edu/~dgame/sockets/socketsC++/sockets.html](http://www.pcs.cnu.edu/~dgame/sockets/socketsC++/sockets.html) 又一个对Socket的封装库。

5)、 轻量级的有libevent， libev，

6）、轻量级的Boost的ASIO是一个异步IO库，封装了对Socket的常用操作，简化了基于socket程序的开发。支持跨平台。

7）、轻量级的libevent是一个C语言写的网络库， 官方主要支持的是类linux 操作系统， 最新的版本添加了对windows的IOCP的支持。在跨平台方面主要通过select模型来进行支持。

8）、轻量级的libev是一个C语言写的，只支持linux系统的库， 使用方法类似libevent， 但是非常简洁，代码量是最少的一个库。跨平台支持的不好， 如果你只需要在linux下面运行，那还是可以的。

### **4、GUI**

在众多C++的库中，GUI部分的库算是比较繁荣，也比较引人注目的。

1)、**MFC**(Window)/Win32  
大名鼎鼎的微软基础类库。但是在最近发展以及官方支持上日渐势微。

2)、QT 参考网站：[http://www.trolltech.com](http://www.trolltech.com/)  
　Qt是Trolltech公司的一个多平台的C++图形用户界面应用程序框架。自从1996年早些时候，Qt进入商业领域，它已经成为全世界范围内数千 种成功的应用程序的基础。Qt也是流行的Linux桌面环境KDE 的基础，同时它还支持Windows、Macintosh、Unix/X11等多种平台。\[QT目前已经是Nokia旗下的产品，原官方网站已经失效\]

3)、WxWindows(更名为wxWidgets)参考网站：[http://www.wxwindows.org](http://www.wxwindows.org/)  
跨平台的GUI库。因为其类层次极像MFC.新近的C++ Builder X的GUI设计器就是基于这个库的。\[wangxinus注:迫于微软的施压，已经由WxWindows更名为wxWidgets\]

4)、Fox参考网站：[http://www.fox-toolkit.org/](http://www.fox-toolkit.org/)  
　　开放源代码的GUI库。作者从自己亲身的开发经验中得出了一个理想的GUI库应该是什么样子的感受出发，从而开始了对这个库的开发。有兴趣的可以尝试一下。

5)、WTL　　  
主要面向的使用群体是开发COM轻量级供网络下载的可视化控件的开发者。

6)、GTK参考网站：[http://gtkmm.sourceforge.net/](http://gtkmm.sourceforge.net/)  
　GTK是一个大名鼎鼎的C的开源GUI库。在Linux世界中有Gnome这样的杀手应用。而Qt就是这个库的C++封装版本。\[“Qt就是这个库的 C++封装版本”是错误的。Qt早于GTK，最初Qt由于协议的原因引起社区的不满，另外开发了一个基于C语言的GTK库，后面的扩展版本为GTK＋。 GTK+的Gnome和Qt的KDE是目前linux桌面的两大阵营，曾有水火不容之势。目前双方都以及开源社区的精神，已经和解。\]

### **5、XML**

  
１)、Xerces参考网站：[http://xml.apache.org/xerces-c/](http://xml.apache.org/xerces-c/)

　　Xerces-C++ 是一个非常健壮的XML解析器，它提供了验证，以及SAX和DOM API。

２)、XMLBooster参考网站：[http://www.xmlbooster.com/](http://www.xmlbooster.com/)

　　在DOM和SAX两大主流XML解析办法之外提供了另外一个可行的解决方案。

### **6、科学计算**

### **7、游戏开发**

１)、Audio/Video 3D C++ Programming Library  
 参考网站：[http://www.galacticasoftware.com/products/av/](http://www.galacticasoftware.com/products/av/)　　AV3D是一个跨平台，高性能的C++库。主要的特性是提供3D图形，声效支持（SB,以及S3M），控制接口（键盘，鼠标和遥感），XMS。

２)、KlayGE 参考网站：[http://home.g365.net/enginedev/](http://home.g365.net/enginedev/)  
　国内游戏开发高手自己用C++开发的游戏引擎。KlayGE是一个开放源代码、跨平台的游戏引擎，并使用Python作脚本语言。KlayGE在 LGPL协议下发行。感谢龚敏敏先生为中国游戏开发事业所做出的贡献。 \[这个库国人了解很少，百度百科的KlayGE词条还是本人创建的。一个人开发一个游戏引擎库，是在让笔者汗颜，对作者表示钦佩！\]

３)、OGRE 参考网站：[http://www.ogre3d.org](http://www.ogre3d.org/)  
OGRE（面 向对象的图形渲染引擎）是用C++开发的，使用灵活的面向对象3D引擎。它的目的是让开发者能更方便和直接地开发基于3D硬件设备的应用程序或游戏。引擎 中的类库对更底层的系统库（如：Direct3D和OpenGL）的全部使用细节进行了抽象，并提供了基于现实世界对象的接口和其它类。

### **8、线程**

### **9、序列化**

### **10、字符串**

### **11、综合**

     这是提供zip，e-mail，编码，S/MIME，XML等方面的库。

５)、C++ Portable Types Library (PTypes)参考网站：[http://www.melikyan.com/ptypes/](http://www.melikyan.com/ptypes/)

　　这是STL的比较简单的替代品，以及可移植的多线程和网络库。

６)、LFC 参考网站：[http://lfc.sourceforge.net/](http://lfc.sourceforge.net/)  
　　哦，这又是一个尝试提供一切的C++库

### **12、其他库**

５)、Crypto++

    Crypto++ 库是一个用c++ 编写的密码类库，是一个自由软件。

数据库：

  OTL(连接数据库)

**多媒体类**

SDL (Simple DirectMedia Layer/多媒体直接访问层，用于游戏编程)。

相应的c开源库有ffmpeg、mpeg4、aac、avc、libmad、mpeg1、flac、ac3、ac3、matroska著名的多媒体播放器 TCPMP 天下闻名的跨平台、嵌入式手持设备视频播放器，

**计算机视觉**

OpenCV，因特尔自主的开源库。支持C/C++/Python接口。这个感兴趣的朋友可以玩一下。如果结合OpenCV，你可以做一些外行人觉得很酷的程序。比如说用它的人脸识别函数，来对你的摄像头进行处理，判断人的动作等

**图形图像处理**

GDAL，处理大图像。　要是GIS专业的人肯定会语言到非常大的tif影像，动则几个GB的航空影像。GDAL对大图像的读写支持是非常棒的（像多波段的图像都可以搞定）。支持C++/Java/Python...

国外开源的GIS软件QGIS就是用了gdal

c的图形图像库较多，libjpeg、libpng、zlib、tiff、JBIG、最著名的开源形图像处理软件Cximage

**内存管理：boost::smart\_ptr，Hans-Boehm GC**

自动内存管理，比较轻量级的做法是boost::smart\_ptr，而激进的做法是引入完整的GC机制。目前开源而又比较可靠的GC 中，Hans- Boehm GC无疑是最受信赖的。作为一个保守的GC，Hans-Boehm GC在性能和功能方面都算是卓越。特别是，使用这个GC，你仍然可以delete、free来自己管理内存，对于我们编程习惯的冲击比较小。

**密码及安全：OpenSSL**

OpenSSL 、

**矩阵计算：MTL**：

Blitz++、POOMA、MTL、Boost::uBLAS

**中间件**

1 分布式对象中间件：ICE

2 消息中间件：ZeroMQ 性能非常优越，远远高于RabbitMQ、ActiveMQ、MSMQ等

**配置管理：Lua**

将Lua嵌入到C/C++程序中，而用Lua程序作为配置脚本。这种做法的优势是，Lua语言强大灵活，可以适应 复杂的配置要求。同时，Lua便于嵌入C/C++程序，而且编译执行速度非常快，可以说是目前解决C/C++程序配置管理问题的一个出色方案。

**3D游戏引擎**

1\. Irrlicht [http://irrlicht.sourceforge.net/](http://irrlicht.sourceforge.net/)

2\. Panda3D [http://www.panda3d.org/](http://www.panda3d.org/)

3\. OGRE [http://www.ogre3d.org/](http://www.ogre3d.org/)

4\. Crystal Space [http://www.crystalspace3d.org/main/Main\_Page](http://www.crystalspace3d.org/main/Main_Page)

5、Delta3d [http://www.delta3d.org/index.php](http://www.delta3d.org/index.php)