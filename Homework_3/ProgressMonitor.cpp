#include "ProgressMonitor.hpp"
#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

void ProgressMonitor::Run(ThreadSafeIntQueue * primeNums, bool * readerDone)
{
    while (true) {
		this_thread::sleep_for(chrono::milliseconds(100));
		int currentCount = primeNums->GetCountAndClear();
		totalCount += currentCount;

		if (currentCount > 0) {
			cout << totalCount << " primes found so far" << endl;
		}
		else if (*readerDone) {
			return;
			}

    }


}
