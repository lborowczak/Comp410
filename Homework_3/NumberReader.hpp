#ifndef NUMBERREADER_HPP_INCLUDED
#define NUMBERREADER_HPP_INCLUDED

#include "ThreadSafeIntQueue.hpp"

ThreadSafeIntQueue* ReadNumbers(char* fileName, ThreadSafeIntQueue* numberQueue);

#endif // NUMBERREADER_HPP_INCLUDED
