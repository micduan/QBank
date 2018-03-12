#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "start.h"
#include "file.h"
#include "testbank.h"
#include <iostream>
#include <fstream>


int main(int argc, char **argv){
	Start *startScreen = new Start(); 
	startScreen->init();
	const char* myPath = startScreen->getFilePath();

	//File *myFile = new File(myPath);

	testbank *myTestBank = new testbank(myPath);



	std::cout << myPath << std::endl;
	int age;
	std::cin >> age;

    startScreen->removeBG();
    delete startScreen;
    return 0;
}