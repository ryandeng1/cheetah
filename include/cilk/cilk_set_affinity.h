#ifndef _CILK_SET_AFFINITY_H
#define _CILK_SET_AFFINITY_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <assert.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <errno.h>
#include <pthread.h>
#include <sched.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

void set_worker_affinity(int num_workers, cpu_set_t* cpusets, pthread_t calling_thread);

#ifdef __cplusplus
}
#endif
#endif // CILK_C11_H
