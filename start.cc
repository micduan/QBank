#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <iostream>

#include "start.h"

Start::Start() {
	this->myDisplay = NULL;
	this->myBG = NULL;
	this->mainFont = NULL;
	this->event_queue = NULL;

	if (!al_init()) {
   		al_show_native_message_box(NULL, NULL, NULL, "Couldn't initialize", NULL, ALLEGRO_MESSAGEBOX_ERROR);
   		throw;
    }
}

void Start::init() {
   this->myDisplay = al_create_display(800,600);

    if (!al_init_image_addon()) {
        al_show_native_message_box(myDisplay, "Error", "Error", "Failed to initialize al_init_image_addon!", 
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
        throw;
    }

    al_set_window_title(myDisplay, "ECON questionbank v1.0");

    if (!myDisplay) {
   		al_show_native_message_box(myDisplay, "Sample Title", "Display Settings", "Display window", NULL, ALLEGRO_MESSAGEBOX_ERROR);
   		throw;
    }
    al_init_font_addon();
    al_init_ttf_addon();

    this->myBG = al_load_bitmap("Additional_Resources/Images/background.jpg");

    if(!myBG) {
        al_show_native_message_box(myDisplay, "Error", "Error", "Failed to load image!", 
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(myDisplay);
        throw;
    }

    this->mainFont = al_load_font("Additional_Resources/Fonts/arial.ttf", 36, 0);
    al_clear_to_color(al_map_rgb(255,255,255));
    al_draw_bitmap(myBG, 450, 50, 0);
    al_draw_text(mainFont, al_map_rgb(0, 0, 0), 100, 200, 0, "Please choose the document containing the ECON questionbank.");
    al_flip_display();

    al_install_mouse();
	this->event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_mouse_event_source());
}

Start::~Start() {
    al_destroy_display(this->myDisplay);
}

void Start::removeBG() {
    al_destroy_bitmap(this->myBG);
}

ALLEGRO_DISPLAY *Start::get_display() {
	return this->myDisplay;
}

const char * Start::getFilePath() {
	const char* path = NULL;
	bool done = false;
	while (!done) {
		ALLEGRO_EVENT events;
		al_wait_for_event(this->event_queue, &events);
		if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			ALLEGRO_FILECHOOSER *filechooser;
			filechooser = al_create_native_file_dialog("C:", "Choose a file.", "*.*;*.jpg;", 0);
			al_show_native_file_dialog(this->myDisplay, filechooser);
			path = al_get_native_file_dialog_path(filechooser, 0);
			done = true;
		}
	}
	return path;
}