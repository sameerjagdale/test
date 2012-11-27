/*
 * EPoll.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: sameer
 */
#include "EPoll.h"

int epollCreate(int numFd){

	return epoll_create(numFd);

}

int epollAdd(int epfd, int fd){
	struct epoll_event event;
	event.data.fd=fd;
	event.events=EPOLLIN;
	int ret=epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&event);
	return ret;
}

int epollDel(int epfd,int fd){
	struct epoll_event event;
	event.data.fd=fd;
	int ret=epoll_ctl(epfd,EPOLL_CTL_DEL,fd,&event);
	return ret;
}

