# server_Reactor


此项目是一个轻量级的基于`Reactor`模式的Linux/C++服务器框架，一共分为 `8` 个模块：

* 内存池模块
* TCP链接模块
* 事件触发`EventLoop`模块
* 消息路由模块
* 消息队列和线程池模块
* 配置文件读写模块
* TCP/UDP客户端模块
* QPS测试模块

用户可以根据主机配置以及使用场景，对配置文件进行修改，其中涉及了服务器的核心属性：<font color=red>**线程池中线程个数、IP地址和端口号、最大连接数等。**</font>


<br/>
<br/>

# 编译生成

执行make之前，确保protobuf环境已经安装成功，按照下面顺序操作：
* 如果想测试服务器性能，先进入example/qps_test目录下执行build.sh
* 执行make


# 性能测试

客户端是开启一个线程进行测试，平均每秒服务端会响应8700次左右。
```cpp
$ ./client 1
msg_router init...
do_connect EINPROGRESS
add msg cb msgid = 1
connect 127.0.0.1:7777 succ!
---> qps = 6875 <----
---> qps = 8890 <----
---> qps = 8354 <----
---> qps = 9078 <----
---> qps = 8933 <----
---> qps = 9043 <----
---> qps = 8743 <----
---> qps = 9048 <----
---> qps = 8987 <----
---> qps = 8742 <----
---> qps = 8720 <----
---> qps = 8795 <----
---> qps = 8889 <----
---> qps = 9034 <----
---> qps = 8669 <----
---> qps = 9001 <----
---> qps = 8810 <----
---> qps = 8850 <----
---> qps = 8802 <----
---> qps = 9072 <----
---> qps = 8853 <----
---> qps = 8804 <----
---> qps = 8574 <----
---> qps = 8645 <----
---> qps = 8085 <----
---> qps = 8720 <----
...

```

用两个主机，分别测试了一些数据：

主机1：
> CPU个数：2个 ， 内存: 2GB , 系统：Ubuntu18.04虚拟机

| 线程数 | QPS | 
| ------ | ------ | 
| 1 | 0.85w/s | 
| 2 | 1.96w/s | 
| 10 | 4.12w/s | 
| 100 | 4.23w/s | 
| 500 | 3.65w/s | 

<br/>
<br/>

主机2：
> CPU个数：24个 ， 内存: 128GB , 系统：云主机

| 线程数 | QPS | 
| ------ | ------ | 
| 1 | 10.86w/s | 
| 3 | 31.06w/s | 
| 5 | 48.12w/s | 
| 8 | 59.79w/s | 



