#include "timer.h"

double frame (double * timer) {
    struct timeval tp;
    double diff, current;
    gettimeofday(&tp, NULL);

    current = (tp.tv_sec * 1e6 + tp.tv_usec) / (float)1000000;
    if (*timer == 0) {
        memcpy(timer, &current, sizeof(double));
        return current; 
    }

    diff = current - *timer;
    memcpy(timer, &current, sizeof(double));

    return diff;
}
