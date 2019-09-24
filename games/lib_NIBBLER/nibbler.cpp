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
#include "../../include/nibbler.hpp"



IGameModule *mod = nullptr;
int gamecheck;

extern "C"
{
	IGameModule *entryPoint()
	{
    	return mod;
	}

}

__attribute__((constructor))
void constructor()
{
	mod = new NIBBLER;
}


__attribute__((destructor))
void destructor()
{
	delete mod;
}


NIBBLER::NIBBLER(): _namePlayer("Anomyme"),
                    _moving(false),
                    _dead(false),
                    _name("NIBBLER"),
                    _segment(20),
                    _val(Arcade::Input::None),
                    _colorR(230, 130, 100, 255, "Red"),
                    _colorG(130, 230, 100, 255, "Green"),
                    _colorB(100, 130, 230, 255, "Blue"),
                    _colorC(0  , 206, 209, 255, "Cyan"),
                    _colorW(255, 255, 255, 255, "White"),
                    _colorM(238, 130, 238, 255, "Magenta"),//rgb(255,215,0)
                    _colorY(255,215,0, 255, "Yellow"),
                    _score(4),
                    _txt("Nibbler", _colorW,    Arcade::Vector2f(55,10)),
                    _rectUP(Arcade::Vector2f(_segment * 42,_segment),       Arcade::Vector2f(_segment * 3,_segment * 3),    _colorW),
                    _rectDOWN(Arcade::Vector2f(_segment * 42,_segment),     Arcade::Vector2f(_segment * 3,_segment * 45),   _colorW),
                    _rectRIGHT(Arcade::Vector2f(_segment , _segment * 43),  Arcade::Vector2f(_segment * 3,_segment * 3),    _colorW),
                    _rectLEFT(Arcade::Vector2f(_segment , _segment * 43),   Arcade::Vector2f(_segment * 45,_segment * 3),   _colorW),
                    _rectMIDx(Arcade::Vector2f(_segment * 16, _segment),    Arcade::Vector2f(_segment * 30,_segment * 25),  _colorW),
                    _rectMIDy(Arcade::Vector2f(_segment, _segment*16),      Arcade::Vector2f(_segment * 16,_segment * 30),  _colorW),
                    _rectMIDz(Arcade::Vector2f(_segment*14, _segment),      Arcade::Vector2f(_segment * 3, _segment * 17),  _colorW),
                    _posSnake(_segment * 10,_segment * 25),
                    _snake(20, _posSnake, _colorY),
                    _posFood(_segment * 40 + 10,_segment * 35 + 10),
                    _food(10, _posFood, _colorM),
                    _alreadyDead(false),
                    _dies(0),
                    direction(0),
                    _hsc(0)
{

	_posBody.push_back(Arcade::Vector2f(_posSnake.x, _posSnake.y));
	_posBody.push_back(Arcade::Vector2f(_posSnake.x, _posSnake.y));
	_posBody.push_back(Arcade::Vector2f(_posSnake.x, _posSnake.y));
	_posBody.push_back(Arcade::Vector2f(_posSnake.x, _posSnake.y));
	_posBody.push_back(Arcade::Vector2f(_posSnake.x, _posSnake.y));
	Arcade::Circle	body(20, _posBody.at(0), _colorB);
	_body.push_back(body);
	_body.push_back(body);
	_body.push_back(body);
	_body.push_back(body);
	_body.push_back(body);
}

NIBBLER::~NIBBLER()
{
}
void NIBBLER::init()
{
    std::srand(std::time(nullptr));
}

void NIBBLER::stop()
{
    _alreadyDead = true;
    _dies++;
}

void *NIBBLER::getHandle() const
{
    return _handle;
}

void NIBBLER::setHandle(void *handle)
{
    _handle = handle;
}

void NIBBLER::setName(std::string handle)
{
    _name = handle;
}

const std::string &NIBBLER::getName() const
{
    return _name;
}

