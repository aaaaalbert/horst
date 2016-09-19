#include <sys/types.h>
#include <mach/clock.h>
#include <mach/mach.h>
#include <err.h>

#include "mach_clock_gettime.h"

int clock_gettime(clockid_t clock_id, struct timespec *tp) {
	clock_serv_t clock_name;
	mach_timespec_t current_time;
        kern_return_t retval;

	// Bail out early if we are asked to do things we cannot do
	if (clock_id != CLOCK_MONOTONIC)
		err(1, "Unsupported clock_id for mach_clock_gettime emulation");

	host_get_clock_service(mach_host_self(), SYSTEM_CLOCK, &clock_name);
	retval = clock_get_time(clock_name, &current_time);
	mach_port_deallocate(mach_task_self(), clock_name);
	tp->tv_sec = current_time.tv_sec;
	tp->tv_nsec = current_time.tv_nsec;

	return retval;
}

