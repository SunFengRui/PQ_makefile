#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include "net_init.h"
#include "workthread.h"
#include "result_send.h"
#include "main.h"
#include <signal.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

struct tm *Start_time;
time_t start_time;
char start_time_s[200];
int threadsum = 0;
pthread_mutex_t fft_mutex;    //
pthread_mutex_t half_mutex; 
static pthread_t handlePcap;
static pthread_t handleFFT_Thread, handleA_FlickerThread, handleA_HalfPeriodThread;
static pthread_t handleB_FlickerThread, handleB_HalfPeriodThread;
static pthread_t handleC_FlickerThread, handleC_HalfPeriodThread;
static pthread_t handle_CheckThread,handleResultSendThread;
static pthread_t printThread;
sem_t FFT_semaphore,A_halfcalc_semaphore,A_flicker_semaphore;
sem_t B_halfcalc_semaphore,B_flicker_semaphore;
sem_t C_halfcalc_semaphore,C_flicker_semaphore;
sem_t data_send_sem;
long cpu_num;
FILE *fp;

void init()
{
    fp=fopen("/home/pi/PQ.txt","w+");

    cpu_num=sysconf(_SC_NPROCESSORS_ONLN);

    time(&start_time);
    Start_time = localtime(&start_time);
    //sprintf(start_time_s, "%2d年%2d月%2d日 %2d时:%2d分:%2d秒\n", Start_time->tm_year + 1900, Start_time->tm_mon + 1, Start_time->tm_mday,  \
    Start_time->tm_hour, Start_time->tm_min, Start_time->tm_sec);  //年月日时分秒

    //10s执行第一次，60s循环执行
    struct itimerval timer;
    memset(&timer,0,sizeof(timer));
    signal(SIGALRM,OneMinuteTimerCallbackFunc);
    timer.it_value.tv_sec=10;
    timer.it_value.tv_usec=0;
    timer.it_interval.tv_sec=60;
    timer.it_interval.tv_usec=0;
    setitimer(ITIMER_REAL,&timer,NULL);   //ITIMER_REAL SIGALRM

}
void os_create(void)
{
    pthread_mutex_init(&fft_mutex, NULL);
    sem_init (&FFT_semaphore , 0, 0);

    sem_init (&A_halfcalc_semaphore , 0, 0);

    sem_init (&data_send_sem , 0, 0);

    pthread_create(&handlePcap,NULL,PcapThreadFunc,NULL);
    threadsum++;

    pthread_create(&handleFFT_Thread,NULL,FFT_ThreadFunc, NULL);
    threadsum++;

    pthread_create(&handleA_HalfPeriodThread,NULL,A_HalfThreadFunc, NULL);
    threadsum++;
    pthread_create(&handleB_HalfPeriodThread,NULL,B_HalfThreadFunc, NULL);
    threadsum++;
    pthread_create(&handleC_HalfPeriodThread,NULL,C_HalfThreadFunc, NULL);
    threadsum++;
    pthread_create(&handleA_FlickerThread,NULL,A_FlickerThreadFunc, NULL);
    threadsum++;
    pthread_create(&handleB_FlickerThread,NULL,B_FlickerThreadFunc, NULL);
    threadsum++;
    pthread_create(&handleC_FlickerThread,NULL,C_FlickerThreadFunc, NULL);
    threadsum++;
    pthread_create(&handle_CheckThread,NULL,CheckThreadFunc, NULL);
    threadsum++;
    pthread_create(&handleResultSendThread,NULL,ResultSendThreadFunc, NULL);
    threadsum++;
    pthread_create(&printThread,NULL,printFunc, NULL);
    threadsum++;
}
DList *list_f;
void create_list(int len, double init_val)
{
    list_f = CreateList();
        for(int i=0;i<len;i++)
            InsertList(list_f, init_val);
}
void distroy_list()
{
    DelList(list_f);
}
int main(int argc, char *argv[])
{

    init();

    os_create();

    create_list(10,50.0);

while(1)
{
}

    return 0;
}
