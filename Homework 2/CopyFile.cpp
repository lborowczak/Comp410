#include <unistd.h>
using namespace std;

int main(int argc, char* argv[]{
		//open file
		int origFile = open(argv[2], O_RDONLY);
		int newFile = open(argv[3], O_CREAT);
		int bufSize = stoi(argv[1]);
		char[bufSize] buffer;
		int readBytes = 0;
		int writtenBytes = 0;

		while (???){
			readBytes = read(origFile, ?, bufSize);
			while (writtenBytes != readBytes){
				writtenBytes += write(newFile, ??, (readBytes - writtenBytes));
			}
			writtenBytes = 0;
		}


}
