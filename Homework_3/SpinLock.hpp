#ifndef SPINLOCK_HPP_INCLUDED
#define SPINLOCK_HPP_INCLUDED

#include <iostream>
#include <atomic>

class SpinLock
{
	private:
		std::atomic_flag lock = ATOMIC_FLAG_INIT;
		//long locksFailed = 0;
	public:
		void Lock();
		void Unlock();
};

#endif // SPINLOCK_HPP_INCLUDED
