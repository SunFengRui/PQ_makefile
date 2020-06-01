
INCPATH       =  -I /usr/local/fftw-3.3.8/include/   \
                 -I /home/pi/SUN/TOOLS/libpcap-1.9.1/
LIBS          =  -L /usr/local/fftw-3.3.8/lib/ -lfftw3  \
                 -L /home/pi/SUN/TOOLS/libpcap-1.9.1 -lpcap  \
                 -lm -lpthread
OBJECTS       = main.o \
		net_init.o \
		data.o \
		dlist.o \
		socket_send.o \
		tool.o \
		V_Dip_Swell_Interrupt.o \
		workthread.o \
 		print.o

PQ_target: /usr/local/fftw-3.3.8/lib/libfftw3.a /home/pi/SUN/TOOLS/libpcap-1.9.1/libpcap.a $(OBJECTS)       
	gcc  -static -o $@ $(OBJECTS) $(LIBS) $(INCPATH)


net_init.o:net_init.cpp workthread.h /home/pi/SUN/TOOLS/libpcap-1.9.1/pcap.h
	gcc -c $(INCPATH) -o $@ $<  

workthread.o:workthread.cpp V_Dip_Swell_Interrupt.h main.h workthread.h tool.h dlist.h data.h /usr/local/fftw-3.3.8/include/fftw3.h
	gcc -c $(INCPATH) -o $@ $<    

socket_send.o:socket_send.cpp workthread.h main.h socket_send.h dlist.h
	gcc -c $(INCPATH) -o $@ $<
tool.o:tool.cpp
	gcc -c $(INCPATH) -o $@ $<
V_Dip_Swell_Interrupt.o:V_Dip_Swell_Interrupt.cpp workthread.h V_Dip_Swell_Interrupt.h
	gcc -c $(INCPATH) -o $@ $<
main.o:main.cpp main.h socket_send.h workthread.h net_init.h dlist.h
	gcc -c $(INCPATH) -o $@ $<
print.o:print.cpp
	gcc -c $(INCPATH) -o $@ $<
dlist.o:dlist.cpp 
	gcc -c $(INCPATH) -o $@ $<
data.o:data.cpp
	gcc -c $(INCPATH) -o $@ $<

clean:
	rm -rf PQ_target *.o