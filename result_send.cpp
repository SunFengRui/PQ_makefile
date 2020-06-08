#include "result_send.h"
#include  <pcap.h>
#include "main.h"
#include <unistd.h>      //sleep
#include "workthread.h"

measuring_results_union measuring_results;
void indicators2union(void)
{
    measuring_results.measure_result.indicators_array_double[0]  = A_fre;//
    measuring_results.measure_result.indicators_array_double[1]  = A_rms;//
    measuring_results.measure_result.indicators_array_double[2]  = A_cur_rms;//
    measuring_results.measure_result.indicators_array_double[3]  = A_active_power;//
    measuring_results.measure_result.indicators_array_double[4]  = A_reactive_power;//
    measuring_results.measure_result.indicators_array_double[5]  = A_apparent_power;//
    measuring_results.measure_result.indicators_array_double[6]  = A_fre;//
    measuring_results.measure_result.indicators_array_double[7]  = A_rms;//
    measuring_results.measure_result.indicators_array_double[8]  = A_cur_rms;//
    measuring_results.measure_result.indicators_array_double[9]  = A_active_power;//
    measuring_results.measure_result.indicators_array_double[10] = A_reactive_power;//
    measuring_results.measure_result.indicators_array_double[11] = A_apparent_power;//
    measuring_results.measure_result.indicators_array_double[12] = A_cur_rms;//
    measuring_results.measure_result.indicators_array_double[13] = A_active_power;//
    measuring_results.measure_result.indicators_array_double[14] = A_reactive_power;//
    measuring_results.measure_result.indicators_array_double[15] = A_apparent_power;//
    measuring_results.measure_result.indicators_array_double[16] = A_fre;//
    measuring_results.measure_result.indicators_array_double[17] = A_rms;//
    measuring_results.measure_result.indicators_array_double[18] = A_cur_rms;//
    measuring_results.measure_result.indicators_array_double[19] = A_active_power;//
    measuring_results.measure_result.indicators_array_double[20] = A_reactive_power;//
    measuring_results.measure_result.indicators_array_double[21] = A_rms;//
    measuring_results.measure_result.indicators_array_double[22] = A_cur_rms;//
    measuring_results.measure_result.indicators_array_double[23] = A_active_power;//
    measuring_results.measure_result.indicators_array_double[24] = A_reactive_power;//
    measuring_results.measure_result.indicators_array_double[25] = A_apparent_power;//
    measuring_results.measure_result.indicators_array_double[26] = A_fre;//
    measuring_results.measure_result.indicators_array_double[27] = A_rms;//
    measuring_results.measure_result.indicators_array_double[28] = A_cur_rms;//
    measuring_results.measure_result.indicators_array_double[29] = A_active_power;//
}

void *ResultSendThreadFunc(void *arg)
{
       sleep(3);
        char errBuf[PCAP_ERRBUF_SIZE];
        pcap_t * device;
         device= pcap_open_live("eth0", 65535, 1, 0, errBuf);
           if(!device)
           {
             printf("error: pcap_open_live(): %s\n", errBuf);
             exit(1);
           }
          u_char packet[100];
            /* Supposing to be on ethernet, set mac destination to 1:1:1:1:1:1 */
                measuring_results.measure_result.mac1[0]=1;
                measuring_results.measure_result.mac1[1]=1;
                measuring_results.measure_result.mac1[2]=1;
                measuring_results.measure_result.mac1[3]=1;
                measuring_results.measure_result.mac1[4]=1;
                measuring_results.measure_result.mac1[5]=1;
                /* set mac source to 2:2:2:2:2:2 */
                measuring_results.measure_result.mac2[0]=2;
                measuring_results.measure_result.mac2[1]=2;
                measuring_results.measure_result.mac2[2]=2;
                measuring_results.measure_result.mac2[3]=2;
                measuring_results.measure_result.mac2[4]=2;
                measuring_results.measure_result.mac2[5]=2; 
                measuring_results.measure_result.send_count=0;

    while(1)
    {
                measuring_results.measure_result.send_count++;
                indicators2union();
                pcap_sendpacket(device,measuring_results.indicators_array_char, sizeof(measuring_results));
                sleep(1);

    }

}
