#include "SpinLock.hpp"

#include <chrono>
#include <thread>
#include <iostream>

//Implemented using C++11 from http://en.cppreference.com/w/cpp/atomic/atomic_flag

using namespace std;

void SpinLock::Lock()
{
	while (lock.test_and_set(memory_order_acquire)) {
		//locksFailed++;
		//if (locksFailed % 100000000 == 0){
		//	cout << locksFailed << endl;
		//}
	}
}

void SpinLock::Unlock()
{
	lock.clear(memory_order_release);
}

