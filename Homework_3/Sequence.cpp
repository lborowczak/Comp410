#include "Sequence.hpp"

#include <vector>

using namespace std;

long* GenerateSequence(long numMin, long numMax) {
	long* sequence = new long[numMax - numMin];
    for (long i = numMin; i < numMax; i++) {
		sequence[i-numMin] = i;
    }
	return sequence;
}


/*
using System.Collections.Generic;

namespace Homework3 {
    internal static class Sequence {
        public static IEnumerable<long> Create(long lowerBound, long upperBound) {
            for (var i = lowerBound; i < upperBound; i++) {
                yield return i;
            }
        }
    }
}
*/
