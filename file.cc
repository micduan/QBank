#include "file.h"
#include <iostream>
#include <fstream>

File::File(std::string filePath) : filePath{filePath} {}

bool File::validateFile() {
	std::ifstream f(this->filePath);
	if (!(this->filePath.substr(this->filePath.length() - 4) == ".txt")) return false; // extra check to ensure file is of .txt
	return f.good();
}

// returns a filestream
std::ifstream File::getFile() {
	bool validFile = this->validateFile();
	if (validFile) {
		return std::ifstream(this->filePath);
	}
	return std::ifstream(this->filePath);
}