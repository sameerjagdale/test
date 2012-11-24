/*
 * socket.c
 *
 *  Created on: Nov 23, 2012
 *      Author: sameer
 */

#include "socket.h"

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
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		return -1;

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(struct sockaddr))
			== 0)
		return sockfd;
	else
		return -1;
}

int listen(int sockfd, int queue) {
	listen(sockfd, queue);
	return 1;
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

int Recieve(int sockfd, char *buffer, int buffLen) {
	return read(sockfd, buffer, 255);
}

int Send(int sockfd, const char *buffer, int len) {
	return write(sockfd, buffer, strlen(buffer));
}

int Close(int sockfd) {
	if (sockfd > 0) {
		close(sockfd);
		return 1;
	}
	return -1;

}

/*
 int main() {

 return 0;
 }
 */


