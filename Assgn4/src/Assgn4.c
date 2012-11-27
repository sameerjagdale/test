//============================================================================
// Name        : Assgn4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Thread.h"
#include "Mutex.h"
#include <unistd.h>
#include "mysocket.h"
#include <stdio.h>
#include "threadpool.h"
#include "Testy.h"
#include "worker.h"

int main() {

	struct threadpool *pool;
	if ((pool = threadpool_init(100)) == NULL ) {
		printf("Error! Failed to create a thread pool struct.\n");
		exit(EXIT_FAILURE);
	}
	int sockfd;
	sockfd = Create();

	if (Bind(35000, sockfd) < 0) {
		printf("error in bind");
		exit(0);
	}
	Listen(sockfd, 10);
	int i=0;
	while (i<100) {
	int newsockfd = Accept(sockfd);
	int ret = threadpool_add_task(pool, negotiator, (void*) &newsockfd, 1);
	i++;

	}
	sleep(10);
	Close(sockfd);
	printf("shutting down");

	return 0;
}

