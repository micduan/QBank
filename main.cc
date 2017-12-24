#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "start.h"
#include <iostream>


int main(int argc, char **argv){
	Start *startScreen = new Start(); 
	startScreen->init();
	const char* myPath = startScreen->getFilePath();

	std::cout << myPath << std::endl;

    startScreen->removeBG();
    delete startScreen;
    return 0;
}