#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <fstream>

#include "displayquestion.h"
#include "question.h"

displayquestion::displayquestion(Question question)
{
	this->question = question;
}

displayquestion::~displayquestion() 
{

}

void displayquestion::clearBackground()
{
	al_flip_display();
	al_rest(0.1);
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
}

void displayquestion::init()
{
	std::cout << "INITIATED" << std::endl;
	Question question = this->question;
	std::string myquestion = question.getQuestion();
	std::string optionA = question.getOptionA();
	std::string optionB = question.getOptionB();
	std::string optionC = question.getOptionC();
	std::string optionD = question.getOptionD();
	std::string optionE = question.getOptionE();
	std::string topic = question.getTopic();
	int difficulty = question.getDifficulty();

    ALLEGRO_FONT *mainFont = al_load_font("Additional_Resources/Fonts/arial.ttf", 36, 0);
    al_clear_to_color(al_map_rgb(255,255,255));

    // Required to convert string to const char * using .c_str()

	al_draw_text(mainFont, al_map_rgb(0, 0, 0), 100, 100, 0, ("Topic: " + topic).c_str());
	al_draw_text(mainFont, al_map_rgb(0, 0, 0), 100, 150, 0, ("Difficulty: " + std::to_string(difficulty)).c_str());
	al_draw_text(mainFont, al_map_rgb(0, 0, 0), 100, 400, 0, ("Question: " + myquestion).c_str());
	al_draw_text(mainFont, al_map_rgb(0, 0, 0), 100, 500, 0, ("A) " + optionA).c_str());
	al_draw_text(mainFont, al_map_rgb(0, 0, 0), 100, 550, 0, ("B) " + optionB).c_str());
	al_draw_text(mainFont, al_map_rgb(0, 0, 0), 100, 600, 0, ("C) " + optionC).c_str());
	al_draw_text(mainFont, al_map_rgb(0, 0, 0), 100, 650, 0, ("D) " + optionD).c_str());
	al_draw_text(mainFont, al_map_rgb(0, 0, 0), 100, 700, 0, ("E) " + optionE).c_str());
	al_flip_display();

}