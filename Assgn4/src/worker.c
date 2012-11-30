/*
 * worker.c
 *
 *  Created on: Nov 24, 2012
 *      Author: sameer
 */
#include "worker.h"
#include "mysocket.h"
#include "Testy.h"
#include "scheduler.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static int count = 0;
void negotiator(void * ptr) {
	int *new = (int*) ptr;
	int newsockfd = *new;
	int panning = 1;
	char fileName[256];
	char buff[256];
	int noOfBytes = 0;
	bzero(fileName, 256);
	linkedList *panList = searchWorker(socketList, newsockfd);
	while ((noOfBytes = Receive(newsockfd, fileName, sizeof(fileName))) > 0) {
		if (strcmp(fileName, "EXIT") == 0) {
			break;
		}

		//fileName[noOfBytes] = 0;
		fprintf(stderr, "\n%s\n", fileName);
		//pthread_mutex_lock(&mutex);
		unsigned int size = getSize(fileName);
		//pthread_mutex_unlock(&mutex);
		sprintf(buff, "%d", size);
		fprintf(stderr, "%d", size);
		if (doSend(panning) == 1) {
			Send(newsockfd, buff, strlen(buff));
			char* s = (char*) malloc(size * sizeof(char) + 1);
			//pthread_mutex_lock(&mutex);
			readFile(s, fileName);
			//pthread_mutex_unlock(&mutex);
			fprintf(stderr, "\n %ld \n", strlen(s));
			int i, j, temp;
			i = 0;
			j = strlen(s) - 1;
			while (i < j) {
				temp = s[i];
				s[i++] = s[j];
				s[j--] = temp;
			}
			Send(newsockfd, s, size);
			free(s);
			panning = panList->data.priority;
		}
		//send the file length as 0
		else{
			sprintf(buff, "%d", 0);
			Send(newsockfd, buff, strlen(buff));
			panning = panList->data.priority;
		}
	}
	Close(newsockfd);
}

//decide using the panning speed whether to send or not
int doSend(int panning) {
	srand(time(NULL));
	if(rand() % panning == 0)
		return 1;
	else
		return 0;
}

void incClient() {
	pthread_mutex_lock(&mutex);
	count++;
	pthread_mutex_unlock(&mutex);
}

void decClient() {
	pthread_mutex_lock(&mutex);
	count++;
	pthread_mutex_unlock(&mutex);
}
int numClient() {
	pthread_mutex_lock(&mutex);
	int tempCount = count;
	pthread_mutex_unlock(&mutex);
	return tempCount;
}
