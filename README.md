# PQ_makefile
合并单元+am3352(树莓派)    无开发环境    makefile编译


  宿主机+am3352目标机开发  交叉编译  工具：municom filezilla

宿主机环境配置
1.编译器 am335x_gcc_tool_4.5.tar.gz
   tar zxvf am335x_gcc_tool_4.5.tar.gz 解压
   vim ~/.bashrc   添加 export PATH=$PATH:/usr/local/arm/cross/am335xt3/devkit/bin(编译器路径)
   source ~/.bashrc
   sudo vim /etc/profile  添加 export PATH=$PATH:/usr/local/arm/cross/am335xt3/devkit/bin(编译器路径)
   source /etc/profile
2.FFTW库 fftw-3.3.8.tar.gz
   tar zxvf fftw-3.3.8.tar.gz
   cd fftw-3.3.8
   ./configure --host=arm-arago-linux-gnueabi --prefix=/home/sun/SUN/tool/fftw-3.3.8 检查makefile编译器是否为相应目标及编译器(非常重要)
   make
   sudo make install
3.libpcap库 libpcap-1.9.1.tar.gz
   tar zxvf libpcap-1.9.1.tar.gz
   cd libpcap-1.9.1
   ./configure --host=arm-arago-linux-gnueabi --prefix=/home/sun/SUN/tool/libpcap-1.9.1 检查makefile编译器是否为相应目标及编译器(非常重要)
   make
   sudo make install
4.libnl库 libnl-3.0
   tar zxvf libnl-3.0
   cd fftw-3.3.8
   ./configure --host=arm-arago-linux-gnueabi --prefix=/home/sun/SUN/tool/libnl-3.0 检查makefile编译器是否为相应目标及编译器(非常重要)
   make
   sudo make install
程序编译：
   cd PQ_makefile
   make                               
   arm-arago-linux-gnueabi-strip PQ_target
      
   
   
