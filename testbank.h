#include "question.h"
#include "fstream"
#include <vector>
#ifndef TESTBANK_H
#define TESTBANK_H

class testbank {
	std::vector<Question> myQuestions;
	std::vector<int> * wrongIndex;
private:
public:

	std::vector<Question> getQuestions();
	std::vector<int> * getIndex();
	testbank(std::string);
};

#endif