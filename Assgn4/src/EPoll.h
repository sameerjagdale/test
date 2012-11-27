/*
 * EPoll.h
 *
 *  Created on: Nov 22, 2012
 *      Author: sameer
 */
#include<sys/epoll.h>



int epollCreate();
int epollAdd(int efd, int fd);
int epollDel(int epfd,int fd);


