//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nathan.R Benjamin.R Camille.V [MPL - 2022]
//

#include <iostream>
#include <dirent.h>
#include <vector>
#include <sys/types.h>
#include <unistd.h>
#include <ctime>
#include "../../include/solarfox.hpp"

IGameModule *mod = nullptr;

int gamecheck;

extern "C" {
IGameModule *entryPoint()
{
    return mod;
}
}

__attribute__((constructor))
void constructor()
{
    mod = new SOLAR_FOX;
}

__attribute__((destructor))
void destructor()
{
    delete mod;
}

SOLAR_FOX::SOLAR_FOX() : _namePlayer("Anomyme"), _dead(false), _segment(20),
    _val(Arcade::Input::None), _colorR(230, 130, 100, 255, "Red"),
    _colorG(130, 230, 100, 255, "Green"), _colorB(100, 130, 230, 255, "Blue"),
    _colorC(0, 206, 209, 255, "Cyan"), _colorW(255, 255, 255, 255, "White"),
    _colorM(238, 130, 238, 255, "Magenta"),//rgb(255,215,0)
    _colorY(255, 215, 0, 255, "Yellow"), _score(0),
    _txt("SOLAR_FOX", _colorW, Arcade::Vector2f(55, 10)),
    _rectUP(Arcade::Vector2f(_segment * 42, _segment),
        Arcade::Vector2f(_segment * 3, _segment * 3), _colorW),
    _rectDOWN(Arcade::Vector2f(_segment * 42, _segment),
        Arcade::Vector2f(_segment * 3, _segment * 45), _colorW),
    _rectLEFT(Arcade::Vector2f(_segment, _segment * 43),
        Arcade::Vector2f(_segment * 3, _segment * 3), _colorW),
    _rectRIGHT(Arcade::Vector2f(_segment, _segment * 43),
        Arcade::Vector2f(_segment * 45, _segment * 3), _colorW),

    _enemyLEFT(Arcade::Vector2f(40, 40),
        Arcade::Vector2f(_segment * 2 + 10, _segment * 32 / 2), _colorR),
    _LmissilR(Arcade::Vector2f(30, 10),
        Arcade::Vector2f(_enemyLEFT.getPosition().x,
            _enemyLEFT.getPosition().y), _colorR),
    _enemyUP(Arcade::Vector2f(40, 40),
        Arcade::Vector2f(_segment * 32 / 2, _segment * 2 + 10), _colorR),
    _UmissilR(Arcade::Vector2f(10, 30),
        Arcade::Vector2f(_enemyUP.getPosition().x, _enemyUP.getPosition().y),
        _colorR),

    ship(Arcade::Vector2f(_segment * 2, _segment * 2),
        Arcade::Vector2f(_segment * 38 / 2, _segment * 38 / 2), _colorW),

    _moving(true), _shot(Arcade::Vector2f(10, 30),
        Arcade::Vector2f(ship.getPosition().x + ship.getSize().x / 2,
            ship.getPosition().y + ship.getSize().y / 2), _colorB),
    winner(false)
{

    for (int i = _segment * 8; i <= _segment * 40; i += _segment * 4) {
        for (int j = _segment * 8; j <= _segment * 40; j += _segment * 4) {
            if (!(j > _segment * 38 / 2 - _segment * 3 &&
                j < _segment * 39 / 2 + _segment * 3 &&
                i > _segment * 38 / 2 - _segment * 3 &&
                i < _segment * 38 / 2 + _segment * 3))
                food.push_back(
                    Arcade::Circle(_segment / 2, Arcade::Vector2f(i, j),
                        _colorY));
        }
    }
}

SOLAR_FOX::~SOLAR_FOX()
{
}

void SOLAR_FOX::init()
{
    std::srand(std::time(nullptr));
}

void SOLAR_FOX::stop()
{
}

void *SOLAR_FOX::getHandle() const
{
    return _handle;
}

void SOLAR_FOX::setHandle(void *handle)
{
    _handle = handle;
}

void SOLAR_FOX::setName(std::string handle)
{
    _name = handle;
}

const std::string &SOLAR_FOX::getName() const
{
    return _name;
}

void SOLAR_FOX::updateInput(Arcade::Input &input)
{                    /////////////////////////////// Gestion Inputs ///////////////////////////////
    //_moving = false;

    if (input != Arcade::Input::None)
        _val = input;

    if (!_dead) {
    }
    ////////////////////////////////////////////////////////////////////////////////

}

//////////////////////////////////////////////   WALLS   //////////////////////////////////////////////////////////

