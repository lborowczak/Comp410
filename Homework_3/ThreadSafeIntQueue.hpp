#ifndef THREADSAFEINTQUEUE_HPP_INCLUDED
#define THREADSAFEINTQUEUE_HPP_INCLUDED

#include <queue>
#include <vector>

#include "SpinLock.hpp"


class ThreadSafeIntQueue
{
	private:
		std::queue<long> numberQueue;
		SpinLock lock;
	public:
		void Enqueue(long item);
		void EnqueueVector(std::vector<long> item);
		long Dequeue();
		std::vector<long> DequeueVector();
		bool IsEmpty();
		long GetCount();
		void ClearItems();
		long GetCountAndClear();
};

#endif // THREADSAFEINTQUEUE_HPP_INCLUDED
