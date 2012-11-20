/*
 * Thread.cpp
 *
 *  Created on: Nov 16, 2012
 *      Author: sameer
 */
#include <iostream>
#include "Thread.h"


extern "C"
{
    // this C function will be used to receive the thread and pass it back to the Thread instance
    void* thread_catch(void* arg) {
        Thread* t = static_cast<Thread*>(arg);
        t->execute();
        return 0;
    }
}


Thread::Thread(void * obj) {

	handle=0;
	arg=obj;
}
void Thread:: start(){
	pthread_create(&handle, 0, thread_catch, this);
}

void* Thread::join(){
	void *val=NULL;
	pthread_join(handle,&val);
	return val;

}

Thread :: Thread(){
	handle=0;
	arg=this;
}
Thread:: ~Thread(){

}



