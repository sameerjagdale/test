/*
 * linkedList.h
 *
 *  Created on: Nov 27, 2012
 *      Author: sameer
 */
//#include "scheduler.h"
#include "mysocket.h"

typedef struct _sockets {
	int schedulerSocket, workerSocket;
	int priority, active;
} sockets;
typedef struct _linkedList {
	sockets data;
	struct _linkedList *next;
} linkedList;

linkedList * addToList(linkedList *, sockets newsock);
linkedList * removeFromList(linkedList*, sockets data);
int contains(linkedList *, sockets data);
linkedList* searchWorker(linkedList *, int workerFd);
linkedList* searchScheduler(linkedList *, int schedulerfd);

