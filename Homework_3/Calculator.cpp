#include "Calculator.hpp"

#include <math.h>
#include <thread>
#include <chrono>
#include <vector>

void Calculator::Run(ThreadSafeIntQueue * numList, ThreadSafeIntQueue * primeNums, bool * readerDone)
{
    while (true) {
    	if (numList->IsEmpty()) {
			if (!(*readerDone)) {
				std::vector<long> numbersToCheck = numList->DequeueVector();
				std::vector<long> primes;
				for (std::vector<long>::iterator it = numbersToCheck.begin() ; it != numbersToCheck.end(); ++it) {
					if (CheckIfPrime(*it)) {
						primes.push_back(*it);
					}
				}
				primeNums->EnqueueVector(primes);
				std::this_thread::sleep_for(std::chrono::milliseconds(100)); //sleep to let the reader add more numbers
			}
			else return;
    	}
		else {
			std::vector<long> numbersToCheck = numList->DequeueVector();
			std::vector<long> primes;
			for (std::vector<long>::iterator it = numbersToCheck.begin() ; it != numbersToCheck.end(); ++it) {
				if (CheckIfPrime(*it)) {
					primes.push_back(*it);
				}
			}
			primeNums->EnqueueVector(primes);
			if (!*readerDone) {
				std::this_thread::sleep_for(std::chrono::milliseconds(100)); //sleep to let the reader add more numbers
			}
		}
    }
}

bool Calculator::CheckIfPrime(long numberToCheck){
	if (numberToCheck % 2 == 0){
		return false;
	}
	long lastNumberToCheck = sqrt(numberToCheck);
	for (long currentDivisor = firstNumToCheck; currentDivisor < lastNumberToCheck; currentDivisor += 2) {
		if (numberToCheck % currentDivisor == 0) {
			return false;
		}
	}
	return true;
}
