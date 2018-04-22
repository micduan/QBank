#include "testbank.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <regex>

testbank::testbank(std::string myPath) {
	std::ifstream inFile;
	inFile.open(myPath);

	// using getline doesn't retrieve all the lines so I have to do it manually :(


	std::string test;
	while (inFile >> test) { 
		// get rid of the text prior to any questions
		if (test == "1)") break;
	}

	while (true) {
		Question myQuestion;	
		std::string current = "question";
		std::string question;
		std::string optionA;
		std::string optionB;
		std::string optionC;
		std::string optionD;
		std::string optionE;
		std::string difficulty;
		std::string answer;
		std::string topic;

		std::string any_number = "^([0-9]*)\\)$";
		std::regex nextQuestion(any_number);
		while (inFile >> test) {
			if (regex_match(test, nextQuestion)) {
				Question myQuestion(question, optionA, optionB, optionC, optionD, optionE, stoi(difficulty), answer, topic);
				this->myQuestions.push_back(myQuestion);
				break;
			}

			if (test == "A)") {
				current = "optionA";
				continue;
			}

			if (test == "B)") {
				current = "optionB";
				continue;
			}

			if (test == "C)") {
				current = "optionC";
				continue;
			}

			if (test == "D)") {
				current = "optionD";
				continue;
			}

			if (test == "E)") {
				current = "optionE";
				continue;
			}

			if (test == "Answer:") {
				current = "answer";
				continue;
			}

			if (test == "Diff:") {
				current = "difficulty";
				continue;
			}

			if (test == "Topic:") {
				current = "topic";
				continue;
			}

			if (current == "question") {
				question += " " + test;
			} else if (current == "optionA") {
				optionA += " " + test;
			} else if (current == "optionB") {
				optionB += " " + test;
			} else if (current == "optionC") {
				optionC += " " + test;
			} else if (current == "optionD") {
				optionD += " " + test;
			} else if (current == "optionE") {
				optionE += " " + test;
			} else if (current == "answer") {
				answer += " " + test;
			} else if (current == "difficulty") {
				difficulty += " " + test;
			} else if (current == "topic") {
				topic += " " + topic;
			}
		}

		if (inFile.eof()) {
			Question myQuestion(question, optionA, optionB, optionC, optionD, optionE, stoi(difficulty), answer, topic);
			this->myQuestions.push_back(myQuestion);
			break;
		}

	}
	inFile.close();
}

std::vector<Question> testbank::getQuestions() {
	return myQuestions;
}

std::vector<int> * testbank::getIndex() {
	return wrongIndex;
}