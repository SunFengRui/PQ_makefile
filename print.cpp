#include <stdio.h>
#include "workthread.h"
#include <unistd.h>

void *printFunc(void *arg)
{
    while(1)
    {
        printf("fre: %.5f\n",A_fre);
        sleep(1);

    }




}
