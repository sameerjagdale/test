/*
 * worker.h
 *
 *  Created on: Nov 24, 2012
 *      Author: sameer
 */
#include "mysocket.h"
#include<pthread.h>


typedef union _converter {
	char charSize[4];
	int size;
} converter;

void negotiator(void*);
void incClient();
void decClient();
int numClient();
int isEmpty();
