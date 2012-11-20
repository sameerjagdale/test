/*
 * Mutex.h
 *
 *  Created on: Nov 17, 2012
 *      Author: sameer
 */

#ifndef MUTEX_H_
#define MUTEX_H_
#include<pthread.h>
class Mutex {
public:
	Mutex();
	int lock();
	int unlock();
	int trylock();
private:
	pthread_mutex_t mutex;
};

#endif /* MUTEX_H_ */
