## 在[虚拟机](https://so.csdn.net/so/search?q=%E8%99%9A%E6%8B%9F%E6%9C%BA&spm=1001.2101.3001.7020)中安装ubuntu 20.04

步骤： 1. 安装虚拟机  
2\. [ubuntu](https://so.csdn.net/so/search?q=ubuntu&spm=1001.2101.3001.7020)下载  
3\. ubuntu安装  
4\. ubuntu中安装c++

## 1.安装虚拟机

这个主要是要找到一个密匙 这个很好找到百度上搜一下就有。  
具体安装教程参考[虚拟机安装教程](https://blog.csdn.net/qq_40950957/article/details/80467513?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522161574249616780264084166%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=161574249616780264084166&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-80467513.first_rank_v2_pc_rank_v29_10&utm_term=%E5%AE%89%E8%A3%85vmware%E8%99%9A%E6%8B%9F%E6%9C%BA)

## 2.ubuntu下载

ubuntu下载建议在官网下载 在其他地方下载容易附带一些垃圾软件.  
Ubuntu中国网站：[https://cn.ubuntu.com/deskto](https://cn.ubuntu.com/deskto)  
2.1进入[VMware](https://so.csdn.net/so/search?q=VMware&spm=1001.2101.3001.7020)创建新的虚拟机  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315013512987.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)  
2.2选择硬件兼容（默认就是是这个 所以直接下一步）  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315013748444.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)  
2.3选择稍后安装  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315013856406.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)  
2.4 选择客户机操作系统（**选linux**）  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315014522557.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.5 选择安装路径  
建议不要选到C盘  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315014541332.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.6 处理器配置，选择4核  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315014631358.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.7 设置虚拟机内存  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315014737405.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.8 设置网络类型  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315014751186.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.9 选择IO控制器类型  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315014808139.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.10选择磁盘类型，默认即可  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315014906661.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.11 选择磁盘  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315014920357.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.12设置磁盘容量  
这个记住要选择**将虚拟磁盘存储为单个文件**  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315014935457.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.13指定磁盘文件  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315015055253.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.14创建虚拟机完成  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315015108642.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.15设置CD/DVD文件  
这个就是你之前下好的Ubuntu镜像文件  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315015208797.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.16开始安装 Ubuntu ，语言选择 中文(简体)， 然后 点击 安装Ubuntu![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315015306881.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.17 键盘布局默认，然后选择继续  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315015344394.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.18更新和其它软件选择默认  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315015405526.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.19 选择安装类型  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315015431497.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.20地区选择上海，默认  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315015445338.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.21设置用户名和密码  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315015457620.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.22 安装Ubuntu系统![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315015526915.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

2.23重启系统，完成安装  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315015538802.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

## 3.在ubuntu中安装c++

3.1在首页界面单击右键打开终端  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315020759730.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)  
3.2在终端输入sudo apt-get install g++  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315021435663.png#pic_center)  
3.3在终端输入 touch helloword.cpp  
用ls查看是否创建成功  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315023748686.png#pic_center)

3.4在终端输入“gedit helloword.cpp”,会弹出一个文本编辑器，选择c++语言编写完之后点击保存并关闭文件即可  
![在这里插入图片描述](https://img-blog.csdnimg.cn/2021031502390519.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FwcGxlXzU0MDc3OTg5,size_16,color_FFFFFF,t_70#pic_center)

3.5之后的话就要编译运行该helloword.cpp文件了，  
输入命令：g++ test.cpp -o tests  
./tests  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210315024537691.png#pic_center)  
**到这里，所有的大功告成了。**