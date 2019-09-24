//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nathan.R Benjamin.R Camille.V [MPL - 2022]
//

#include "../../include/sfml.hpp"

IDisplayModule *mod = nullptr;

int libcheck;

extern "C" {
IDisplayModule *entryPoint()
{
    return mod;
}
}

__attribute__((constructor))
void constructor()
{
    mod = new SFML;
}

__attribute__((destructor))
void destructor()
{
    delete mod;
}

SFML::SFML() : _name(""), _pseudo(""),
    _window(sf::VideoMode(1200, 960), "Arcade [MPL-22] -> SFML"), _elapsed(0.0)
{
}

SFML::~SFML()
{
}

void SFML::init()
{
}

void SFML::stop()
{
    _window.close();
}

void *SFML::getHandle() const
{
    return _handle;
}

void SFML::setHandle(void *handle)
{
    _handle = handle;
}

void SFML::setName(std::string handle)
{
    _name = handle;
}

const std::string &SFML::getName() const
{
    return _name;
}

void SFML::clearWindow()
{
    _window.clear();
}

void SFML::displayWindow()
{
    _window.display();
}

void SFML::drawRectangle(Arcade::Rectangle &rectangle)
{
    sf::RectangleShape rect(sf::Vector2f(
        sf::Vector2f(rectangle.getSize().x, rectangle.getSize().y)));

    rect.setPosition(rectangle.getPosition().x, rectangle.getPosition().y);
    rect.setFillColor(sf::Color(rectangle.getColor().r, rectangle.getColor().g,
        rectangle.getColor().b));
    _window.draw(rect);
}

void SFML::drawCircle(Arcade::Circle &circle)
{
    sf::CircleShape shape(circle.getRadius());

    shape.setPosition(circle.getPosition().x, circle.getPosition().y);
    shape.setFillColor(sf::Color(circle.getColor().r, circle.getColor().g,
        circle.getColor().b));
    _window.draw(shape);
}

void SFML::drawText(Arcade::Text &text)
{

    sf::Font font;
    text.getString();

    sf::Color color(text.getColor().r, text.getColor().g, text.getColor().b,
        text.getColor().a);

    font.loadFromFile("./texture/VT323-Regular.ttf");

    sf::Text msg(text.getString(), font);

    msg.setCharacterSize(text.getSize());

    msg.setColor(color);

    msg.setPosition(text.getPosition().x, text.getPosition().y);

    _window.draw(msg);
}

Arcade::Input SFML::coreInputs()
{
    sf::Event event;
    _window.setKeyRepeatEnabled(false);
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return Arcade::Input::Escape;

        switch (event.key.code) {
        case sf::Keyboard::Tab:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)))
                return Arcade::Input::Escape;
        case sf::Keyboard::Escape:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
                return Arcade::Input::Escape;
        case sf::Keyboard::Left:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
                return Arcade::Input::LEFT;
        case sf::Keyboard::Right:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
                return Arcade::Input::RIGHT;
        case sf::Keyboard::Up:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
                return Arcade::Input::UP;
        case sf::Keyboard::Down:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
                return Arcade::Input::DOWN;
        case sf::Keyboard::Num0:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)))
                return Arcade::Input::Num0;
        case sf::Keyboard::Num1:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)))
                return Arcade::Input::Num1;
        case sf::Keyboard::Num2:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)))
                return Arcade::Input::Num2;
        case sf::Keyboard::Num3:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)))
                return Arcade::Input::Num3;
        case sf::Keyboard::Num4:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)))
                return Arcade::Input::Num4;
        case sf::Keyboard::A:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
                return Arcade::Input::A;
        case sf::Keyboard::Z:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z)))
                return Arcade::Input::Z;
        case sf::Keyboard::E:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::E)))
                return Arcade::Input::E;
        case sf::Keyboard::R:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::R)))
                return Arcade::Input::R;
        case sf::Keyboard::T:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::T)))
                return Arcade::Input::T;
        case sf::Keyboard::Y:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Y)))
                return Arcade::Input::Y;
        case sf::Keyboard::U:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::U)))
                return Arcade::Input::U;
        case sf::Keyboard::I:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::I)))
                return Arcade::Input::I;
        case sf::Keyboard::O:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::O)))
                return Arcade::Input::O;
        case sf::Keyboard::P:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::P)))
                return Arcade::Input::P;
        case sf::Keyboard::Q:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Q)))
                return Arcade::Input::Q;
        case sf::Keyboard::S:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S)))
                return Arcade::Input::S;
        case sf::Keyboard::D:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
                return Arcade::Input::D;
        case sf::Keyboard::F:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::F)))
                return Arcade::Input::F;
        case sf::Keyboard::G:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::G)))
                return Arcade::Input::G;
        case sf::Keyboard::H:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::H)))
                return Arcade::Input::H;
        case sf::Keyboard::J:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::J)))
                return Arcade::Input::J;
        case sf::Keyboard::K:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::K)))
                return Arcade::Input::K;
        case sf::Keyboard::L:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::L)))
                return Arcade::Input::L;
        case sf::Keyboard::M:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::M)))
                return Arcade::Input::M;
        case sf::Keyboard::W:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
                return Arcade::Input::W;
        case sf::Keyboard::X:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::X)))
                return Arcade::Input::X;
        case sf::Keyboard::C:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::C)))
                return Arcade::Input::C;
        case sf::Keyboard::V:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::V)))
                return Arcade::Input::V;
        case sf::Keyboard::B:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::B)))
                return Arcade::Input::B;
        case sf::Keyboard::N:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::N)))
                return Arcade::Input::N;
        case sf::Keyboard::BackSpace:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)))
                return Arcade::Input::BackSpace;
        case sf::Keyboard::Space:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
                return Arcade::Input::Space;
        case sf::Keyboard::Return:
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Return)))
                return Arcade::Input::Return;
        default:
            return Arcade::Input::None;
        }
    }
    return Arcade::Input::None;
}

void SFML::startClock()
{
    _clock = std::chrono::high_resolution_clock::now();
}

void SFML::setDeltaTime()
{
    auto elapsed = std::chrono::high_resolution_clock::now() - _clock;
    _clock = std::chrono::high_resolution_clock::now();
    _elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
        elapsed).count();
}

const long double &SFML::getDeltaTime() const
{
    return _elapsed;
}

std::string SFML::getPseudo() const
{
    return _pseudo;
}

void SFML::setPseudo(const std::string str)
{
    _pseudo = str;
}

int SFML::drawSprite(Arcade::Sprite sp)
{

    sf::Texture texture;
    texture.loadFromFile(sp.getName().c_str());
    sf::Sprite sprite(texture);

    sprite.setPosition(sf::Vector2f(sp.getPosition().x, sp.getPosition().y));
    _window.draw(sprite);
    return 0;
}
