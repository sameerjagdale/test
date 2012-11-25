#ifndef THREADPOOL_H_
#define THREADPOOL_H_

struct threadpool;

struct threadpool* threadpool_init(int num_of_threads);


int threadpool_add_task(struct threadpool *pool, void (*routine)(void*), void *data, int blocking);


void threadpool_free(struct threadpool *pool, int blocking);

#endif
