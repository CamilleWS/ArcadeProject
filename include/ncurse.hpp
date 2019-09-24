//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nathan.R Benjamin.R Camille.V [MPL - 2022]
//


#ifndef NCURSE_LIB
#define NCURSE_LIB


#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

#include <unistd.h>
#include <ncurses.h>
#include "interface.hpp"



class NCURSE: public IDisplayModule {
    private:
    void *_handle;
    std::string _pseudo;
    std::chrono::time_point<std::chrono::system_clock> _clock;
    long double _elapsed;

    std::string _name;
    std::string _boardstr;
    std::vector<std::string> _board;
	std::vector<std::string> _circleColor;
    WINDOW *_window;
    WINDOW *_windowtext;
	std::map<char, std::string> _caracColor;
	std::vector<std::string> _str;
	std::vector<std::string> _strColor;
	std::vector<int> _strPosX;
    std::vector<int> _strPosY;
    std::vector<int> _strPosGiveY;


    public:
    NCURSE();
    ~NCURSE(){}

	void init();
	void stop();
	void *getHandle() const;
	void setHandle(void *handle);
	void setName(std::string handle);
	const std::string &getName() const;

	void clearWindow();
	void displayWindow();
	void eventManager();

	void drawRectangle(Arcade::Rectangle &rectangle);
	void drawCircle(Arcade::Circle &circle);
    void drawText(Arcade::Text &text);
    void intputMenu(Arcade::Input val);
    void updateMenu();
    void drawMenu();
	Arcade::Input coreInputs();

	void fillBoard();
	const long double &getDeltaTime() const;
	std::string getPseudo() const;
	void changeStrColor(int ic, std::vector<std::string> strColor, WINDOW *);
	void startClock();
	void setDeltaTime();

	void setPseudo( const std::string str);
	void setSprite(const std::string &name,  Arcade::Vector2f pos);
	int drawSprite(const std::string &name);
	const Arcade::Vector2f &getSpritePosition(const std::string &name);
	void setSpritePosition(const std::string &name, Arcade::Vector2f pos);

	int drawSprite(Arcade::Sprite);

    int whatLib() {
		return 0;
	}
};

#endif
