# polkit-uos
在统信UOS非开发者模式或普通用户下，获取root权限，执行命令

#### 介绍
在UOS普通用户下实现root权限获取

#### 软件架构
软件架构说明
QT/C++

#### 安装教程

1.  apt-get install cmake g++ libpolkit-qt5-1-dev
2.  cd build & cmake ..
3.  make -j8
4. ./cpserver.sh
#### 使用说明

1.  在root下启动polkit-absurd-dream-server，若为安装包，则打包到deb安装包中并签名
2.  在普通用户下启动polkit-absurd-dream-client
3.  输入命令查询
