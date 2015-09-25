#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

long getFileSize(char* filename){
	
	FILE* tmpFile;
	long fileSize = -1;
	
	tmpFile = fopen(filename, "rb");
	fseek(tmpFile, 0, SEEK_END);
	fileSize = ftell(tmpFile);
	fclose(tmpFile);
	
	return fileSize;
}

int main(int argc, char* argv[]){
	
	//check if there is the correct number of arguments
	if (argc < 3){
		cout << "At least 3 arguments expected." << endl;
		cout << "Paramaters: [buffer size] [source file] [destination file]" << endl;
		return -1;
	}
	
	//setup initial variables
	int readBytes = 0;
	int writtenBytes = 0;
	clock_t timer;
	
	//create buffer
	int bufSize = atoi(argv[1]);
	char buffer [bufSize];
	
	//open files with correct permissions
	int origFile = open(argv[2], O_RDONLY);
	int newFile = open(argv[3], O_WRONLY + O_CREAT, S_IRUSR + S_IWUSR + S_IRGRP + S_IWGRP);
	
	//get the file size
	long fileSize = getFileSize(argv[2]);
	
	timer = clock();
	do{
		readBytes = read(origFile, buffer, bufSize);
		while (writtenBytes != readBytes){
			writtenBytes += write(newFile, buffer, (readBytes - writtenBytes));
		}
		writtenBytes = 0;
	} while (readBytes != 0);
	timer = clock() - timer;
	float totalTime = (((float)timer)/CLOCKS_PER_SEC);
	close(origFile);
	close(newFile);
	
	
	//cout << "Copied " << fileSize << " bytes in " << totalTime << " seconds, at the rate of " << fixed << (fileSize/totalTime) << " bytes per second." << endl;
	cout << bufSize << "," << fileSize << "," << totalTime << "," << fixed << (fileSize/totalTime) << endl;
	
}