std::vector<Arcade::Vector2f> movementVector()
{
    std::vector<Arcade::Vector2f> movement;
    int _segment = 20;
    movement.push_back(Arcade::Vector2f(_segment*2, 0));
    movement.push_back(Arcade::Vector2f(0, -_segment*2));
    movement.push_back(Arcade::Vector2f(-_segment*2, 0));
    movement.push_back(Arcade::Vector2f(0, _segment*2));
    return movement;
}


void NIBBLER::updateInput(Arcade::Input &input)
{                    /////////////////////////////// Gestion Inputs ///////////////////////////////
    //_moving = false;

    if (input != Arcade::Input::None)  _val = input;

    if (!_dead) {

/*
        if (_val == Arcade::Input::LEFT) {

            _snake.move(Arcade::Vector2f(-_segment*2, 0));
            _posBody.push_back(_snake.getPosition());
            _val = Arcade::Input::None;
        }

        if (_val == Arcade::Input::RIGHT) {

            _snake.move(Arcade::Vector2f(_segment*2, 0));
            _posBody.push_back(_snake.getPosition());
            _val = Arcade::Input::None;
        }


        if (_val == Arcade::Input::DOWN) {

            _snake.move(Arcade::Vector2f(0, _segment*2));
            _posBody.push_back(_snake.getPosition());
            _val = Arcade::Input::None;
        }
        if (_val == Arcade::Input::UP) {

            _snake.move(Arcade::Vector2f(0, -_segment*2));
            _posBody.push_back(_snake.getPosition());
            _val = Arcade::Input::None;
        }

        */


        if (_val == Arcade::Input::LEFT) {
            _val = Arcade::Input::None;
            //printf("direction avant de tourner à gauche %d\n", direction);
            direction++;
            //printf("direction [intermédiaire] avant de tourner à gauche %d\n", direction);
            if (direction >= 4)
                direction = 0;
            //printf("direction pour tourner à gauche %d\n", direction);
             _moving = true;
        }
        if (_val == Arcade::Input::RIGHT) {
            _val = Arcade::Input::None;
            //printf("direction avant de tourner à droite %d\n", direction);
            direction--;
            //printf("direction [intermédiaire] avant de tourner à droite %d\n", direction);
            if (direction < 0)
                direction = 3;
            //printf("direction pour tourner à droite %d\n", direction);
             _moving = true;
        }
   
    }
     if (_val == Arcade::Input::R) {
        _dies = 0;
        replay();
     }
     if (_val == Arcade::Input::Escape || _val == Arcade::Input::M)
        _dead = true;
    ////////////////////////////////////////////////////////////////////////////////

}

Arcade::Vector2f NIBBLER::find_pos()
{

    float pos_x = (std::rand()%_segment*42) + _segment * 4;
    float pos_y = (std::rand()%_segment*42) + _segment * 4;
/*
    if ((pos_y >= _rectMIDx.getPosition().y-_segment && pos_y <= _rectMIDx.getPosition().y + _rectMIDx.getSize().y - _segment
            && pos_x >= _rectMIDx.getPosition().x-_segment && pos_x <= _rectMIDx.getPosition().x + _rectMIDx.getSize().x)
            || (pos_y >= _rectMIDy.getPosition().y-_segment && pos_y <= _rectMIDy.getPosition().y + _rectMIDy.getSize().y
            && pos_x >= _rectMIDy.getPosition().x-_segment && pos_x <= _rectMIDy.getPosition().x-_segment + _rectMIDy.getSize().x)
            || (pos_y >= _rectMIDz.getPosition().y-_segment && pos_y <= _rectMIDz.getPosition().y + _rectMIDz.getSize().y-_segment
            && pos_x >= _rectMIDz.getPosition().x && pos_x <= _rectMIDz.getPosition().x + _rectMIDz.getSize().x-_segment)
            || (_snake.getPosition().y >= _segment*45 - _segment || _snake.getPosition().y <= _segment * 3 )
            || (_snake.getPosition().x >= _segment*45 - _segment || _snake.getPosition().x <= _segment * 3 ) ){
                printf("Aïe !! \n");
            pos_x = (std::rand()%_segment*42) + _segment * 4;
            pos_y = (std::rand()%_segment*42) + _segment * 4;
    }
    */

    return Arcade::Vector2f(pos_x, pos_y);
}

