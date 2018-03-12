#include "question.h"
#include <string>

Question::Question(std::string optionA, std::string optionB, std::string optionC, std::string optionD, std::string optionE, int difficulty, std::string answer, std::string topic)
	: optionA{optionA}, optionB{optionB}, optionC{optionC}, optionD{optionD}, optionE{optionE}, difficulty{difficulty}, answer{answer}, topic{topic} {}

Question::Question() {}

std::string Question::getOptionA() {
	return optionA;

}
std::string Question::getOptionB() {
	return optionB;
}

std::string Question::getOptionC() {
	return optionC;
}

std::string Question::getOptionD() {
	return optionD;
}

std::string Question::getOptionE() {
	return optionE;
}

int Question::getDifficulty() {
	return difficulty;
}

std::string Question::getAnswer() {
	return answer;
}

std::string Question::getTopic() {
	return topic;
}

void Question::setOptionA(std::string optionA) {
	this->optionA = optionA;

}
void Question::setOptionB(std::string optionB) {
	this->optionB = optionB;
}

void Question::setOptionC(std::string optionC) {
	this->optionC = optionC;
}

void Question::setOptionD(std::string optionD) {
	this->optionD = optionD;
}

void Question::setOptionE(std::string optionE) {
	this->optionE = optionE;
}

void Question::setDifficulty(int difficulty) {
	this->difficulty = difficulty;
}

void Question::setAnswer(std::string answer) {
	this->answer = answer;
}

void Question::setTopic(std::string topic) {
	this->topic = topic;
}