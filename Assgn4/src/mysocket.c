/*
 * socket.c
 *
 *  Created on: Nov 23, 2012
 *      Author: sameer
 */

#include "mysocket.h"

int Create() {
	int sockfd = -1;
	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	return sockfd;
}

int Bind(int port, int sockfd) {
	struct sockaddr_in serv_addr;
	bzero((char *) &serv_addr, sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);
	fprintf(stderr,"entered bind");
	return  bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

}

int Listen(int sockfd, int queue) {
	return  listen(sockfd, queue);

}

int Accept(int sockfd) {
	struct sockaddr_in cli_addr;
	socklen_t clilen = sizeof(cli_addr);
	int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0)
		return -1;
	return newsockfd;
}

int Connect(char* address, int port, int sockfd) {
	struct sockaddr_in serv_addr;
	struct hostent *server;
	server = gethostbyname(address);
	if (server == NULL ) {
		return -1;
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr,
	(char *)&serv_addr.sin_addr.s_addr,
	server->h_length);
	serv_addr.sin_port = htons(port);
	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		return -1;
	return 1;

}

int Receive(int sockfd, char *buffer, unsigned long buffLen) {
	return read(sockfd, buffer,buffLen);
}

int Send(int sockfd, const char *buffer, unsigned long len) {
	return write(sockfd, buffer, len);
}

int Close(int sockfd) {
	if (sockfd > 0) {
		close(sockfd);
		return 1;
	}
	return -1;

}

//Socket programming v2

/*
 int main() {

 return 0;
 }
 */


