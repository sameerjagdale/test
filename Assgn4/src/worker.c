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

	char* s = (char*) malloc(size * sizeof(char)+1);
	readFile(s,source);
	int i,j,temp;
	 i=0;
	j=strlen(s) - 1;
	while(i < j) {
	temp = s[i];
	s[i++] = s[j];
	s[j--] = temp;
	}
	Send(newsockfd, buff, strlen(buff));
	Send(newsockfd, s, size);
	free(s);
	Close(newsockfd);
}
