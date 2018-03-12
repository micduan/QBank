#include "testbank.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

testbank::testbank(std::string myPath) {
	std::ifstream inFile;
	inFile.open(myPath);

	// using getline doesn't retrieve all the lines so I have to do it manually :(


	std::string test;

	Question myQuestion;
	while (inFile >> test) { 
		// get rid of the text prior to any questions
		if (test == "1)") break;
	}
	inFile.close();
}

std::vector<Question> testbank::getQuestions() {
	return myQuestions;
}

std::vector<int> * testbank::getIndex() {
	return wrongIndex;
}