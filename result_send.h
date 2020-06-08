#ifndef RESULTSEND_H
#define RESULTSEND_H

#include <stdlib.h>  



typedef struct _measure_result_struct{
      char mac1[6];
      char mac2[6];
      short send_count;
      double  indicators_array_double[30];

}measure_result_struct;

typedef union _measuring_results_union
{
    measure_result_struct measure_result;
    u_char    indicators_array_char[240];
}measuring_results_union;

void *ResultSendThreadFunc(void *arg);

#endif // RESULTSEND_H
