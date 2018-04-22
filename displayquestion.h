#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "question.h"
#ifndef DISPLAYQUESTION_H
#define DISPLAYQUESTION_H

class displayquestion {
	Question question;
	ALLEGRO_FONT *mainFont;
	ALLEGRO_EVENT_QUEUE *event_queue;
public:
	displayquestion(Question);
	~displayquestion();
	void init();
	void clearBackground();
};

#endif