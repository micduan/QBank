#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#ifndef START_H
#define START_H

class Start {
	ALLEGRO_DISPLAY *myDisplay;
	ALLEGRO_BITMAP *myBG;
	ALLEGRO_FONT *mainFont;
	ALLEGRO_EVENT_QUEUE *event_queue;
public:
	Start();
	~Start();
	void init();
	void removeBG();
	ALLEGRO_DISPLAY *get_display();
	const char * getFilePath();
};

#endif