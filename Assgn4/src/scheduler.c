#include "scheduler.h"
//#define DEBUG

void schedule(void *param) {
	struct epoll_event *events;
#ifdef DEBUG
	fprintf(stderr, "entered scheduler");
#endif
	int i;
	char buff[7];
	events = (struct epoll_event*) malloc(
			sizeof(struct epoll_event) * MAX_CLIENTS);
	while (1) {
#ifdef DEBUG
		fprintf(stderr, "entered while loop");
#endif
		int numEvents = epoll_wait(epfd, events, MAX_CLIENTS, -1);
		if (numEvents == 0) {
#ifdef DEBUG
			fprintf(stderr, "out of scheduler");
#endif
			break;
		}
#ifdef DEBUG
		fprintf(stderr, "out of wait");
#endif
		for (i = 0; i < numEvents; i++) {
			int fd = events[i].data.fd;
			Receive(fd, buff, sizeof(int) + 1);
			linkedList *temp = searchScheduler(socketList, fd);
			if (atoi(buff) >= 0 && temp != NULL ) {
				temp->data.priority = ((float) (atoi(buff) + 1)) * 1000;
			}
			//if the listener is closing, it sends -1 as the panning speed
			else {
				close(fd);
				if (temp != NULL ) {
					socketList = removeFromList(socketList, temp->data);
				}
			}
		}
	}
}
