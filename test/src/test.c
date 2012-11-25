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
	char* images[5];
	images[0]="lala1.jpg";
	images[1]="lala2.jpg";
	images[2]="lala3.jpg";
	images[3]="lala4.jpg";
	images[4]="lala5.jgp";

	int randomNumber = rand() % 5;

	while(randomNumber!=0){
		randomImage = images[rand() % (sizeof(arr) / sizeof(arr[0]))];
		Send(sockfd, randomImage, strlen(randomImage));
		int n = 0;
		n = Receive(sockfd, buff, sizeof(int));
		buff[n] = 0;
		temp=(char*)malloc(sizeof(char)*atoi(buff));
		int m = Receive(sockfd, temp,atoi(buff));
		fprintf(stderr,"bytes read=%d  size given =%d",m,atoi(buff));{
		int i,j,temp1;
		 i=0;
		j=strlen(temp) - 1;
			while(i < j) {
			temp1= temp[i];
			temp[i++] = temp[j];
			temp[j--] = temp1;
			}
		writeFile(temp,atoi(buff), strcat(strcat("./copyOf", imageName),".jpg")));
		fprintf(stderr,"write successful");
		randomNumber -= 1;
	}

	Close(sockfd);
	return EXIT_SUCCESS;
}
