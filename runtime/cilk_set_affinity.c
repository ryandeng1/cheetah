#define _GNU_SOURCE
#include "cilk2c.h"
#include "cilk-internal.h"
#include <cilk/cilk_set_affinity.h>
#include "debug.h"
#include "global.h"

#include <pthread.h>
#include <sched.h>
#include <stdio.h>

void set_worker_affinity(int num_workers, cpu_set_t* cpusets, pthread_t calling_thread) {
    global_state *g = __cilkrts_tls_worker->g;
    CILK_ASSERT(g->nworkers == num_workers);

    for (int w = 1; w < num_workers; w++) {
        int err = pthread_setaffinity_np(g->threads[w], sizeof(cpusets[w]),
                                         &cpusets[w]);
        CILK_ASSERT(err == 0);
    }

    int err = pthread_setaffinity_np(calling_thread, sizeof(cpusets[0]),
                                     &cpusets[0]);
    CILK_ASSERT(err == 0);
}

