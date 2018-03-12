#include <string>

class Question {
	std::string optionA;
	std::string optionB;
	std::string optionC;
	std::string optionD;
	std::string optionE;
	int difficulty;
	std::string answer;
	std::string topic;
public:
	Question(std::string, std::string, std::string, std::string, std::string, int, std::string, std::string);
	Question();
	std::string getOptionA();
	std::string getOptionB();
	std::string getOptionC();
	std::string getOptionD();
	std::string getOptionE();
	int getDifficulty();
	std::string getAnswer();
	std::string getTopic();
	void setOptionA(std::string);
	void setOptionB(std::string);
	void setOptionC(std::string);
	void setOptionD(std::string);
	void setOptionE(std::string);
	void setDifficulty(int);
	void setAnswer(std::string);
	void setTopic(std::string);
};