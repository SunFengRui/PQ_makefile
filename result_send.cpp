#include "result_send.h"
#include  <pcap.h>
#include "main.h"
#include <unistd.h>      //sleep



void *ResultSendThreadFunc(void *arg)
{
     char errBuf[PCAP_ERRBUF_SIZE];
        pcap_t * device = pcap_open_live("eth0", 65535, 1, 0, errBuf);
          if(!device)
          {
            printf("error: pcap_open_live(): %s\n", errBuf);
            exit(1);
          }
          u_char packet[100];
            /* Supposing to be on ethernet, set mac destination to 1:1:1:1:1:1 */
                packet[0]=1;
                packet[1]=1;
                packet[2]=1;
                packet[3]=1;
                packet[4]=1;
                packet[5]=1;
                /* set mac source to 2:2:2:2:2:2 */
                packet[6]=2;
                packet[7]=2;
                packet[8]=2;
                packet[9]=2;
                packet[10]=2;
                packet[11]=2;
                for(int i=12;i<100;i++)
                    packet[i]=i%256;       

    while(1)
    {
                pcap_sendpacket(device, packet, 100);
                sleep(1);

    }

}
