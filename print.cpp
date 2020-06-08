#include <stdio.h>
#include "workthread.h"
#include <unistd.h>
#include "main.h"
#include <time.h>


static time_t real_time;
static long totaltime;
static char total_time[100];
static int day, hour, minute, sec;

void *printFunc(void *arg)
{
    static int print_count=0;
    while(1)
    {
        time(&real_time);
        totaltime = (real_time - start_time);

        day = totaltime / (60 * 60 * 24);
        totaltime = totaltime % (60 * 60 * 24);
        hour = totaltime / (60 * 60);
        totaltime = totaltime % (60 * 60);
        minute = totaltime / 60;
        totaltime = totaltime % 60;
        sec = totaltime;
        printf("            ****** %2d day %2d hour %2d min %2d sec******\n", day, hour, minute, sec);//年月日时分秒
      
        if(packet_number)
        {

        printf("loss: %d\n",A_err_flag);
        printf("A_fre: %.5f\n",A_fre);
        printf("A_U_rms: %.5f\n",A_rms);
        printf("A_I_rms: %.5f\n",A_cur_rms);
        printf("A_U_jibofuzhi: %.5f\n",fuzhi_a[1]);
        printf("A_I_jibofuzhi: %.5f\n",fuzhi_a_cur[1]);
        printf("U_I phase diff:%.5f\n",fftw_phase_differ[1]/ PI * 180);
        printf("A_zhiliufenliang: %.5f\n",fuzhi_a[0]);
        printf("A_ercixiebo: %.5f\n",fuzhi_a[2]);
        printf("A_sancixiebo: %.5f\n",fuzhi_a[3]);

        printf("A voltage swell dip interrupt :%d %d %d\n",A_voltageswellstartflag,A_voltagedipstartflag,A_voltageinterruptstartflag);
        printf("B voltage swell dip interrupt :%d %d %d\n",B_voltageswellstartflag,B_voltagedipstartflag,B_voltageinterruptstartflag);
        printf("C voltage swell dip interrupt :%d %d %d\n",C_voltageswellstartflag,C_voltagedipstartflag,C_voltageinterruptstartflag);

        printf("                \n");
        print_count++;
        packet_number=0;
           
        }
        else
        {
            printf("no data receive\n");
        }
        sleep(1);

    }




}
