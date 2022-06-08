#pragma once


#include <fstream>
#include <iostream>


using std::fstream;
using::ios_Base;


class DataFile {
private:
	
	ios_Base::openmode openMode;
	const char* path;
public:
	fstream file;
	DataFile();
	DataFile(const char*);
	~DataFile();


	void open(const char*);

	void close();
	void write(char*, unsigned int , unsigned int);
	char* read(unsigned int, unsigned int);

	bool iseof();
};