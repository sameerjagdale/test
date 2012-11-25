/*
 ============================================================================
 Name        : test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "mysocket.h"
#include "Testy.h"

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	int sockfd = Create();
	char *temp = NULL;
	char buff[7];
	//char buff2[10];

	if (Connect("localhost", 35000, sockfd) < 0) {
		printf("error in connecting");
		exit(0);
	}
	int n = 0;
	n = Receive(sockfd, buff, sizeof(int));
	buff[n] = 0;
	temp=(char*)malloc(sizeof(char)*atoi(buff));
	int m = Receive(sockfd, temp,atoi(buff));
	fprintf(stderr,"bytes read=%d  size given =%d",m,atoi(buff));
	//if(m==atoi(buff)){
	int i,j,temp1;
	 i=0;
	j=strlen(temp) - 1;
		while(i < j) {
		temp1= temp[i];
		temp[i++] = temp[j];
		temp[j--] = temp1;
		}
		writeFile(temp,atoi(buff), "./copy.jpg");
		fprintf(stderr,"write successful");
	//}
	//else{
	//	fprintf(stderr,"error in reading file data from socket");
	//}
		sleep(10);
	Close(sockfd);
	return EXIT_SUCCESS;
}
