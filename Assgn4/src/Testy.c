#include "Testy.h"

void readFile(char*, char*);
void writeFile(char*, int, char*);
int getSize();

/*In charge of all operations relating to image files
*/

//returns the size of the file
int getSize(char* filename){
	FILE* from;
	if((from = fopen(filename, "rb"))==NULL) {
		printf("Cannot open source file.\n");
		exit(1);
	}
	fseek(from, 0L, SEEK_END);
	int size = ftell(from);
	fseek(from, 0L, SEEK_SET);
	fclose(from);
	return size;
}

void readFile(char* s, char* source){
	FILE* from;
	char ch;

	//opens source file
	if((from = fopen(source, "rb"))==NULL) {
	    printf("Cannot open source file.\n");
	    exit(1);
	}
	int i=0;

	//reads from source file and stores it in the char array
	while(!feof(from)) {
		ch = fgetc(from);
		if(ferror(from)) {
			printf("Error reading source file.\n");
			exit(1);
		}
		if(!feof(from)&&i<100000000){
			*(s+i) = ch;
			i=i+1;
		}
	}

	//closes the source file
	if(fclose(from)==EOF) {
		printf("Error closing source file.\n");
		exit(1);
	}
}

void writeFile(char* data, int size, char* destination){
	FILE* to;
	  /* open destination file */
	if((to = fopen(destination, "wb"))==NULL) {
		printf("Cannot open destination file.\n");
	    exit(1);
	}
	int i;

	//writes to destination file
	for(i =0; i<size; i++){
		fputc(*(data+i), to);
		if(ferror(to)) {
			printf("Error writing destination file.\n");
			exit(1);
		}
	}

	//closes the file
	if(fclose(to)==EOF) {
		printf("Error closing destination file.\n");
		exit(1);
	}
}
