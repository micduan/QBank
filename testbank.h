#include "question.h"
#include "fstream"
#include <vector>

class testbank {
	std::vector<Question> myQuestions;
	std::vector<int> * wrongIndex;
private:
	std::vector<Question> getQuestions();
	std::vector<int> * getIndex();
public:

	testbank(std::string);
};