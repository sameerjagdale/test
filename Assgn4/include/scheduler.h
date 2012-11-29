/*
 * scheduler.h
 *
 *  Created on: Nov 27, 2012
 *      Author: sameer
 */

#include "stdlib.h"
#include "mysocket.h"
#include "linkedList.h"
#include "EPoll.h"
#define MAX_CLIENTS 100
int epfd;
void add(sockets s1);
void process(int sockfd);
void schedule(void*);

