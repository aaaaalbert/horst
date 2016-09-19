#include <stdio.h>
#include <time.h>

#include "mach_clock_gettime.h"

int main() {
  struct timespec *ts;
  clock_gettime(CLOCK_MONOTONIC, ts);
  printf("%s", ctime(&ts->tv_sec));
  return 0;
}
