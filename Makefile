#  
#  Project: Power Quality am335xt3
#  compile: arm-arago-linux-gnueabi-gcc   gcc
#  Makefile written by Sun Fengrui
#  -lnl -lnl-genl

TARGET        =  PQ_target
CC            =  arm-arago-linux-gnueabi-gcc
LIBPCAPPATH   =  /usr/local/ARM_lib/libpcap-1.9.1
LIBFFTWPATH   =  /usr/local/ARM_lib/fftw-3.3.8
LIBNLPATH     =  /usr/local/ARM_lib/libnl-3.0

INCPATH       =  -I $(LIBFFTWPATH)/include/   \
                 -I $(LIBPCAPPATH)/include/
LIBS          =  -L $(LIBFFTWPATH)/lib/ -lfftw3  \
                 -L $(LIBPCAPPATH)/lib/ -lpcap  \
		 -L $(LIBNLPATH)/lib/ -lnl -lnl-genl  \
                 -lm -lpthread 
OBJECTS       =  main.o \
		 net_init.o \
		 data.o \
		 dlist.o \
		 socket_send.o \
		 tool.o \
		 V_Dip_Swell_Interrupt.o \
		 workthread.o \
 		 print.o


$(TARGET): $(LIBFFTWPATH)/lib/libfftw3.a $(LIBPCAPPATH)/lib/libpcap.a $(OBJECTS)       
	$(CC)  -static -o $@ $(OBJECTS) $(LIBS) $(INCPATH)



net_init.o:net_init.cpp workthread.h $(LIBPCAPPATH)/include/pcap.h
	$(CC) -c $(INCPATH) -o $@ $<  
workthread.o:workthread.cpp V_Dip_Swell_Interrupt.h main.h workthread.h tool.h dlist.h data.h $(LIBFFTWPATH)/include/fftw3.h
	$(CC) -c $(INCPATH) -o $@ $<    
socket_send.o:socket_send.cpp workthread.h main.h socket_send.h dlist.h
	$(CC) -c $(INCPATH) -o $@ $<
tool.o:tool.cpp
	$(CC) -c $(INCPATH) -o $@ $<
V_Dip_Swell_Interrupt.o:V_Dip_Swell_Interrupt.cpp workthread.h V_Dip_Swell_Interrupt.h
	$(CC) -c $(INCPATH) -o $@ $<
main.o:main.cpp main.h socket_send.h workthread.h net_init.h dlist.h
	$(CC) -c $(INCPATH) -o $@ $<
print.o:print.cpp
	$(CC) -c $(INCPATH) -o $@ $<
dlist.o:dlist.cpp 
	$(CC) -c $(INCPATH) -o $@ $<
data.o:data.cpp
	$(CC) -c $(INCPATH) -o $@ $<

clean:
	rm -rf $(TARGET) *.o
