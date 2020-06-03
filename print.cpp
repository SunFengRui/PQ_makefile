#include <stdio.h>
#include "workthread.h"
#include <unistd.h>

void *printFunc(void *arg)
{
    static int print_count=0;
    while(1)
    {
        if(packet_number)
        {
        printf("     %d     \n",print_count);
        printf("loss: %d\n",A_err_flag);
        printf("A_fre: %.5f\n",A_fre);
        printf("A_U_rms: %.5f\n",A_rms);
        printf("A_I_rms: %.5f\n",A_cur_rms);
        printf("A_jibofuzhi: %.5f\n",fuzhi_a[1]);
        printf("A_zhiliufenliang: %.5f\n",fuzhi_a[0]);
        printf("A_ercixiebo: %.5f\n",fuzhi_a[2]);
        printf("A_sancixiebo: %.5f\n",fuzhi_a[3]);

        printf("                \n");
        print_count++;
        packet_number=0;
        }
        sleep(1);

    }




}
