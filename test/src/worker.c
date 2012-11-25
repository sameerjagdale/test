/*
 * worker.c
 *
 *  Created on: Nov 24, 2012
 *      Author: sameer
 */
#include "worker.h"
#include "mysocket.h"
#include "Testy.h"

void negotiator(void * ptr) {
	int *new = (int*) ptr;
	int newsockfd = *new;
	char* source = "./pic.jpg";

	char buff[256];

	unsigned int size = getSize(source);
	sprintf(buff, "%d", size);
	fprintf(stderr, "%d", size);
	char buff1[] = "sameer";
	char* s = (char*) malloc(size * sizeof(char));
	sprintf(buff, "%ld", sizeof(buff1));

	Send(newsockfd, buff, sizeof(buff));


	fprintf(stderr, "\n  size of size %ld ", sizeof(size));
	fprintf(stderr, "size of sameer %d", atoi(buff));
	//readFile(s, source);

	fprintf(stderr, "\n%s", buff1);
	fprintf(stderr, "\n size of buffer   %ld", sizeof(buff1));

	Send(newsockfd, buff1, atoi(buff));

	free(s);
	Close(newsockfd);
}

