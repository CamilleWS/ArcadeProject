//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nathan.R Benjamin.R Camille.V [MPL - 2022]
//


#ifndef ALLEGRO_LIB
#define ALLEGRO_LIB

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string>
#include <iostream>

#include <unistd.h>
#include <map>
#include "interface.hpp"



class ALLEGRO: public IDisplayModule {
    private:
    void *_handle;
    std::string _name;
	std::string _pseudo;
	ALLEGRO_DISPLAY *_window;
	ALLEGRO_EVENT_QUEUE *_event_queue;
	std::chrono::time_point<std::chrono::system_clock>_clock;
	long double _elapsed;
	std::map<std::string, ALLEGRO_BITMAP*> _sprites;
	std::map<std::string, Arcade::Vector2f> _pos_sprites;
    public:
    std::string _gameName;
    ALLEGRO();
    ~ALLEGRO();

	void init();
	void stop();
	void *getHandle() const;
	void setHandle(void *handle);
	void setName(std::string handle);
	const std::string &getName() const;

	void clearWindow();
	void displayWindow();

	void drawRectangle(Arcade::Rectangle &rectangle);
    void drawCircle(Arcade::Circle &circle);
    void drawText(Arcade::Text &text);
	Arcade::Input coreInputs();

	void startClock();
	void setDeltaTime();
	const long double &getDeltaTime() const;
	std::string getPseudo() const;
	void setPseudo( const std::string str);
	int drawSprite(Arcade::Sprite);
	int whatLib() {
		return 0;
	}
};

#endif