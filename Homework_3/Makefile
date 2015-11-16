CC = g++
CFLAGS  = -g -Wall -std=c++11 -pthread

default: Homework3

Homework3: Program.cpp Calculator.o NumberWriter.o NumberReader.o ProgressMonitor.o Sequence.o ThreadSafeIntQueue.o SpinLock.o
	$(CC) $(CFLAGS) -o Homework3.exe Program.cpp Calculator.o NumberWriter.o NumberReader.o ProgressMonitor.o Sequence.o ThreadSafeIntQueue.o SpinLock.o

Calculator.o: Calculator.hpp Calculator.cpp ThreadSafeIntQueue.hpp
	$(CC) $(CFLAGS) -c Calculator.cpp

NumberWriter.o: NumberWriter.hpp NumberWriter.cpp
	$(CC) $(CFLAGS) -c NumberWriter.cpp

NumberReader.o: NumberReader.hpp NumberReader.cpp ThreadSafeIntQueue.hpp
	$(CC) $(CFLAGS) -c NumberReader.cpp

ProgressMonitor.o: ProgressMonitor.hpp ProgressMonitor.cpp ThreadSafeIntQueue.hpp
	$(CC) $(CFLAGS) -c ProgressMonitor.cpp

Sequence.o: Sequence.hpp Sequence.cpp
	$(CC) $(CFLAGS) -c Sequence.cpp

ThreadSafeIntQueue.o: ThreadSafeIntQueue.hpp ThreadSafeIntQueue.cpp SpinLock.hpp SpinLock.o
	$(CC) $(CFLAGS) -c ThreadSafeIntQueue.cpp

SpinLock.o: SpinLock.hpp SpinLock.cpp
	$(CC) $(CFLAGS) -c SpinLock.cpp


clean: 
	$(RM) Homework3.exe *.o *~
