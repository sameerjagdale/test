/*
 * example.c
 *
 *  Created on: Dec 25, 2010
 *      Author: Tomer Heber (heber.tomer@gmail.com).
 */

#include "threadpool.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ARR_SIZE 100
/*
static pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
static int count;

void computeSum(void *ptr)
{
	int *pval = (int*)ptr;

	printf("%d + %d = %d.\n",*pval, *pval +1, *pval + *pval + 1);

}

int main(int argc, char **argv)
{
	struct threadpool *pool;
	int arr[ARR_SIZE], i, ret, failed_count = 0;

	for (i = 0; i < ARR_SIZE; i++) {
		arr[i] = i;
	}


	if ((pool = threadpool_init(10)) == NULL) {
		printf("Error! Failed to create a thread pool struct.\n");
		exit(EXIT_FAILURE);
	}
	i=0;
	while(1){
	for (i=0; i < ARR_SIZE; i++) {


			ret = threadpool_add_task(pool,computeSum,arr + i,1);


		if (ret == -1) {
			printf("An error had occurred while adding a task.");
			exit(EXIT_FAILURE);
		}

		if (ret == -2) {
			failed_count++;
		}
	}
	}
		threadpool_free(pool,1);

	printf("Example ended.\n");
	printf("%d tasks out of %d have been executed.\n",count,ARR_SIZE);
	printf("%d tasks out of %d did not execute since the pool was overloaded.\n",failed_count,ARR_SIZE);
	printf("All other tasks had not executed yet.");

	return 0;
}
*/