void SOLAR_FOX::collisionWall()
{
    ////////////////// Collision Sides Map /////////////////////////

    //////////////////////////////////////////////////////////////////
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////  Food  /////////////////////////////////////////////////////

void SOLAR_FOX::foodWall()
{
    //////////////////////////////////////// Collision Food //////////////////////////////////////////////////
    for (int i = 0; i < food.size(); i++) {
        if (ship.getPosition().x > food.at(i).getPosition().x - _segment * 2 &&
            ship.getPosition().x < food.at(i).getPosition().x + _segment * 2) {
            if (ship.getPosition().y >
                food.at(i).getPosition().y - _segment * 2 &&
                ship.getPosition().y <
                    food.at(i).getPosition().y + _segment * 2) {
                food.erase(food.begin() + i);
                _score++;
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

//////////////////////////////////////////////////////////////////////////////////////////

void SOLAR_FOX::snakeCollision()
{
    /////////////////////////////////////////// Snake Self Collision ////////////////////////////////////////////
    // if(_moving) {

    // }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void SOLAR_FOX::moveEnemy()
{
    static bool left = false;
    static bool up = true;
    static bool shotL = false;
    static bool shotU = false;
    static int i = 0;

    if (!left &&
        _enemyUP.getPosition().x + _segment < _rectRIGHT.getPosition().x)
        _enemyUP.move(Arcade::Vector2f(_segment, 0));
    if (_enemyUP.getPosition().x + _segment == _rectRIGHT.getPosition().x)
        left = true;
    if (left == true && i % 2 == 0)
        _enemyUP.move(Arcade::Vector2f(-_segment, 0));
    if (_enemyUP.getPosition().x == _rectLEFT.getPosition().x + _segment)
        left = false;

    if (up &&
        _enemyLEFT.getPosition().y + _segment < _rectDOWN.getPosition().y &&
        i % 2 == 0)
        _enemyLEFT.move(Arcade::Vector2f(0, _segment));
    if (_enemyLEFT.getPosition().y + _segment == _rectDOWN.getPosition().y)
        up = false;
    if (!up)
        _enemyLEFT.move(Arcade::Vector2f(0, -_segment));
    if (_enemyLEFT.getPosition().y == _rectUP.getPosition().y + _segment)
        up = true;

    if (!shotL) {
        _LmissilR.setPosition(Arcade::Vector2f(_enemyLEFT.getPosition().x,
            _enemyLEFT.getPosition().y));
    } else {
        _LmissilR.move(Arcade::Vector2f(_segment * 2, 0));
    }
    if (!shotU) {
        _UmissilR.setPosition(Arcade::Vector2f(_enemyUP.getPosition().x,
            _enemyUP.getPosition().y));
    } else {
        _UmissilR.move(Arcade::Vector2f(0, _segment * 2));
    }

    int travers = 18;

    if (i == 0)
        shotL = true;
    if (i == travers)
        shotL = false;
    if (i == travers / 2)
        shotU = true;
    if (i == travers / 2 + travers)
        shotU = false;

    if (i == travers * 2)
        shotL = true;
    if (i == travers * 3)
        shotL = false;
    if (i == travers / 2 + travers * 2)
        shotU = true;
    if (i == travers / 2 + travers * 3)
        shotU = false;

    if (i == travers * 4)
        shotL = true;
    if (i == travers * 5)
        shotL = false;
    if (i == travers / 2 + travers * 4)
        shotU = true;
    if (i == travers / 2 + travers * 5)
        shotU = false;

    if (i == travers * 6)
        shotL = true;
    if (i == travers * 6)
        shotL = false;
    if (i == travers / 2 + travers * 6)
        shotU = true;
    if (i == travers / 2 + travers * 7)
        shotU = false;

    i++;
    if (i == 80)
        i = 0;

    if (ship.getPosition().x <= _UmissilR.getPosition().x + _segment &&
        ship.getPosition().x >= _UmissilR.getPosition().x - _segment) {
        if (ship.getPosition().y <= _UmissilR.getPosition().y + _segment &&
            ship.getPosition().y >= _UmissilR.getPosition().y - _segment) {
            shotU = false;
            ship.setColor(_colorR);
            _dead = true;
        }
    }
    if (ship.getPosition().x <= _LmissilR.getPosition().x + _segment &&
        ship.getPosition().x >= _LmissilR.getPosition().x - _segment) {
        if (ship.getPosition().y <= _LmissilR.getPosition().y + _segment &&
            ship.getPosition().y >= _LmissilR.getPosition().y - _segment) {
            shotL = false;
            ship.setColor(_colorR);
            _dead = true;
        }
    }

    if (_shot.getPosition().x <= _UmissilR.getPosition().x + _segment &&
        _shot.getPosition().x >= _UmissilR.getPosition().x - _segment) {
        if (_shot.getPosition().y <= _UmissilR.getPosition().y + _segment &&
            _shot.getPosition().y >= _UmissilR.getPosition().y - _segment) {
            shotU = false;
            _shot.setColor(_colorR);
        }
    }
    if (_shot.getPosition().x <= _LmissilR.getPosition().x + _segment &&
        _shot.getPosition().x >= _LmissilR.getPosition().x - _segment) {
        if (_shot.getPosition().y <= _LmissilR.getPosition().y + _segment &&
            _shot.getPosition().y >= _LmissilR.getPosition().y - _segment) {
            shotL = false;
            _shot.setColor(_colorR);
        }
    }
}

std::vector<Arcade::Vector2f> SOLAR_FOX::movementVector()
{
    std::vector<Arcade::Vector2f> movement;
    int _segment = 20;
    movement.push_back(Arcade::Vector2f(-10, 0));
    movement.push_back(Arcade::Vector2f(10, 0));
    movement.push_back(Arcade::Vector2f(0, -10));
    movement.push_back(Arcade::Vector2f(0, 10));
    return movement;
}

std::vector<Arcade::Vector2f> fillCadrill()
{
    std::vector<Arcade::Vector2f> cadril;

    for (float i = 150; i <= 790; i += 80) {
        for (float j = 150; j <= 790; j += 80) {
            cadril.push_back(Arcade::Vector2f(i, j));
        }
    }
    return cadril;
}

void SOLAR_FOX::shot(bool pool, Arcade::Vector2f pos_shot_begin,
    int shot_direction
)
{

    for (int i = 0; i < food.size(); i++) {
        if (_shot.getPosition().x > food.at(i).getPosition().x - _segment * 2 &&
            _shot.getPosition().x < food.at(i).getPosition().x + _segment * 2) {
            if (_shot.getPosition().y >
                food.at(i).getPosition().y - _segment * 2 &&
                _shot.getPosition().y <
                    food.at(i).getPosition().y + _segment * 2) {
                food.erase(food.begin() + i);
                _score++;
            }
        }
    }
}

void SOLAR_FOX::moveShip()
{
    std::vector<Arcade::Vector2f> cadril = fillCadrill();
    static Arcade::Input tmp = Arcade::Input::None;
    static int direction;
    static int shot_direction;
    static bool pool = false;
    static Arcade::Vector2f pos_shot_begin;

    if (_moving) {
        if (direction == 0 && ship.getPosition().x > cadril.at(0).x ||
            direction == 1 &&
                ship.getPosition().x < cadril.at(cadril.size() - 1).x ||
            direction == 2 && ship.getPosition().y > cadril.at(0).y ||
            direction == 3 &&
                ship.getPosition().y < cadril.at(cadril.size() - 1).y)
            ship.move(movementVector().at(direction));
    }

    if (pool) {
        _shot.move(Arcade::Vector2f(movementVector().at(shot_direction).x * 3,
            movementVector().at(shot_direction).y * 3));
        if (_shot.getPosition().x >= pos_shot_begin.x + 80 * 2 ||
            _shot.getPosition().y >= pos_shot_begin.y + 80 * 2 ||
            _shot.getPosition().x <= pos_shot_begin.x - 80 * 2 ||
            _shot.getPosition().y <= pos_shot_begin.y - 80 * 2)
            pool = false;
        if (_shot.getColor().r == _colorR.r &&
            _shot.getColor().g == _colorR.g && _shot.getColor().b == _colorR.b)
            pool = false;
    } else {
        _shot.setPosition(
            Arcade::Vector2f(ship.getPosition().x + ship.getSize().x / 2,
                ship.getPosition().y + ship.getSize().y / 2));
        _shot.setSize(Arcade::Vector2f(10, 10));
        _shot.setColor(_colorB);
    }

    shot(pool, pos_shot_begin, shot_direction);

    switch (_val) {
    case Arcade::Input::LEFT:
        for (int i = 0; i < cadril.size(); i++) {
            if (ship.getPosition().y == cadril.at(i).y) {
                //  printf("x = %f   y = %f\nx = %f   y = %f\n\n\n\n",ship.getPosition().x  , ship.getPosition().y ,cadril.at(i).x, cadril.at(i).y);
                if (direction != 1) {
                    direction = 0;
                    _moving = true;
                }

                tmp = _val;
            }
        }
        break;
    case Arcade::Input::RIGHT:

        for (int i = 0; i < cadril.size(); i++) {
            if (ship.getPosition().y == cadril.at(i).y) {
                //   printf("x = %f   y = %f\nx = %f   y = %f\n\n\n\n",ship.getPosition().x  , ship.getPosition().y ,cadril.at(i).x, cadril.at(i).y);
                if (direction != 0) {
                    direction = 1;
                    _moving = true;
                }
                tmp = _val;
            }
        }
        break;

    case Arcade::Input::UP:

        for (int i = 0; i < cadril.size(); i++) {
            if (ship.getPosition().x == cadril.at(i).x) {
                ///  printf("x = %f   y = %f\nx = %f   y = %f\n\n\n\n",ship.getPosition().x  , ship.getPosition().y ,cadril.at(i).x, cadril.at(i).y);
                if (direction != 3) {
                    direction = 2;
                    _moving = true;
                }
                tmp = _val;
            }
        }
        break;
    case Arcade::Input::DOWN:
        for (int i = 0; i < cadril.size(); i++) {
            if (ship.getPosition().x == cadril.at(i).x) {
                //  printf("x = %f   y = %f\nx = %f   y = %f\n\n\n\n",ship.getPosition().x  , ship.getPosition().y ,cadril.at(i).x, cadril.at(i).y);
                if (direction != 2) {
                    direction = 3;
                    _moving = true;
                }
                tmp = _val;
            }
        }
        break;
    case Arcade::Input::Space:
        pool = true;

        if (direction >= 2)
            _shot.setSize(Arcade::Vector2f(10, 30));
        else
            _shot.setSize(Arcade::Vector2f(30, 10));
        shot_direction = direction;
        pos_shot_begin = ship.getPosition();
        _val = Arcade::Input::None;
        break;

    default:
        break;
    }
}

// 150    150
// 790    790
// 80

int SOLAR_FOX::updateGame(IDisplayModule *_Dinstance)
{
    static double long sec = 0;
    double long ti = _Dinstance->getDeltaTime();
    sec += ti / 10000.0;

    if (sec > 9.) {
        sec = 0.0;
        if (food.size() == 0)
            winner = true;
        else {
            moveEnemy();
            moveShip();
            foodWall();
        }
    }

    if (_val == Arcade::Input::R)
        replay();
    if (_val == Arcade::Input::Escape || _val == Arcade::Input::M)
        _dead = true;

    if (!_dead)
        return -1;
    return _score;
}

void SOLAR_FOX::drawWall(IDisplayModule *instance)
{
    instance->drawRectangle(_rectUP);
    instance->drawRectangle(_rectDOWN);
    instance->drawRectangle(_rectRIGHT);
    instance->drawRectangle(_rectLEFT);
}

void SOLAR_FOX::drawText(IDisplayModule *instance)
{
    std::string Score = std::to_string(_score);

    Arcade::Text pseudoT("Player: ", _colorW,
        Arcade::Vector2f(_segment * 47 - _segment / 2, 100));
    Arcade::Text pseudoN(instance->getPseudo(), _colorM,
        Arcade::Vector2f(_segment * 47 - _segment / 2, 130));
    Arcade::Text score("Actual score: " + Score + " / 80", _colorW,
        Arcade::Vector2f(_segment * 47, 200));

    Arcade::Text tips("TIPS:", _colorW, Arcade::Vector2f(_segment * 47, 300));
    Arcade::Text tipsR("R: replay.", _colorW,
        Arcade::Vector2f(_segment * 48 - _segment / 2, 325));
    Arcade::Text tipsM("M: return to menu.", _colorW,
        Arcade::Vector2f(_segment * 48 - _segment / 2, 350));

    instance->drawText(_txt);
    instance->drawText(score);
    instance->drawText(pseudoT);
    instance->drawText(pseudoN);
    instance->drawText(tips);
    instance->drawText(tipsR);
    instance->drawText(tipsM);
}

void SOLAR_FOX::drawEnemy(IDisplayModule *instance)
{

    instance->drawRectangle(_enemyLEFT);
    instance->drawRectangle(_LmissilR);
    instance->drawRectangle(_enemyUP);
    instance->drawRectangle(_UmissilR);
}

void SOLAR_FOX::drawGame(IDisplayModule *instance)
{

    drawText(instance);
    drawWall(instance);
    if (!winner) {
        drawEnemy(instance);

        for (size_t i = 0; i < food.size(); i++)
            instance->drawCircle(food.at(i));

        instance->drawRectangle(_shot);
        instance->drawRectangle(ship);
    } else {

        Arcade::Text end(" You Win !!!", _colorG,
            Arcade::Vector2f(_segment * 20, _segment * 20));

        instance->drawText(end);
    }
}

void SOLAR_FOX::replay()
{

    _name = "SOLAR_FOX";
    _val = Arcade::Input::None;
    for (int i = _segment * 8; i <= _segment * 40; i += _segment * 4) {
        for (int j = _segment * 8; j <= _segment * 40; j += _segment * 4) {
            if (!(j > _segment * 38 / 2 - _segment * 4 &&
                j < _segment * 39 / 2 + _segment * 4 &&
                i > _segment * 38 / 2 - _segment * 4 &&
                i < _segment * 38 / 2 + _segment * 4))
                food.push_back(
                    Arcade::Circle(_segment / 2, Arcade::Vector2f(i, j),
                        _colorY));
        }
    }
    ship.setPosition(Arcade::Vector2f(_segment * 38 / 2, _segment * 38 / 2));
    _score = 0;
    winner = false;
}
