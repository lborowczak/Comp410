#include "ThreadSafeIntQueue.hpp"

void ThreadSafeIntQueue::Enqueue(long item)
{
	lock.Lock();
	numberQueue.push(item);
	lock.Unlock();
}

void ThreadSafeIntQueue::EnqueueVector(std::vector<long> item)
{
	lock.Lock();
	for (std::vector<long>::iterator it = item.begin() ; it != item.end(); ++it) {
		numberQueue.push(*it);
	}
	lock.Unlock();
}

long ThreadSafeIntQueue::Dequeue()
{
	long tmpvar;
	lock.Lock();
	if (numberQueue.empty())
	{
		lock.Unlock();
		return -1;
	}
	tmpvar = numberQueue.front();
	numberQueue.pop();
	lock.Unlock();
	return tmpvar;
}

std::vector<long> ThreadSafeIntQueue::DequeueVector()
{
	std::vector<long> returnVect;
	lock.Lock();
	for (int i=0; i<1000; i++){
		if (numberQueue.empty())
		{
			lock.Unlock();
			return returnVect;
		}
		returnVect.push_back(numberQueue.front());
		numberQueue.pop();

	}
	lock.Unlock();
	return returnVect;
}

bool ThreadSafeIntQueue::IsEmpty()
{
	return numberQueue.empty();
}

long ThreadSafeIntQueue::GetCount() {
	long tmpCount = 0;
	lock.Lock();
    tmpCount = numberQueue.size();
    lock.Unlock();
    return tmpCount;
}

void ThreadSafeIntQueue::ClearItems() {
	std::queue<long> emptyQueue;
	lock.Lock();
    numberQueue = emptyQueue;
    lock.Unlock();
}

long ThreadSafeIntQueue::GetCountAndClear() {
	long tmpCount = 0;
    std::queue<long> emptyQueue;
	lock.Lock();
    tmpCount = numberQueue.size();
    numberQueue = emptyQueue;
    lock.Unlock();
    return tmpCount;
}
