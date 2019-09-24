/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#ifndef _NIBBLER_HPP_
#define _NIBBLER_HPP_

#include <dlfcn.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "IGameModule.hpp"
#include "IDisplayModule.hpp"

class NIBBLER: public IGameModule {
    void *				_handle;
    std::string		 	_name;
public:
    std::string		 	_namePlayer;
	bool _moving;
	bool _dead;

	int 				_segment;
	Arcade::Input 		_val;

	Arcade::Color       _colorR;
	Arcade::Color       _colorG;
	Arcade::Color       _colorB;
	Arcade::Color       _colorC;
	Arcade::Color       _colorW;
	Arcade::Color       _colorM;
	Arcade::Color       _colorY;

    Arcade::Text        _txt;
    int 		        _score;

	Arcade::Rectangle   _rectUP;
    Arcade::Rectangle   _rectDOWN;
    Arcade::Rectangle   _rectRIGHT;
    Arcade::Rectangle   _rectLEFT;

	Arcade::Rectangle   _rectMIDx;
	Arcade::Rectangle   _rectMIDy;
	Arcade::Rectangle   _rectMIDz;


	Arcade::Vector2f	_posSnake;
	Arcade::Circle		_snake;
	
	Arcade::Vector2f	_posFood;
	Arcade::Circle		_food;

	std::vector<Arcade::Vector2f>	_posBody;
	std::vector<Arcade::Circle>	_body;
	bool _alreadyDead;
	int _dies;
	int direction;
	int _hsc;



	 NIBBLER();
	 ~NIBBLER();


	 void init();
	 void stop();
	 void *getHandle() const;
	 void setHandle(void *handle);
	 void setName(std::string handle);
	 const std::string &getName() const;
	 void updateInput(Arcade::Input &input);
	 int updateGame(IDisplayModule *_Dinstance);
	 void drawGame(IDisplayModule *_Dinstance);
	 void replay();

	 void drawWall(IDisplayModule *);
	 void drawText(IDisplayModule *);
	 void collisionWall();
	 void foodWall();
	 void snakeCollision();
	 void moveBodySnake();
	 Arcade::Vector2f find_pos();
	int whatLib() {
		return 1;
	}

};

#endif
