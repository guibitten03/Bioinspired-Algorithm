#include "microseg.h"

long int microseg(){
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return current_time.tv_usec;
}