//////////////////////////////////////////////   WALLS   //////////////////////////////////////////////////////////

void NIBBLER::collisionWall()
{
    ////////////////// Collision Sides Map /////////////////////////
    if (_snake.getPosition().y >= _segment*45 - _segment || _snake.getPosition().y <= _segment * 3 ){
        stop();
        replay();
    }
    if (_snake.getPosition().x >= _segment*45 - _segment || _snake.getPosition().x <= _segment * 3 ){
        stop();
        replay();
    }
    ////////////////////////////////////////////////////////////////

    ////////////////// Collision Obstacles /////////////////////////
    if (_snake.getPosition().y >= _rectMIDx.getPosition().y-_segment && _snake.getPosition().y <= _rectMIDx.getPosition().y + _rectMIDx.getSize().y - _segment) {
        if (_snake.getPosition().x >= _rectMIDx.getPosition().x-_segment && _snake.getPosition().x <= _rectMIDx.getPosition().x + _rectMIDx.getSize().x){
            stop();
            replay();
        }
    }
    if (_snake.getPosition().y >= _rectMIDy.getPosition().y-_segment && _snake.getPosition().y <= _rectMIDy.getPosition().y + _rectMIDy.getSize().y) {
        if (_snake.getPosition().x >= _rectMIDy.getPosition().x-_segment && _snake.getPosition().x <= _rectMIDy.getPosition().x-_segment + _rectMIDy.getSize().x){
            stop();
            replay();
        }
    }
    if (_snake.getPosition().y >= _rectMIDz.getPosition().y-_segment && _snake.getPosition().y <= _rectMIDz.getPosition().y + _rectMIDz.getSize().y-_segment) {
        if (_snake.getPosition().x >= _rectMIDz.getPosition().x && _snake.getPosition().x <= _rectMIDz.getPosition().x + _rectMIDz.getSize().x-_segment){
            stop();
            replay();
        }
    }
    //////////////////////////////////////////////////////////////////
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////  Food  /////////////////////////////////////////////////////

void NIBBLER::foodWall()
{
    //////////////////////////////////////// Collision Food //////////////////////////////////////////////////
    if (_snake.getPosition().y >= _food.getPosition().y-_segment*2 && _snake.getPosition().y <= _food.getPosition().y + _segment) {
        if (_snake.getPosition().x >= _food.getPosition().x-_segment*2 && _snake.getPosition().x <= _food.getPosition().x+_segment){
            _snake.setColor(_colorG);
            _score++;

            _food.setPosition(find_pos());
            _body.push_back(Arcade::Circle(20, Arcade::Vector2f(_posBody.at(_posBody.size()-2).x, _posBody.at(_posBody.size()-2).y), _colorB));
            // printf("%d\n", _body.size());
            
        } else
            _snake.setColor(_colorY);
    } else
            _snake.setColor(_colorY);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

}

//////////////////////////////////////////////////////////////////////////////////////////

void NIBBLER::snakeCollision()
{
    /////////////////////////////////////////// Snake Self Collision ////////////////////////////////////////////
    if(_moving) {
        for (unsigned int i = 1;i < _body.size(); i++) {
            if (_snake.getPosition().y == _body.at(i).getPosition().y &&  _snake.getPosition().y == _body.at(i).getPosition().y  ) {
                if (_snake.getPosition().x == _body.at(i).getPosition().x  && _snake.getPosition().x == _body.at(i).getPosition().x  ){
                    stop();
                    replay();
                }
            }
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void NIBBLER::moveBodySnake()
{
    _snake.move(movementVector().at(direction));
    _posBody.push_back(_snake.getPosition());

    for (unsigned int i = 0; i < _body.size(); i++){
        if (i == 0)
            _body.at(i).setPosition(Arcade::Vector2f(_posBody.at(_posBody.size()-1).x, _posBody.at(_posBody.size()-1).y));
        else
            _body.at(i).setPosition(Arcade::Vector2f(_posBody.at(_posBody.size()-(i+1)).x, _posBody.at(_posBody.size()-(i+1)).y));
    }

}

int NIBBLER::updateGame(IDisplayModule *_Dinstance)
{
    static double long sec = 0;
    double long ti = _Dinstance->getDeltaTime();
    sec += ti / 10000.0;

    if (sec > 9.) {
        sec = 0.0;

        moveBodySnake();
        collisionWall();
        foodWall();
        snakeCollision();
    }

    if (!_dead)
        return -1;
    return _hsc;
}
void NIBBLER::drawWall(IDisplayModule *instance)
{
    instance->drawRectangle(_rectUP);
    instance->drawRectangle(_rectDOWN);
    instance->drawRectangle(_rectRIGHT);
    instance->drawRectangle(_rectLEFT);

    instance->drawRectangle(_rectMIDx);
    instance->drawRectangle(_rectMIDy);
    instance->drawRectangle(_rectMIDz);
}

void NIBBLER::drawText(IDisplayModule *instance)
{
    std::string Score = std::to_string(_score-4);
    std::string nbdie = std::to_string(_dies);

    if (_score-4 > _hsc) _hsc = (_score-4);
    std::string hsc = std::to_string(_hsc);

    Arcade::Text pseudoT("Player: " , _colorW,   Arcade::Vector2f(_segment*50 - _segment/2,100));
    Arcade::Text pseudoN(instance->getPseudo(), _colorM,   Arcade::Vector2f(_segment*50- _segment/2,130));
    Arcade::Text hscore("Record: " + hsc, _colorW,   Arcade::Vector2f(_segment*50,170));
    Arcade::Text score("Actual score: " + Score, _colorW,   Arcade::Vector2f(_segment*50,200));
    Arcade::Text allDeath("Dies: " + nbdie, _colorW,   Arcade::Vector2f(_segment*50,230));
    
    instance->drawText(_txt);
    instance->drawText(score);
    instance->drawText(hscore);
    instance->drawText(pseudoT);
    instance->drawText(pseudoN);
    if (_alreadyDead) instance->drawText(allDeath);
}

void NIBBLER::drawGame(IDisplayModule *instance)
{
    drawWall(instance);
    drawText(instance);
    
    instance->drawCircle(_food);
    for(size_t i = 1; i < _body.size(); i++)
        instance->drawCircle(_body.at(i));
    instance->drawCircle(_snake);
}

void NIBBLER::replay()
{
    _moving = false;
    _dead = false;
    _name = "NIBBLER";
    _val = Arcade::Input::None;
    _score = 4;
    _posSnake =  Arcade::Vector2f(_segment * 10,_segment * 25);
    _snake.setPosition(_posSnake);
    _snake.setColor(_colorY);
    _posFood = Arcade::Vector2f(_segment * 40 + 10,_segment * 35 + 10);
    _food.setPosition(_posFood);
    direction = 0;

    _posBody.clear();
    _body.clear();
	_posBody.push_back(Arcade::Vector2f(_posSnake.x, _posSnake.y));
	_posBody.push_back(Arcade::Vector2f(_posSnake.x, _posSnake.y));
	_posBody.push_back(Arcade::Vector2f(_posSnake.x, _posSnake.y));
	_posBody.push_back(Arcade::Vector2f(_posSnake.x, _posSnake.y));
	_posBody.push_back(Arcade::Vector2f(_posSnake.x, _posSnake.y));
	Arcade::Circle	body(20, _posBody.at(0), _colorB);
	_body.push_back(body);
	_body.push_back(body);
	_body.push_back(body);
	_body.push_back(body);
	_body.push_back(body);

}
