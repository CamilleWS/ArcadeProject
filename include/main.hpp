//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nathan.R Benjamin.R Camille.V [MPL - 2022]
//



#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <dirent.h>
#include <vector>
#include <sys/types.h>
#include <unistd.h>
#include <ctime>
#include "IGameModule.hpp"


#ifndef _CORE_HPP_
#define _CORE_HPP_
#include "Arcade.hpp"

void print_usage();

class Core {

    public:
    IDisplayModule *_instance;
    IGameModule *_gameInstance;
    std::string _gameChosen;
    std::vector<std::string> _games;
    std::vector<std::string> _libs;
    Arcade::Input _val;
    bool _play;
    int _score;

    Core(IDisplayModule *instance):_instance(instance),_gameChosen(""), _val(Arcade::Input::None), _play(false), _score(0) {

        _games = list_game();
        _libs = list_lib();

    }
    ~Core(){}

    void setInstance(IDisplayModule * instance) {_instance = instance; }
    IDisplayModule *  getInstance() {return _instance; }
    void setGame(std::string str) {
        _gameChosen = str;
    }
    std::string  getGame() {return _gameChosen; }
    std::vector<std::string> getGamesList(){return _games;}
    std::vector<std::string> getLibsList(){return _libs;}
    std::vector<std::string> list_lib()
    {
        struct dirent *entry;
        std::string tmp;
        std::vector<std::string> res;
        DIR *dir = opendir("./lib");
    
        if (dir == NULL)
            return res;
        while ((entry = readdir(dir)) != NULL) {
            tmp =  entry->d_name;
            if (tmp.find("lib_arcade") == 0){
                tmp = "./lib/" + tmp;
                //std::cout << " [libraries]: "<< tmp << std::endl;
                res.push_back(tmp);
            }
        }
        closedir(dir);
        return res;
    }

    std::vector<std::string>  list_game()
    {
        struct dirent *entry;
        std::string tmp;
        std::vector<std::string> res;
        DIR *dir = opendir("./games");

        if (dir == NULL)
            return res;
        while ((entry = readdir(dir)) != NULL) {
            tmp =  entry->d_name;
            if (tmp.find("lib_arcade") == 0){
                tmp = "./games/" + tmp;
                //std::cout <<" [games]: "<< tmp << std::endl;
                res.push_back(tmp);
            }
        }
        closedir(dir);
        return res;
    }



        Core &operator=(Core other)
        {
            _instance = other._instance;
            _gameChosen = other._gameChosen;
            _games = other._games;
            _libs = other._libs;
            _val = other._val;
            _gameInstance = other._gameInstance;
            _play = other._play;
            _score = other._score;
            return *this;
        }

};

#endif



#ifndef _MENU_HPP_
#define _MENU_HPP_


class Menu {

    public:
    Arcade::Color colorW; //(255, 255, 255, 255, "White");
    Arcade::Color colorG; //(130, 230, 100, 255, "Green");
    Arcade::Color colorR; //(230, 130, 100, 255, "Red");
    Arcade::Color colorB; //(100, 130, 230, 255, "Blue");
    Arcade::Color colorBL; //(0, 0, 0, 0, "Black");
    std::vector<Arcade::Text> gameNames;
    std::vector<Arcade::Text> libNames;
	bool enterName;

    Arcade::Text titleAtcuLib;
    Arcade::Text theScore;
    Arcade::Text titleGames;
    Arcade::Text titleLibs;
    Arcade::Text selector;
    Arcade::Text pseudoName;

    Arcade::Rectangle bigRect;
    Arcade::Rectangle rect;

    std::string pseudo;

    Menu():colorW(255, 255, 255, 255, "White"),
            colorG(130, 230, 100, 255, "Green"),
            colorR(230, 130, 100, 255, "Red"),
            colorB(100, 130, 230, 255, "Blue"),
            colorBL(0, 0, 0, 0, "Black"), 
            enterName(false),
            titleAtcuLib( " ", colorW,    Arcade::Vector2f(550., 20.), (size_t)30),
            theScore( " ", colorW,    Arcade::Vector2f(480., 50.), (size_t)30),
            titleGames( "Choose Games:", colorW,    Arcade::Vector2f(150., 50.), (size_t)30),
            titleLibs( "Choose Lib:", colorW,    Arcade::Vector2f(850., 50.), (size_t)30),
            selector( "<0-", colorW,    Arcade::Vector2f(450., 100.), (size_t)30),
            pseudoName("", colorB, Arcade::Vector2f(510.,610.), (size_t)30),
            bigRect(Arcade::Vector2f(220.,70.),Arcade::Vector2f(490.,590.), colorW),
            rect(Arcade::Vector2f(200.,50.),Arcade::Vector2f(500.,600.),  colorBL)
            {
            }
    void drawTitle(IDisplayModule *instance) {
            instance->drawText(titleAtcuLib);
            instance->drawText(titleGames);
            instance->drawText(titleLibs);
            instance->drawText(theScore);
    }
    void drawOptionLib(IDisplayModule *instance) {
        for (unsigned int i = 0; i < libNames.size(); i++) {
            if (libNames.at(i).getString().find(instance->getName()) != std::string::npos)
                libNames.at(i).setColor(colorR);
            instance->drawText(libNames.at(i));
        }
    }
    void drawOptionGame(IDisplayModule *instance) {
        for (unsigned int i = 0; i < gameNames.size(); i++)
            instance->drawText(gameNames.at(i));
        if (enterName) {
            Arcade::Text txt("Pseudo", colorW, Arcade::Vector2f(570.,530.));
            instance->drawText(txt);
        }
        instance->setPseudo(pseudo);
    }
    void initMenu(std::vector<std::string> games, std::vector<std::string> libs) {
        for (unsigned int i = 0; i < games.size(); i++) {
            if (i > 0)  gameNames.push_back(Arcade::Text(games.at(i), colorW,    Arcade::Vector2f(50., 100. * (i+1))));
            else        gameNames.push_back(Arcade::Text(games.at(i), colorW,    Arcade::Vector2f(50., 100.)));
        }
        for (unsigned int i = 0; i < libs.size(); i++) {
            if (i > 0)  libNames.push_back(Arcade::Text(libs.at(i), colorW,    Arcade::Vector2f(750., 100. * (i+1))));
            else        libNames.push_back(Arcade::Text(libs.at(i), colorW,    Arcade::Vector2f(750., 100.)));
        }

    }

