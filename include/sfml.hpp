//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nathan.R Benjamin.R Camille.V [MPL - 2022]
//


#ifndef SFML_LIB
#define SFML_LIB

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string>
#include <iostream>

#include <unistd.h>
#include "interface.hpp"

class SFML : public IDisplayModule {
    private:
    void *_handle;
    std::string _name;
    std::string _pseudo;
    sf::RenderWindow _window;
    std::chrono::time_point<std::chrono::system_clock> _clock;
    long double _elapsed;
    std::map<std::string, sf::Texture> _sprites;
    std::map<std::string, Arcade::Vector2f> _pos_sprites;
    public:
    SFML();

    ~SFML();

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

    void intputMenu(Arcade::Input val);

    void updateMenu();

    void drawMenu();

    Arcade::Input coreInputs();

    void startClock();

    void setDeltaTime();

    const long double &getDeltaTime() const;

    std::string getPseudo() const;

    void setPseudo(const std::string str);

    int drawSprite(Arcade::Sprite);

    int whatLib()
    {
        return 0;
    }
};

#endif