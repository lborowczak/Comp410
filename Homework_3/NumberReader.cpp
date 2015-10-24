#include "ThreadSafeIntQueue.hpp"

#include <fstream>
#include <thread>

using namespace std;

void ReadNumbers(char* fileName, ThreadSafeIntQueue* numberQueue) {
	ifstream readerStream(fileName);
	string tmpNumber;
	bool somethingLeft = true;
	vector<thread> pushThreads;

	while (somethingLeft)
	{
		vector<long> enqueueBuffer;
		for (int i=0; i<100000; i++) {
			if (getline(readerStream, tmpNumber) && (tmpNumber!= "") && somethingLeft)
			{
				enqueueBuffer.push_back(stol(tmpNumber));
			}
			else {
                somethingLeft = false;
			}
		}
		numberQueue->EnqueueVector(enqueueBuffer);
		//pushThreads.push_back(thread(&ThreadSafeIntQueue::EnqueueVector, numberQueue, enqueueBuffer));
	}
	/*
	while (getline(readerStream, tmpNumber) && (tmpNumber!= "")){
		numberQueue->Enqueue(stol(tmpNumber));
	}
	*/
	/*auto currThread = pushThreads.begin();

	while (currThread != pushThreads.end())
	{
	   currThread->join();
	   currThread++;
	}
	*/
	readerStream.clear();
	readerStream.close();
}

