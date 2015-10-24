#include "Program.hpp"
#include "Calculator.hpp"
#include "NumberWriter.hpp"
#include "NumberReader.hpp"
#include "ProgressMonitor.hpp"
#include "Sequence.hpp"
#include "ThreadSafeIntQueue.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <atomic>


using namespace std;

const long LowerBound = 1000000;
const long UpperBound = 5000000; //from original program

int main(int argc, char* argv[]) {
	//argument parsing/checking
	//WriteNumbers("numbers.txt", GenerateSequence(LowerBound, UpperBound));
	//process("numbers.txt");
	//return 0;
	if (argc != 3){
		printUsage();
		return -1;
	}

	else if (string(argv[1]) == "--createDataFile") {
		WriteNumbers(argv[2], GenerateSequence(LowerBound, UpperBound));
		return 0;
	}

	else if (string(argv[1]) == "--processDataFile") {
		auto startTime = chrono::system_clock::now();
		process(argv[2]);
		auto endTime = chrono::system_clock::now();
		chrono::duration<double> elapsedTime = endTime - startTime ;
		cout << fixed << elapsedTime.count() << endl;
		return 0;
	}

	else {
		printUsage();
		cout << argv[1] << "\n" << argv[2] << endl;
		return -1;
	}

    return 0;
}


void printUsage() {
	cout << "Usage:" << endl;
	cout << "Homework3 --createDataFile [file name]" << endl;
	cout << "Homework3 --processDataFile [file name]" << endl;
}

void process(char* argument2) {
	int threadNum = thread::hardware_concurrency() * 2; //get number of cores on the machine and multiply by 2
	ThreadSafeIntQueue* mainQueue = new ThreadSafeIntQueue;
	ThreadSafeIntQueue* primeNums = new ThreadSafeIntQueue;
	bool * readerDone = new bool;
	*readerDone = false;
	cout << "Using " << threadNum << " compute threads and 1 I/O thread" << endl;
	thread readThread(ReadNumbers, argument2, mainQueue); //read numbers from file into mainQueue in a seperate thread
	vector<thread> CalcThreads;

	for (int i=0; i < threadNum; i++) {
		CalcThreads.push_back(thread(&Calculator::Run, new Calculator, mainQueue, primeNums, readerDone));
	}
	thread progressThread(&ProgressMonitor::Run, new ProgressMonitor, primeNums, readerDone); //start progress monitor
	readThread.join();
	*readerDone = true;

	auto currThread = CalcThreads.begin();

	while (currThread != CalcThreads.end())
	{
	   currThread->join();
	   currThread++;
	}
	progressThread.join();

	delete readerDone;
	delete mainQueue;
	delete primeNums;
}
