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
#include "string.h"
//#define DEBUG

//get the panning speed ( a random number)
int getPanningSpeed(int currSpeed) {
	int randomNumber = (rand() % 6);

	//50% chance of the panning speed not changing
	if (randomNumber > 3) {
		currSpeed = (rand() % 5) + 1;
	}

	return currSpeed;
}

int main(int argc, char*argv[]) {
	fprintf(stderr, "\nThread number - 	%s\n", argv[1]);
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	int sockfd = Create();
	int schedulerfd = Create();
	//int schedulerSocket = Create();
	char *temp = NULL;
	char buff[7], accept[256];
	int panningSpeed = 0;
	//char buff2[10];

	if (Connect("localhost", 35000, sockfd) < 0) {
		printf("error in connecting");
		exit(0);
	}
	if (Connect("localhost", 35001, schedulerfd) < 0) {
		printf("error in connecting to scheduler");
		exit(0);
	}
	int n = Receive(sockfd, accept, 256);
	accept[n] = 0;
	if (strcasecmp(accept, "REJECT") == 0) {
		fprintf(stderr, "SERVER REJECTED CONNECTION: PLEASE TRY AGAIN LATER");
		exit(0);
	} else {
		fprintf(stderr, "SERVER ACCEPTED CONNECTION");
	}
	char* images[5];
	images[0] = "lala1.png";
	images[1] = "lala2.png";
	images[2] = "lala3.png";
	images[3] = "lala4.png";
	images[4] = "lala5.png";

	srand(time(NULL));
	int randomNumber = ((rand() + getpid()) % 5) + 1;
	int count = 1;

	//just a test to prove that we are using multithreading!
#ifdef DEBUG
	fprintf(stderr, "\nPID = %d\n", getpid());
#endif

	while (randomNumber != 0) {
		char *randomImage = images[(rand() + getpid())
				% (sizeof(images) / sizeof(images[0]))];
		Send(sockfd, randomImage, strlen(randomImage));
		int n = 0;

		n = Receive(sockfd, buff, sizeof(int) + 1);
		buff[n] = 0;
		//the server returns the image size as 0 if it does not intend to send the image
		if(atoi(buff) != 0){

			fprintf(stderr, "\nNumber of bytes read for size= %d\n", n);
			temp = (char*) malloc(sizeof(char) * atoi(buff));
			int m = Receive(sockfd, temp, atoi(buff));
			fprintf(stderr, "bytes read=%d  size given =%d\n", m, atoi(buff));

			int i, j, temp1;
			i = 0;
			j = strlen(temp) - 1;
			while (i < j) {
				temp1 = temp[i];
				temp[i++] = temp[j];
				temp[j--] = temp1;
			}
			char countChar[5];
			sprintf(countChar, "%d", count);
			char path[100];
			strcpy(path, "./copyOfRequest");

			//uncomment if you want to have the image files stored in a seperate folder
			//strcpy(path, "./bin/copyOfRequest");

			strcat(path, countChar);
			strcat(path, "threadNo");
			strcat(path, argv[1]);
			strcat(path, randomImage);

			writeFile(temp, atoi(buff), path);
			fprintf(stderr, "write successful");
		}
		else
			fprintf(stderr, "\nServer rejected the request \n");
		randomNumber -= 1;
		count += 1;

		//get the panning speed and send it
		panningSpeed = getPanningSpeed(panningSpeed);
		char tempy[256];
		sprintf(tempy, "%d", panningSpeed);
		Send(schedulerfd, tempy, strlen(tempy));
	}
	char tempy[256];
	panningSpeed = -1;
	sprintf(tempy, "%d", panningSpeed);

	//send the panning speed as -1 to indicate to the server that the client is shutting down
	Send(schedulerfd, tempy, strlen(tempy));
	Close(sockfd);
	return EXIT_SUCCESS;
}
