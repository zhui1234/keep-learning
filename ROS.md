# ROS

## ROS的安装

### 基本流程

> 参考教程:[ROS安装教程](https://blog.csdn.net/In_moon_shadow/article/details/153737498)

### 问题

#### 1. `rosdep update`超时

+ 方案1 资源代理(失败)
  使用ghproxy代理加速对Github的访问,修改了rep3.py和__init__.py中的URL,以及20-default.list,但显示网络连接有问题.
  于是尝试使用国内镜像源,先后尝试了清华源和中科大源.但清华源显示清华镜像中index.yaml文件和index-v4文件不存在;中科大源则是直接404.

+ 方案2 手动下载+本地文件(成功)
