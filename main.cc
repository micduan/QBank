#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "start.h"
#include "file.h"
#include "testbank.h"
#include "displayquestion.h"
#include <iostream>
#include <fstream>
#include <vector>


int main(int argc, char **argv){
	Start *startScreen = new Start(); 
	startScreen->init();
	const char* myPath = startScreen->getFilePath();
	ALLEGRO_DISPLAY* display = startScreen->get_display();

	//File *myFile = new File(myPath);

	testbank *myTestBank = new testbank(myPath);



	std::cout << myPath << std::endl;
	al_flip_display();
	al_rest(0.1);
	al_clear_to_color(al_map_rgb(255,255,255));
	al_flip_display();

	int total_questions = 0;
	int correct_questions = 0;

	std::vector<Question> myQuestions = myTestBank->getQuestions();
	int questionSize = myQuestions.size();
	for (int index = 0; index < questionSize; ++index) {
		displayquestion questionDisplay = displayquestion(myQuestions[index]);
		questionDisplay.init();


		// wait for mouse event

		questionDisplay.clearBackground();();
	}


	int age;
	std::cin >> age;

    startScreen->removeBG();
    delete startScreen;
    return 0;
}