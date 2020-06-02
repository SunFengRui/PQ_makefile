#  
#  Project: Power Quality am335xt3
#  compile: arm-arago-linux-gnueabi-gcc   gcc
#  Makefile written by Sun Fengrui
#  -lnl -lnl-genl

CC            =  gcc
LIBPCAPPATH   =  /home/sun/SUN/PF_test/libpcap-1.9.1
LIBFFTWPATH   =  /usr/local/fftw-3.3.8

INCPATH       =  -I $(LIBFFTWPATH)/include/   \
                 -I $(LIBPCAPPATH)
LIBS          =  -L $(LIBFFTWPATH)/lib/ -lfftw3  \
                 -L $(LIBPCAPPATH) -lpcap  \
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


PQ_target: $(LIBFFTWPATH)/lib/libfftw3.a $(LIBPCAPPATH)/libpcap.a $(OBJECTS)       
	$(CC)  -static -o $@ $(OBJECTS) $(LIBS) $(INCPATH)



net_init.o:net_init.cpp workthread.h $(LIBPCAPPATH)/pcap.h
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
	rm -rf PQ_target *.o
