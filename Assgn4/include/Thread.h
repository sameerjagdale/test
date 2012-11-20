/*
 * Thread.h
 *
 *  Created on: Nov 16, 2012
 *      Author: sameer
 */





class Thread {
public:
	Thread();
	Thread(void*);
	void start();
	virtual void execute()=0;
	void* join();
	virtual ~Thread()=0;
private:
	pthread_t handle;
	void *arg;
};


