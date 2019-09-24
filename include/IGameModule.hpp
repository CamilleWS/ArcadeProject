/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#ifndef _IGameModule_HPP_
#define _IGameModule_HPP_

#include <dlfcn.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "IDisplayModule.hpp"


class IGameModule {
public:
    virtual ~IGameModule() = default;


    virtual void init() = 0;
    virtual void stop() = 0;
    virtual void *getHandle() const = 0;
    virtual void setHandle(void *handle) = 0;
    virtual void setName(std::string handle) = 0;
    virtual const std::string &getName() const = 0;
    virtual void updateInput(Arcade::Input &input) = 0;
    virtual int updateGame(IDisplayModule *_Dinstance) = 0;
    virtual void drawGame(IDisplayModule *_Dinstance) = 0;
    virtual int whatLib() = 0;
};

#endif
