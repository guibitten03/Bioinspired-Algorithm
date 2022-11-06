#include "microseg.h"

long int microseg(){
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return current_time.tv_usec;
}
//./bioinsp lau15_dist.txt lau
//valgrind --track-origins=yes ./bioinsp lau15_dist.txt lau