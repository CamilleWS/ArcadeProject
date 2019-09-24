/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#ifndef _IDisplayModule_HPP_
#define _IDisplayModule_HPP_

#include <dlfcn.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Arcade.hpp"

class IDisplayModule {
public:
	virtual ~IDisplayModule() = default;

	virtual void init() = 0;
	virtual void stop() = 0;
	virtual void *getHandle() const = 0;
	virtual void setHandle(void *handle) = 0;
	virtual void setName(std::string handle) = 0;
	virtual const std::string &getName() const = 0;

	virtual void clearWindow() = 0;
	virtual void displayWindow() = 0;

	virtual void drawRectangle(Arcade::Rectangle &rectangle) = 0;
    virtual void drawCircle(Arcade::Circle &circle) = 0;
    virtual void drawText(Arcade::Text &text) = 0;
	virtual Arcade::Input coreInputs() = 0;


	virtual void startClock() = 0;
	virtual void setDeltaTime() = 0;
	virtual const long double &getDeltaTime() const = 0;
	virtual std::string getPseudo() const  = 0;
	virtual void setPseudo( const std::string ) = 0;
	virtual int drawSprite(Arcade::Sprite) = 0;
    virtual int whatLib() = 0;
};

#endif
