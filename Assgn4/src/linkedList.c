/*
 * linkedList.c
 *
 *  Created on: Nov 27, 2012
 *      Author: sameer
 */
#include "linkedList.h"
#include<stdlib.h>
//#define DEBUG
linkedList *socketList = NULL;

linkedList * addToList(linkedList * head, sockets newsock) {

	if (head == NULL ) {
		head = (linkedList*) malloc(sizeof(linkedList*));
		head->next = NULL;
		head->data = newsock;
	} else {
		linkedList *temp = head;
		while (temp->next != NULL ) {
			temp = temp->next;
		}
		temp->next = (linkedList*) malloc(sizeof(linkedList));
		temp = temp->next;
		temp->next = NULL;
		temp->data = newsock;

	}
	return head;
}

linkedList * removeFromList(linkedList*head, sockets data) {
	linkedList *temp, *prev;
	if (head->data.schedulerSocket == data.schedulerSocket) {
		temp = head->next;
		free(head);
		head = temp;
	} else {
		temp = head->next;
		while (temp != NULL ) {
			if (temp->data.schedulerSocket == data.schedulerSocket) {
				break;
			}
			prev = temp;
			temp = temp->next;
		}
		if (temp != NULL ) {
			prev->next = temp->next;
			free(temp);
		}

	}
	return head;
}
int contains(linkedList * head, sockets data) {
	linkedList*temp = NULL;

	temp = searchScheduler(head, data.schedulerSocket);
	if (temp == NULL ) {
		return 0;
	} else {
		return 1;
	}
}
linkedList* searchWorker(linkedList *head, int workerFd) {
	linkedList*temp = head;
	while (temp != NULL ) {
		if (temp->data.workerSocket == workerFd) {
			break;
		}
		temp = temp->next;
	}
	return temp;
}
linkedList* searchScheduler(linkedList *head, int schedulerfd) {
	linkedList*temp = head;
	while (temp != NULL ) {

		if (temp->data.schedulerSocket == schedulerfd) {
#ifdef DEBUG
			fprintf(stderr,"data found ");
#endif
			break;
		}
		temp = temp->next;
	}
	if(temp==NULL){

#ifdef DEBUG
			fprintf(stderr,"data found ");
#endif
	}
	return temp;
}

