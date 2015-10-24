#include "NumberWriter.hpp"
#include <fstream>

using namespace std;

void WriteNumbers(char* fileName, long numbers[]) {
	ofstream writerStream(fileName);	//replaces file if not explicity told to only append
	long i=0;
	while (numbers[i] != NULL) {
		writerStream << numbers[i] << "\n";
		i++;
	}
	writerStream.clear();
	writerStream.close();
	delete [] numbers;
}


//fopen ( const char * filename, const char * mode );


/*
using System;
using System.Collections.Generic;
using System.IO;

namespace Homework3 {
    internal class NumberWriter : IDisposable {
        private readonly TextWriter _writer;

        public NumberWriter(FileInfo file) {
            if (File.Exists(file.FullName)) {
                File.Delete(file.FullName);
            }
            _writer = new StreamWriter(new BufferedStream(new FileStream(
                file.FullName, FileMode.Create, FileAccess.Write, FileShare.None, 8192, FileOptions.SequentialScan)));
        }

        public void WriteIntegers(IEnumerable<long> values) {
            foreach (var value in values) {
                _writer.WriteLine(value);
            }
        }

        public void Dispose() {
            _writer.Dispose();
        }
    }
}
*/
