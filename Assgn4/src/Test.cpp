//============================================================================
// Name        : Test.cpp
// Author      : rahul
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <istream>
#include <iostream>
#include <fstream>
#include <iterator>
#include <stdio.h>
using namespace std;

void copyFile(char*, char*);

int main() {
	char inputFile[] = "./Firefox_wallpaper.png";
	char outputFile[] = "./copy.png";
	copyFile(inputFile, outputFile);
	return 0;
}

void copyFile(char *inputFile, char* outputFile){
//	fstream f(inputFile, fstream::in|fstream::binary);
//	f << noskipws;
//	istream_iterator<unsigned char> begin(f);
//	istream_iterator<unsigned char> end;
//
//	fstream f2(outputFile,
//	fstream::out|fstream::trunc|fstream::binary);
//	ostream_iterator<char> begin2(f2);
//
//	copy(begin, end, begin2);

	ifstream f1(inputFile, fstream::binary);
	ofstream f2(outputFile, fstream::trunc|fstream::binary);
	f2 << f1.rdbuf();
}
