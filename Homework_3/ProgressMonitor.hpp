#ifndef PROGRESSMONITOR_HPP
#define PROGRESSMONITOR_HPP

#include <vector>
#include "ThreadSafeIntQueue.hpp"

class ProgressMonitor
{
	private:
		long totalCount = 0;
	public:
		void Run(ThreadSafeIntQueue * primeNums, bool * readerDone);
};

#endif // PROGRESSMONITOR_HPP
