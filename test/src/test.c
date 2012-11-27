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

int main(int argc,char*argv[]) {
	fprintf(stderr,"\nThread number - 	%s\n",argv[1]);
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
	images[0] = "lala1.png";
	images[1] = "lala2.png";
	images[2] = "lala3.png";
	images[3] = "lala4.png";
	images[4] = "lala5.png";

	srand(time(NULL));
	int randomNumber = (rand() % 5)+1;
	int count = 1;
	while (randomNumber != 0) {
		char *randomImage =
				images[rand() % (sizeof(images) / sizeof(images[0]))];
		Send(sockfd, randomImage, strlen(randomImage));
		int n = 0;
		n = Receive(sockfd, buff, sizeof(int) + 1);
		buff[n] = 0;
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

		strcpy(path, "./bin/copyOfRequest");
		strcat(path, countChar);
		strcat(path,"threadNo");
		strcat(path,argv[1]);
		strcat(path, randomImage);

		writeFile(temp, atoi(buff), path);
		fprintf(stderr, "write successful");
		randomNumber -= 1;
		count += 1;

	}
	Close(sockfd);
	return EXIT_SUCCESS;
}
