#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "ThreadSafeIntQueue.hpp"
#include <atomic>

class Calculator
{
	private:
		int firstNumToCheck = 3;
		bool CheckIfPrime(long numberToCheck);
	public:
		void Run(ThreadSafeIntQueue * numList, ThreadSafeIntQueue * primeNums, bool * readerDone);
};

#endif // CALCULATOR_H
