//============================================================================
// Name        : Assgn4.c
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Thread.h"
#include "Mutex.h"
#include <unistd.h>
#include "mysocket.h"
#include <pthread.h>
#include <stdio.h>
#include "threadpool.h"
#include "Testy.h"
#include "worker.h"
#include "scheduler.h"
#include "EPoll.h"
//#define DEBUG
int main() {
	pthread_t schedulerThread;
	epfd = epollCreate(100);
	struct threadpool *pool;
	if ((pool = threadpool_init(100)) == NULL ) {
		printf("Error! Failed to create a thread pool struct.\n");
		exit(EXIT_FAILURE);
	}
	int sockfd;
	int newsockfd, newschedule;
	sockfd = Create();
	int schedulerfd = Create();

	if (Bind(35000, sockfd) < 0) {
		printf("error in bind");
		exit(0);
	}
	if (Bind(35001, schedulerfd) < 0) {
		printf("error in bind");
		exit(0);
	}
	Listen(sockfd, 10);
	Listen(schedulerfd, 10);
	pthread_create(&schedulerThread, 0, (void*) &schedule, NULL);
	int i = 0;
	while (i < 100) {
		incClient();
		newsockfd = Accept(sockfd);

		if (numClient() <= 100) {
			Send(newsockfd, "ACCEPT", strlen("ACCEPT") + 1);
			newschedule = Accept(schedulerfd);
			fprintf(stderr, "Connection established with scheduler");
			sockets newsock;
			newsock.active = 1;
			newsock.priority = 1;
			newsock.schedulerSocket = newschedule;
			newsock.workerSocket = newsockfd;
			socketList = addToList(socketList, newsock);
#ifdef DEBUG
			if(socketList==NULL) {
				fprintf(stderr,"socketlist is null");
				exit(0);
			}
#endif
			epollAdd(epfd, newschedule);
			int ret = threadpool_add_task(pool, negotiator, (void*) &newsockfd,
					1);
		} else {
			Send(newsockfd, "REJECT", strlen("REJECT") + 1);
			close(newsockfd);
		}

		i++;

	}
	sleep(10);
	Close(sockfd);
	printf("shutting down");

	return 0;
}

