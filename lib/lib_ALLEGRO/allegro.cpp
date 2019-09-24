//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nathan.R Benjamin.R Camille.V [MPL - 2022]
//

#include "../../include/allegro.hpp"

#include <sys/time.h>

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
    mod = new ALLEGRO;
}

__attribute__((destructor))
void destructor()
{
    delete mod;
}

ALLEGRO::ALLEGRO() : _name(""), _window(NULL), _event_queue(NULL), _elapsed(0.0)
{
    al_init();
    _window = al_create_display(1200, 950);
    al_set_window_title(_window, "Arcade [MPL-22] -> Allegro");
}

ALLEGRO::~ALLEGRO()
{
}

void ALLEGRO::init()
{
    al_install_keyboard();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();

    // _menu._bigFont = al_load_ttf_font("./doc/texture/VT323-Regular.ttf", 110, ALLEGRO_TTF_NO_KERNING);

}

void ALLEGRO::stop()
{
    al_destroy_display(_window);
}

void *ALLEGRO::getHandle() const
{
    return _handle;
}

void ALLEGRO::setHandle(void *handle)
{
    _handle = handle;
}

void ALLEGRO::setName(std::string handle)
{
    _name = handle;
}

const std::string &ALLEGRO::getName() const
{
    return _name;
}

