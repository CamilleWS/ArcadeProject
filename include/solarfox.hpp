/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#ifndef _SOLAR_FOX_HPP_
#define _SOLAR_FOX_HPP_

#include <dlfcn.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "IGameModule.hpp"
#include "IDisplayModule.hpp"

class SOLAR_FOX: public IGameModule {
    void *				_handle;
    std::string		 	_name;
public:
    std::string _namePlayer;
	int _segment;
	bool _dead;
	Arcade::Input _val;
	Arcade::Color _colorR;
	Arcade::Color _colorG;
	Arcade::Color _colorB;
	Arcade::Color _colorC;
	Arcade::Color _colorW;
	Arcade::Color _colorM;
	Arcade::Color _colorY;
	int _score;
	Arcade::Text _txt;
	Arcade::Rectangle _rectUP;
	Arcade::Rectangle _rectDOWN;
	Arcade::Rectangle _rectRIGHT;
	Arcade::Rectangle _rectLEFT;

	
	Arcade::Rectangle _enemyLEFT;
    Arcade::Rectangle _LmissilR;

	Arcade::Rectangle _enemyUP;
	Arcade::Rectangle _UmissilR;

	std::vector<Arcade::Circle> food;

	Arcade::Rectangle ship;


    bool _moving;

	Arcade::Rectangle _shot;
	bool winner;





	 SOLAR_FOX();
	 ~SOLAR_FOX();


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
	 void movingEnemy();

	 void drawWall(IDisplayModule *);
	 void drawText(IDisplayModule *);
	 void drawEnemy(IDisplayModule *);
	 void moveEnemy();
	 void moveShip();
	 std::vector<Arcade::Vector2f> movementVector();
	 void shot(bool pool, Arcade::Vector2f pos_shot_begin, int shot_direction);

	 void collisionWall();
	 void foodWall();
	 void snakeCollision();
	int whatLib() {
		return 1;
	}
};

#endif
