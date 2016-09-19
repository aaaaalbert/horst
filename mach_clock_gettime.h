/*
 * mach_clock_gettime --- an emulation of POSIX's `clock_gettime` for 
 * Mach / Mac OS X.
 *
 * This little library is based on material by
 * - The Open Group, see 
 *     http://pubs.opengroup.org/onlinepubs/9699919799/functions/clock_gettime.html
 * - the Linux kernel headers, see posix_types.h and types.h
 * - https://stackoverflow.com/questions/11680461/monotonic-clock-on-osx
 */

#ifndef _MACH_CLOCK_GETTIME_
#define _MACH_CLOCK_GETTIME_

#include<time.h>

#define CLOCK_MONOTONIC 1
typedef int clockid_t;

int clock_gettime(clockid_t clock_id, struct timespec *tp);

#endif
