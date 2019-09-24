//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// src
//


#include "../include/Arcade.hpp"

Arcade::Vector2i::Vector2i(int x_, int y_) :
x(x_),
y(y_)
{

}

Arcade::Vector2i::~Vector2i()
{

}

Arcade::Vector2f::Vector2f(float x_, float y_) :
x(x_),
y(y_)
{

}

Arcade::Vector2f::~Vector2f()
{

}

Arcade::Color::Color(int r_, int g_, int b_, int a_, std::string color_) :
r(r_),
g(g_),
b(b_),
a(a_),
color(color_)
{

}

Arcade::Color::~Color()
{
}

Arcade::Text::Text(const std::string &string, Arcade::Color color, Arcade::Vector2f position, size_t size)
{
    _string = string;
    _position = position;
    _color = color;
    _size = size;
}

Arcade::Text::~Text()
{

}

void Arcade::Text::move(Arcade::Vector2f move)
{
    _position.x += move.x;
    _position.y += move.y;
}

void Arcade::Text::setPosition(Arcade::Vector2f position)
{
    _position.x = position.x;
    _position.y = position.y;
}

void Arcade::Text::setString(const std::string &string)
{
    _string = string;
}

void Arcade::Text::setColor(Arcade::Color color)
{
    _color = color;
}


const Arcade::Vector2f &Arcade::Text::getPosition() const
{
    return (_position);
}

const std::string &Arcade::Text::getString() const
{
    return (_string);
}

const Arcade::Color &Arcade::Text::getColor() const
{
    return (_color);
}

size_t Arcade::Text::getSize() const
{
    return (_size);
}

void Arcade::Text::setSize(size_t size)
{
    _size = size;
}


Arcade::Sprite::Sprite(const std::string &string, Arcade::Vector2f position) : _position(position), _name(string)
{
}

void Arcade::Sprite::setPosition(Arcade::Vector2f pos)
{
    _position = pos;
}

void Arcade::Sprite::setName(const std::string &string)
{
    _name = string;
}

const std::string &Arcade::Sprite::getName() const
{
    return (_name);
}

const Arcade::Vector2f &Arcade::Sprite::getPosition() const
{
    return (_position);
}

Arcade::Sprite &Arcade::Sprite::operator=(const Arcade::Sprite& other)
{
    _name = other._name;
    _position = other._position;
    return *this;
}

Arcade::Sprite::~Sprite()
{
}


Arcade::Rectangle::Rectangle(Arcade::Vector2f size, Arcade::Vector2f position, Arcade::Color color)
{
    _position = position;
    _size = size;
    _color = color;
}

Arcade::Rectangle::~Rectangle()
{

}

void Arcade::Rectangle::move(Arcade::Vector2f move)
{
    _position.x += move.x;
    _position.y += move.y;
}

void Arcade::Rectangle::setPosition(Arcade::Vector2f position)
{
    _position.x = position.x;
    _position.y = position.y;
}

void Arcade::Rectangle::setSize(Arcade::Vector2f size)
{
    _size.x = size.x;
    _size.y = size.y;
}


void Arcade::Rectangle::setColor(Arcade::Color color)
{
    _color = color;
}

const Arcade::Vector2f &Arcade::Rectangle::getPosition() const
{
    return (_position);
}

const Arcade::Vector2f &Arcade::Rectangle::getSize() const
{
    return (_size);
}

const Arcade::Color &Arcade::Rectangle::getColor() const
{
    return (_color);
}

Arcade::Circle::Circle(float r, Arcade::Vector2f position, Arcade::Color color)
{
    _position.x = position.x;
    _position.y = position.y;
    _r = r;
    _color = color;
}

Arcade::Circle::~Circle()
{

}

void Arcade::Circle::move(Arcade::Vector2f move)
{
    _position.x += move.x;
    _position.y += move.y;
}

void Arcade::Circle::setPosition(Arcade::Vector2f position)
{
    _position.x = position.x;
    _position.y = position.y;
}

void Arcade::Circle::setRadius(float r)
{
    _r = r;
}


void Arcade::Circle::setColor(Arcade::Color color)
{
    _color = color;
}

const Arcade::Vector2f &Arcade::Circle::getPosition() const
{
    return (_position);
}

const float &Arcade::Circle::getRadius() const
{
    return (_r);
}

const Arcade::Color &Arcade::Circle::getColor() const
{
    return (_color);
}

Arcade::Color &Arcade::Color::operator=(const Arcade::Color& other)
{
    r = other.r;
    g = other.g;
    b = other.b;
    a = other.a;
    color = other.color;
    return *this;
}

Arcade::Vector2f &Arcade::Vector2f::operator=(const Arcade::Vector2f& other)
{
    x = other.x;
    y = other.y;
    return *this;
}

Arcade::Vector2i &Arcade::Vector2i::operator=(const Arcade::Vector2i& other)
{
    x = other.x;
    y = other.y;
    return *this;
}