void ALLEGRO::clearWindow()
{
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

void ALLEGRO::displayWindow()
{
    al_flip_display();
}

void ALLEGRO::drawRectangle(Arcade::Rectangle &rectangle)
{
    ALLEGRO_COLOR color = al_map_rgb(rectangle.getColor().r,
        rectangle.getColor().g, rectangle.getColor().b);
    al_draw_filled_rectangle(rectangle.getPosition().x,
        rectangle.getPosition().y,
        rectangle.getPosition().x + rectangle.getSize().x,
        rectangle.getPosition().y + rectangle.getSize().y, color);
}

void ALLEGRO::drawCircle(Arcade::Circle &circle)
{
    ALLEGRO_COLOR color = al_map_rgb(circle.getColor().r, circle.getColor().g,
        circle.getColor().b);
    al_draw_filled_circle(circle.getPosition().x + circle.getRadius(),
        circle.getPosition().y + circle.getRadius(), circle.getRadius(), color);
}

void ALLEGRO::drawText(Arcade::Text &text)
{
    ALLEGRO_FONT *font;
    ALLEGRO_COLOR color = al_map_rgb(text.getColor().r, text.getColor().g,
        text.getColor().b);

    font = al_load_ttf_font("./texture/VT323-Regular.ttf", text.getSize(),
        ALLEGRO_TTF_NO_KERNING);
    al_draw_text(font, color, text.getPosition().x, text.getPosition().y,
        ALLEGRO_ALIGN_LEFT, text.getString().c_str());
    al_destroy_font(font);
}

Arcade::Input ALLEGRO::coreInputs()
{
    ALLEGRO_EVENT event;
    ALLEGRO_TIMEOUT timeout;
    ALLEGRO_KEYBOARD_STATE key;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    event_queue = al_create_event_queue();
    al_init_timeout(&timeout, 0.06);
    al_register_event_source(event_queue, al_get_display_event_source(_window));
    bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
    al_get_keyboard_state(&key);

    if (get_event && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        al_destroy_event_queue(event_queue);
        return Arcade::Input::Escape;
    }
    if (al_key_down(&key, ALLEGRO_KEY_TAB))
        return Arcade::Input::Escape;
    if (al_key_down(&key, ALLEGRO_KEY_LEFT))
        return Arcade::Input::LEFT;
    if (al_key_down(&key, ALLEGRO_KEY_RIGHT))
        return Arcade::Input::RIGHT;
    if (al_key_down(&key, ALLEGRO_KEY_UP))
        return Arcade::Input::UP;
    if (al_key_down(&key, ALLEGRO_KEY_DOWN))
        return Arcade::Input::DOWN;
    if (al_key_down(&key, ALLEGRO_KEY_0))
        return Arcade::Input::Num0;
    if (al_key_down(&key, ALLEGRO_KEY_1))
        return Arcade::Input::Num1;
    if (al_key_down(&key, ALLEGRO_KEY_2))
        return Arcade::Input::Num2;
    if (al_key_down(&key, ALLEGRO_KEY_3))
        return Arcade::Input::Num3;
    if (al_key_down(&key, ALLEGRO_KEY_4))
        return Arcade::Input::Num4;
    if (al_key_down(&key, ALLEGRO_KEY_A))
        return Arcade::Input::A;
    if (al_key_down(&key, ALLEGRO_KEY_Z))
        return Arcade::Input::Z;
    if (al_key_down(&key, ALLEGRO_KEY_E))
        return Arcade::Input::E;
    if (al_key_down(&key, ALLEGRO_KEY_R))
        return Arcade::Input::R;
    if (al_key_down(&key, ALLEGRO_KEY_T))
        return Arcade::Input::T;
    if (al_key_down(&key, ALLEGRO_KEY_Y))
        return Arcade::Input::Y;
    if (al_key_down(&key, ALLEGRO_KEY_U))
        return Arcade::Input::U;
    if (al_key_down(&key, ALLEGRO_KEY_I))
        return Arcade::Input::I;
    if (al_key_down(&key, ALLEGRO_KEY_O))
        return Arcade::Input::O;
    if (al_key_down(&key, ALLEGRO_KEY_P))
        return Arcade::Input::P;
    if (al_key_down(&key, ALLEGRO_KEY_Q))
        return Arcade::Input::Q;
    if (al_key_down(&key, ALLEGRO_KEY_S))
        return Arcade::Input::S;
    if (al_key_down(&key, ALLEGRO_KEY_D))
        return Arcade::Input::D;
    if (al_key_down(&key, ALLEGRO_KEY_F))
        return Arcade::Input::F;
    if (al_key_down(&key, ALLEGRO_KEY_G))
        return Arcade::Input::G;
    if (al_key_down(&key, ALLEGRO_KEY_H))
        return Arcade::Input::H;
    if (al_key_down(&key, ALLEGRO_KEY_J))
        return Arcade::Input::J;
    if (al_key_down(&key, ALLEGRO_KEY_K))
        return Arcade::Input::K;
    if (al_key_down(&key, ALLEGRO_KEY_L))
        return Arcade::Input::L;
    if (al_key_down(&key, ALLEGRO_KEY_M))
        return Arcade::Input::M;
    if (al_key_down(&key, ALLEGRO_KEY_W))
        return Arcade::Input::W;
    if (al_key_down(&key, ALLEGRO_KEY_X))
        return Arcade::Input::X;
    if (al_key_down(&key, ALLEGRO_KEY_C))
        return Arcade::Input::C;
    if (al_key_down(&key, ALLEGRO_KEY_V))
        return Arcade::Input::V;
    if (al_key_down(&key, ALLEGRO_KEY_B))
        return Arcade::Input::B;
    if (al_key_down(&key, ALLEGRO_KEY_N))
        return Arcade::Input::N;
    if (al_key_down(&key, ALLEGRO_KEY_BACKSPACE))
        return Arcade::Input::BackSpace;
    if (al_key_down(&key, ALLEGRO_KEY_SPACE))
        return Arcade::Input::Space;
    if (al_key_down(&key, ALLEGRO_KEY_ENTER))
        return Arcade::Input::Return;
    if (al_key_down(&key, ALLEGRO_KEY_ESCAPE))
        return Arcade::Input::Escape;

    al_destroy_event_queue(event_queue);
    return Arcade::Input::None;
}

void ALLEGRO::startClock()
{
    _clock = std::chrono::high_resolution_clock::now();
}

void ALLEGRO::setDeltaTime()
{
    auto elapsed = std::chrono::high_resolution_clock::now() - _clock;
    _clock = std::chrono::high_resolution_clock::now();
    _elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
        elapsed).count();
}

const long double &ALLEGRO::getDeltaTime() const
{
    return _elapsed;
}

std::string ALLEGRO::getPseudo() const
{
    return _pseudo;
}

void ALLEGRO::setPseudo(const std::string str)
{
    _pseudo = str;
}

int ALLEGRO::drawSprite(Arcade::Sprite sp)
{
    ALLEGRO_BITMAP *tmp = al_load_bitmap(sp.getName().c_str());
    al_draw_bitmap(tmp, sp.getPosition().x, sp.getPosition().y, 0);
    return (1);
}