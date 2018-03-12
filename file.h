#include <fstream>
#ifndef FILE_H
#define FILE_H

class File {
private:
	std::string filePath;
	bool validateFile();
public:
	std::ifstream getFile();
	File(std::string filePath);
};

#endif