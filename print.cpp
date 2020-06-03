#include <stdio.h>
#include "workthread.h"
#include <unistd.h>

void *printFunc(void *arg)
{
    static int print_count=0;
    while(1)
    {
        printf("     %d     \n",print_count);
        printf("fre: %.5f\n",A_fre);
        printf("loss: %d\n",A_fre);
        printf("                \n")
        print_count++;
        sleep(1);

    }




}
