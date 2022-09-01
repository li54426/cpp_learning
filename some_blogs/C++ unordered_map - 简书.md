## C++ unordered\_map

[![](https://cdn2.jianshu.io/assets/default_avatar/6-fd30f34c8641f6f32f5494df5d6b8f3c.jpg)](https://www.jianshu.com/u/581759327d44)

0.0822018.04.20 11:14:43字数 1,178阅读 32,339

## hash\_map ≈ unordered\_map

最初的 C++ 标准库中没有类似 hash\_map 的实现，但不同实现者自己提供了非标准的 hash\_map。 因为这些实现不是遵循标准编写的，所以它们在功能和性能保证方面都有细微差别。

从 C++ 11 开始，hash\_map 实现已被添加到标准库中。但为了防止与已开发的代码存在冲突，决定使用替代名称 unordered\_map。这个名字其实更具描述性，因为它暗示了该类元素的无序性。

## unordered\_map 原理

**hashtable + bucket**  
由于 unordered\_map 内部采用 hashtable 的数据结构存储，所以，每个特定的 key 会通过一些特定的哈希运算映射到一个特定的位置，我们知道，hashtable 是可能存在冲突的，在同一个位置的元素会按顺序链在后面。所以把这个位置称为一个 bucket 是十分形象的，每个哈希桶中可能没有元素，也可能有多个元素。

![](https://upload-images.jianshu.io/upload_images/5418798-bcc2dc27c141255b.png?imageMogr2/auto-orient/strip|imageView2/2/w/670/format/webp)

其插入过程是：  
1、得到 key；  
2、通过 hash 函数得到 hash 值；  
3、得到桶号（一般都为 hash 值对桶数求模）；  
4、存放 key 和 value 在桶内（发生冲突，用比较函数解决）。

其取值过程是：  
1、得到 key  
2、通过 hash 函数得到 hash 值  
3、得到桶号（一般都为 hash 值对桶数求模）  
4、比较桶的内部元素是否与 key 相等，若都不相等，则没有找到。  
5、取出相等的记录的 value。

总结其特点如下：

-   关联性：通过 key 去检索 value，而不是通过绝对地址（和顺序容器不同）
-   无序性：使用 hash 表存储，内部无序
-   Map : 每个值对应一个键值_（unordered\_map<Key, Value> 的元素类型是 std::pair<const Key, Value>。如果有某个元素的Value部分的地址，减去 offsetof(std::pair<const Key, Value>, second) 再加上 offsetof(std::pair<const Key, Value>, first) （虽然估计是 0，不加也没事），就是对应的 Key 部分的地址）_
-   键唯一性：不存在两个元素的 key 一样_（unordered\_multimap 可以存放相同相同 key）_
-   动态内存管理：使用内存管理模型来动态管理所需要的内存空间

## unordered\_map 实现

unordered\_map 类的定义：

```
// 通常只用得到前两个 <Key, Ty>
template <class Key,  
          class Ty,  
          class Hash = std::hash<Key>,  
          class Pred = std::equal_to<Key>,  
          class Alloc = std::allocator<std::pair<const Key, Ty>>>
class unordered_map;
```

| 参数 | 描述 |
| --- | --- |
| Key | 密钥类 |
| Ty | 映射类 |
| Hash | 哈希函数对象类 |
| Pred | 相等比较函数对象类 |
| Alloc | allocator 类 |

## unordered\_map 使用

头文件：

取得键和值：

```
unordered_map<Key,T>::iterator it;
it->first;               // same as (*it).first   (the key value)
it->second;              // same as (*it).second  (the mapped value) 
```

成员函数：  
\===================迭代器====================  
begin | 返回指向容器起始位置的迭代器（iterator）  
end | 返回指向容器末尾位置的迭代器  
cbegin | 返回指向容器起始位置的常迭代器（const\_iterator）  
cend | 返回指向容器末尾位置的常迭代器  
\===================Capacity===================  
size 返回有效元素个数  
max\_size 返回 unordered\_map 支持的最大元素个数  
empty 判断是否为空  
\===================元素访问===================  
operator\[\] 访问元素  
at 访问元素（如 m.at(5) = 3.33）  
\===================元素修改===================  
insert 插入元素  
erase 删除元素  
swap 交换内容  
clear 清空内容  
emplace 构造及插入一个元素  
emplace\_hint 按提示构造及插入一个元素  
\=====================操作=====================  
find 通过给定主键查找元素  
count 返回匹配给定主键的元素的个数  
equal\_range 返回值匹配给定搜索值的元素组成的范围  
\===================Buckets====================  
bucket\_count 返回槽（Bucket）数  
max\_bucket\_count 返回最大槽数  
bucket\_size 返回槽大小  
bucket 返回元素所在槽的序号  
load\_factor 返回载入因子，即一个元素槽（Bucket）的最大元素数  
max\_load\_factor 返回或设置最大载入因子  
rehash 设置槽数  
reserve 请求改变容器容量

更多精彩内容，就在简书APP

"小礼物走一走，来简书关注我"

还没有人赞赏，支持一下

[![  ](https://cdn2.jianshu.io/assets/default_avatar/6-fd30f34c8641f6f32f5494df5d6b8f3c.jpg)](https://www.jianshu.com/u/581759327d44)

总资产41共写了12.0W字获得208个赞共71个粉丝

### 被以下专题收入，发现更多相似内容

### 推荐阅读[更多精彩内容](https://www.jianshu.com/)

-   1.HashMap是一个数组＋链表/红黑树的结构，数组的下标在HashMap中称为Bucket值，每个数组项对应的...
    
    [![](https://upload-images.jianshu.io/upload_images/3145530-edad24701148a590.png?imageMogr2/auto-orient/strip|imageView2/1/w/300/h/240/format/webp)](https://www.jianshu.com/p/719d708ca1af)
-   [![](https://cdn2.jianshu.io/assets/default_avatar/3-9a2bcc21a5d89e21dafc73b39dc5f582.jpg)核桃啊](https://www.jianshu.com/u/e706f0b931b2)阅读 3,541评论 0赞 5
    

-   Map 是一种很常见的数据结构，用于存储一些无序的键值对。在主流的编程语言中，默认就自带它的实现。C、C++ 中的...
    
    [![](https://upload-images.jianshu.io/upload_images/1194012-b0b43d09c63546a7.png?imageMogr2/auto-orient/strip|imageView2/1/w/300/h/240/format/webp)](https://www.jianshu.com/p/cd41ca8741f4)
-   徐志摩说“一生至少该有一次，为了某个人而忘了自己，不求有结果 ，不求同行，不求曾经拥有，甚至不求你爱我，只求在我最...
    
    [![](https://upload-images.jianshu.io/upload_images/7041913-3e36175be0b2f279.jpg?imageMogr2/auto-orient/strip|imageView2/1/w/300/h/240/format/webp)](https://www.jianshu.com/p/a86e0b040277)
-   08107-张珊 第三天，看《绘本之力》说到 孩子·死亡·绘本，绘本是可以很孩子沟通的一种方式，一个故事，小朋友们...
    
    [![](https://upload-images.jianshu.io/upload_images/11383035-88004a5aa1eb8a9c.jpg?imageMogr2/auto-orient/strip|imageView2/1/w/300/h/240/format/webp)](https://www.jianshu.com/p/791a76bd8efd)
-   爱情是两个人的事，思念自然也是两个人的事。然而当两颗心被同一个爱情联系在一起，思念也就变成...
    
    [![](https://cdn2.jianshu.io/assets/default_avatar/8-a356878e44b45ab268a3b0bbaaadeeb7.jpg)冰夫](https://www.jianshu.com/u/e73219532b8d)阅读 128评论 0赞 0
    
-   2018年1月9日星期二 天气：晴 下班回到家，女儿突然跑过来告诉我，哥哥哭了。我跑到书房，看到儿子眼圈红红的，肿...
    
    [![](https://upload.jianshu.io/users/upload_avatars/9276674/30dbd085-c96e-48a1-a9fa-31ef32578503.jpg?imageMogr2/auto-orient/strip|imageView2/1/w/48/h/48/format/webp)唐丽娟](https://www.jianshu.com/u/02540127dd17)阅读 91评论 0赞 0