    std::string translateEnumToLetter(Arcade::Input val) {
        
        switch (val) {
            case Arcade::Input::Space: return " ";
            case Arcade::Input::Num0: return "0";
            case Arcade::Input::Num1: return "1";
            case Arcade::Input::Num2: return "2";
            case Arcade::Input::Num3: return "3";
            case Arcade::Input::Num4: return "4";
            case Arcade::Input::A: return "A";
            case Arcade::Input::Z: return "Z";
            case Arcade::Input::E: return "E";
            case Arcade::Input::R: return "R";
            case Arcade::Input::T: return "T";
            case Arcade::Input::Y: return "Y";
            case Arcade::Input::U: return "U";
            case Arcade::Input::I: return "I";
            case Arcade::Input::O: return "O";
            case Arcade::Input::P: return "P";
            case Arcade::Input::Q: return "Q";
            case Arcade::Input::S: return "S";
            case Arcade::Input::D: return "D";
            case Arcade::Input::F: return "F";
            case Arcade::Input::G: return "G";
            case Arcade::Input::H: return "H";
            case Arcade::Input::J: return "J";
            case Arcade::Input::K: return "K";
            case Arcade::Input::L: return "L";
            case Arcade::Input::M: return "M";
            case Arcade::Input::W: return "W";
            case Arcade::Input::X: return "X";
            case Arcade::Input::C: return "C";
            case Arcade::Input::V: return "V";
            case Arcade::Input::B: return "B";
            case Arcade::Input::N: return "N";
            default: return "";
        }
    }

    void setPseudo(Arcade::Input val) {
        if (enterName) {
            if (val == Arcade::Input::BackSpace && !pseudo.empty())
                pseudo.pop_back();
            if (pseudo.size() < 15)
                pseudo += translateEnumToLetter(val);
        }
        pseudoName.setString(pseudo);
    }

    void updateMenu(Arcade::Input val) {

            if (val == Arcade::Input::DOWN && selector.getPosition().y == (100*((int)gameNames.size())) && selector.getPosition().x == 450) {
                selector.setPosition(Arcade::Vector2f(600., 550.));
                selector.setString("v");
                bigRect.setColor(colorB);
                rect.setColor(colorW);
	            enterName = true;
            }

            if (val == Arcade::Input::DOWN && selector.getPosition().y == 100*((int)libNames.size()) && selector.getPosition().x == 650) {
                selector.setPosition(Arcade::Vector2f(600., 550.));
                selector.setString("v");
                bigRect.setColor(colorB);
                rect.setColor(colorW);
	            enterName = true;
            }
            

            if (val == Arcade::Input::UP && selector.getPosition().y > 100 && selector.getPosition().x != 600)
                selector.move(Arcade::Vector2f(0., -100.));
            if (val == Arcade::Input::DOWN && selector.getPosition().y < 100*((int)gameNames.size()) && selector.getPosition().x == 450)
                selector.move(Arcade::Vector2f(0., 100.));
            if (val == Arcade::Input::DOWN && selector.getPosition().y < 100*((int)libNames.size()) && selector.getPosition().x == 650)
                selector.move(Arcade::Vector2f(0., 100.));



            if ((val == Arcade::Input::UP && selector.getPosition().y == 550 && selector.getPosition().x == 600) || (val == Arcade::Input::Return && selector.getPosition().y == 550 && selector.getPosition().x == 600 )) {
                selector.setPosition(Arcade::Vector2f(450.,100.*((int)gameNames.size())));
                selector.setString("<0-");
                bigRect.setColor(colorW);
                rect.setColor(colorBL);
	            enterName = false;
                val =  Arcade::Input::None;
            }



            if (val == Arcade::Input::RIGHT && selector.getPosition().x < 650 && selector.getPosition().y != 550){
                selector.move(Arcade::Vector2f(200., 0.));
                selector.setString("-0>");
            }
            if (val == Arcade::Input::LEFT && selector.getPosition().x > 450 && selector.getPosition().y != 550){
                selector.move(Arcade::Vector2f(-200., 0.));
                selector.setString("<0-");
            }

            for (unsigned int i = 0; i < gameNames.size(); i++) {
                if (selector.getPosition().y == gameNames.at(i).getPosition().y && selector.getPosition().x == 450)
                    gameNames.at(i).setColor(colorG);
                else
                    gameNames.at(i).setColor(colorW);
                
            }

            for (unsigned int i = 0; i < libNames.size(); i++) {
                if (selector.getPosition().y == libNames.at(i).getPosition().y && selector.getPosition().x == 650)
                    libNames.at(i).setColor(colorG);
                else
                    libNames.at(i).setColor(colorW);
            }
    }


};


#endif
