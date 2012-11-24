//============================================================================
// Name        : Assgn4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Thread.h"
#include "Mutex.h"
#include <unistd.h>
using namespace std;

class test: public Thread {



public :
	static Mutex mutex;
	test(){

	}

	void virtual execute(){
		test::mutex.lock();
		cout<<"thread execution"<<endl;
		cout<<"after lock"<<endl;
		test::mutex.unlock();
		cout<<"after unlock"<<endl;
		sleep(1);
		test::mutex.lock();
		cout<<"afterlock2"<<endl;
		test::mutex.unlock();

	}


};
Mutex test::mutex;
int main() {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	test t[2];
	t[0].start();
	t[1].start();
	t[0].join();
	t[1].join();
	return 0;
}
