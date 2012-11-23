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
#include <sstream>
#include <iterator>
#include <stdio.h>
using namespace std;

void copyFile(char*, char*);
string readFile(char*);
void writeFile(char*, string);

int main() {
	char inputFile[] = "./Firefox_wallpaper.png";
	char outputFile[] = "./copy.png";
	copyFile(inputFile, outputFile);
	return 0;
}

void copyFile(char *inputFile, char* outputFile){
	writeFile(outputFile, readFile(inputFile));
}

void writeFile(char* outputFile, string data){
	ofstream f2(outputFile, fstream::trunc|fstream::binary);
	f2 << data;
}

string readFile(char* inputFile){
	std::ifstream in(inputFile, std::ios::in | std::ios::binary);
	std::string contents;
	if (in)
	{
	    in.seekg(0, std::ios::end);
	    contents.reserve(in.tellg());
	    in.seekg(0, std::ios::beg);
	    contents.assign((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	    in.close();
	 }
	return contents;
}
