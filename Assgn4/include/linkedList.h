#include "mysocket.h"

typedef struct _sockets {
	int schedulerSocket, workerSocket;
	int priority, active;
} sockets;

typedef struct _linkedList {
	sockets data;
	struct _linkedList *next;
} linkedList;

extern linkedList *socketList;

linkedList * addToList(linkedList *, sockets newsock);
linkedList * removeFromList(linkedList*, sockets data);
int contains(linkedList *, sockets data);
linkedList* searchWorker(linkedList *, int workerFd);
linkedList* searchScheduler(linkedList *, int schedulerfd);

