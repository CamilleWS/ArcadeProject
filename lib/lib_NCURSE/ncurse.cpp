//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Nathan.R Benjamin.R Camille.V [MPL - 2022]
//

#include "../../include/ncurse.hpp"

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
    mod = new NCURSE;
}

__attribute__((destructor))
void destructor()
{
    delete mod;
}

NCURSE::NCURSE()
{
}

void NCURSE::init()
{
    initscr();
    NCURSE::_window = newwin(50, 100, 0, 0);
    NCURSE::_windowtext = newwin(50, 200, 0, 0);
    nodelay(stdscr, TRUE);
    nodelay(NCURSE::_window, TRUE);
    nodelay(NCURSE::_windowtext, TRUE);
    noecho();
    keypad(stdscr, TRUE);
    start_color();

    for (int i = 0; i < 5000; i++)
        NCURSE::_boardstr += ' ';
    NCURSE::_boardstr += '\0';

    NCURSE::_caracColor = {{'&', "Alpha"}, {' ', "Black"}, {'b', "Blue"},
        {'c', "Cyan"}, {'g', "Green"}, {'m', "Magenta"}, {'r', "Red"},
        {'w', "White"}, {'y', "Yellow"}};
    init_pair(2, COLOR_BLACK, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_CYAN, COLOR_CYAN);
    init_pair(5, COLOR_GREEN, COLOR_GREEN);
    init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(7, COLOR_RED, COLOR_RED);
    init_pair(8, COLOR_WHITE, COLOR_WHITE);
    init_pair(9, COLOR_YELLOW, COLOR_YELLOW);

    init_pair(10, COLOR_BLACK, COLOR_BLACK);
    init_pair(11, COLOR_BLUE, COLOR_BLACK);
    init_pair(12, COLOR_CYAN, COLOR_BLACK);
    init_pair(13, COLOR_GREEN, COLOR_BLACK);
    init_pair(14, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(15, COLOR_RED, COLOR_BLACK);
    init_pair(16, COLOR_WHITE, COLOR_BLACK);
    init_pair(17, COLOR_YELLOW, COLOR_BLACK);

    /*init_pair(2, COLOR_BLACK, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_CYAN);
    init_pair(5, COLOR_BLACK, COLOR_GREEN);
    init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(7, COLOR_BLACK, COLOR_RED);
    init_pair(8, COLOR_BLACK, COLOR_WHITE);
    init_pair(9, COLOR_BLACK, COLOR_YELLOW);*/
}

void NCURSE::stop()
{
    delwin(NCURSE::_window);
    endwin();
}

void *NCURSE::getHandle() const
{
    return _handle;
}

void NCURSE::setHandle(void *handle)
{
    _handle = handle;
}

void NCURSE::setName(std::string handle)
{
    _name = handle;
}

const std::string &NCURSE::getName() const
{
    return _name;
}

void NCURSE::fillBoard()
{
    int i = 0;
    char c = NCURSE::_boardstr[0];
    std::string temp = "";

    NCURSE::_board.clear();
    while (NCURSE::_boardstr[i] != '\0') {
        for (; NCURSE::_boardstr[i] == c; i++)
            temp += NCURSE::_boardstr[i];
        NCURSE::_board.push_back(temp);
        c = NCURSE::_boardstr[i];
        temp.clear();
    }
}

void NCURSE::changeStrColor(int ic, std::vector<std::string> tab, WINDOW *win)
{
    if (tab.at(ic) == "BLACK")
        wattron(win, COLOR_PAIR(10));
    if (tab.at(ic) == "BLUE")
        wattron(win, COLOR_PAIR(11));
    if (tab.at(ic) == "CYAN")
        wattron(win, COLOR_PAIR(12));
    if (tab.at(ic) == "GREEN")
        wattron(win, COLOR_PAIR(13));
    if (tab.at(ic) == "MAGENTA")
        wattron(win, COLOR_PAIR(14));
    if (tab.at(ic) == "RED")
        wattron(win, COLOR_PAIR(15));
    if (tab.at(ic) == "WHITE")
        wattron(win, COLOR_PAIR(16));
    if (tab.at(ic) == "YELLOW")
        wattron(win, COLOR_PAIR(17));
}

void NCURSE::displayWindow()
{
    int c = 0;
    int i = 0;
    int ic = 0;
    int ok = 0;

    fillBoard();
    for (int j = 0; j < NCURSE::_board.size(); j++) {
        i = 0;
        for (std::map<char, std::string>::iterator it = NCURSE::_caracColor.begin();
            it != NCURSE::_caracColor.end(); ++it) {
            i++;
            if (NCURSE::_board[j][0] == it->first) {
                wattron(NCURSE::_window, COLOR_PAIR(i));
                break;
            }
        }
        wprintw(NCURSE::_window, NCURSE::_board.at(j).c_str());
        if (ok == 1) {
            wattroff(NCURSE::_window, COLOR_PAIR(10));
            wattroff(NCURSE::_window, COLOR_PAIR(11));
            wattroff(NCURSE::_window, COLOR_PAIR(12));
            wattroff(NCURSE::_window, COLOR_PAIR(13));
            wattroff(NCURSE::_window, COLOR_PAIR(14));
            wattroff(NCURSE::_window, COLOR_PAIR(15));
            wattroff(NCURSE::_window, COLOR_PAIR(16));
            wattroff(NCURSE::_window, COLOR_PAIR(17));
            ok = 0;
        } else
            wattroff(NCURSE::_window, COLOR_PAIR(i + 1));
    }
    for (int j = 0; j < NCURSE::_str.size(); j++) {
        //std::cout << NCURSE::_str.at(j) << std::endl;
        NCURSE::changeStrColor(j, NCURSE::_strColor, NCURSE::_windowtext);
        mvwprintw(NCURSE::_windowtext, NCURSE::_strPosX.at(j),
            NCURSE::_strPosY.at(j), NCURSE::_str.at(j).c_str());
    }
    //wprintw(NCURSE::_window, NCURSE::_boardstr.c_str());
    refresh();
    wrefresh(NCURSE::_window);
    wrefresh(NCURSE::_windowtext);
    /*while (c != 27) {
        timeout(1);
        c = getch();
        usleep(100000);
    }*/
}

void NCURSE::clearWindow()
{
    werase(NCURSE::_window);
    werase(NCURSE::_windowtext);
    usleep(100000);
    NCURSE::_strPosY.clear();
    NCURSE::_strPosX.clear();
    NCURSE::_str.clear();
    NCURSE::_strColor.clear();
    NCURSE::_boardstr.clear();
    for (int i = 0; i < 5000; i++) {
        NCURSE::_boardstr += ' ';
    }
    NCURSE::_boardstr += '\0';
    refresh();
    wrefresh(NCURSE::_window);
    wrefresh(NCURSE::_windowtext);
}

void NCURSE::eventManager()
{
    /*
    int c = 0;

    init_pair(2, COLOR_RED, COLOR_RED);
    attron(COLOR_PAIR(2));

    mvwprintw(NCURSE::_window, 0, 1, "YOLOOOO STRAT");
    attroff(COLOR_PAIR(2));
    refresh();
    //wrefresh(NCURSE::_window);
    while (c != 27) {
        timeout(1);
        c = getch();
        usleep(100000);
    }
     */
}

void NCURSE::drawRectangle(Arcade::Rectangle &rectangle)
{
    int pos_y = rectangle.getPosition().x / 10;
    int pos_x = rectangle.getPosition().y / 20;

    int size_x = rectangle.getSize().x / 20;
    int size_y = rectangle.getSize().y / 10;
    char carac = '.';

    //if ((pos_y % 10) != 1)
    pos_y -= 1;
    //if ((pos_x % 10) != 1)
    pos_x -= 1;

    /*if ((((int)rectangle.getSize().x / 20) % 10) != 0)
        size_x = rectangle.getSize().x / 20 + 1;
    if ((((int)rectangle.getSize().y / 10) % 10) != 0)
        size_y = rectangle.getSize().y / 10 + 1;*/

    size_x < 1 ? size_x = 1 : size_x;
    size_y < 1 ? size_y = 1 : size_y;
    size_y > 20 ? size_y = size_y / 2 + 1 : size_y;

    std::string color = rectangle.getColor().color;

    for (std::map<char, std::string>::iterator it = NCURSE::_caracColor.begin();
        it != NCURSE::_caracColor.end(); ++it)
        if (color == it->second)
            carac = it->first;

    int pos = pos_x * 100 + pos_y;
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < (size_x * 2); j++) {
            if (pos + j < 5000)
                NCURSE::_boardstr[pos + j] = carac;
        }
        pos += 100;
    }
}

void NCURSE::drawCircle(Arcade::Circle &circle)
{
    int pos_y = (circle.getPosition().x - circle.getRadius()) / 10;
    int pos_x = (circle.getPosition().y - circle.getRadius()) / 20;
    int size_x = circle.getRadius() * 2 / 20;
    int size_y = circle.getRadius() * 2 / 20;
    char carac = 'O';

    if (((((int)circle.getPosition().x - (int)circle.getRadius()) / 100) %
        10) != 0)
        pos_y = (circle.getPosition().x - (int)circle.getRadius()) / 10 + 1;
    if (((((int)circle.getPosition().y - (int)circle.getRadius()) / 200) %
        10) != 0)
        pos_x = (circle.getPosition().y - (int)circle.getRadius()) / 20 + 1;

    if ((((int)circle.getRadius() * 2 / 20) % 10) != 0)
        size_x = circle.getRadius() * 2 / 20 + 1;
    if ((((int)circle.getRadius() * 2 / 10) % 10) != 0)
        size_y = circle.getRadius() * 2 / 20 + 1;

    size_x < 1 ? size_x = 1 : size_x;
    size_y < 1 ? size_y = 1 : size_y;
    size_y > 1 ? size_y -= 1 : size_y;

    std::string color = circle.getColor().color;
    //for (auto & c: color) c = toupper(c);

    for (std::map<char, std::string>::iterator it = NCURSE::_caracColor.begin();
        it != NCURSE::_caracColor.end(); ++it)
        if (color == it->second)
            carac = it->first;

    int pos = pos_x * 100 + pos_y;
    for (int i = 0; i < size_y; i++) {
        if ((i == 0 || (i + 1) == size_y) && (size_x >= 3 && size_y >= 3)) {
            for (int j = 1; j < size_x - 1; j++)
                if (pos + j < 5000)
                    NCURSE::_boardstr[pos + j] = carac;
        } else {
            for (int j = 0; j < size_x; j++)
                if (pos + j < 5000)
                    NCURSE::_boardstr[pos + j] = carac;
        }
        for (int j = 0; j < size_x; j++)
            if (pos + j < 5000)
                NCURSE::_boardstr[pos + j] = carac;
        pos += 100;
    }
}

void NCURSE::drawText(Arcade::Text &text)
{
    int pos_y = text.getPosition().x / 10;
    int pos_x = text.getPosition().y / 20;

    if ((pos_y % 10) != 0)
        pos_y += 1;
    if ((pos_x % 10) != 1)
        pos_x += 1;

    for (int i = 0; i < NCURSE::_str.size(); i++)
        if (pos_x == NCURSE::_strPosX.at(i) &&
            (pos_y >= NCURSE::_strPosY.at(i) &&
                pos_y <= (NCURSE::_strPosY.at(i) + NCURSE::_str.at(i).size())))
            pos_x += 1;

    //std::cout << text.getString() << std::endl;
    std::string color = text.getColor().color;
    for (auto &c: color)
        c = toupper(c);
    NCURSE::_strColor.push_back(color);
    NCURSE::_str.push_back(text.getString());
    NCURSE::_strPosY.push_back(pos_y);
    NCURSE::_strPosX.push_back(pos_x);

    /*NCURSE::_strPosGiveY.push_back(text.getPosition().y);
    for (int i = 0; i < NCURSE::_strPosGiveY.size() && i < NCURSE::_strPosX.size(); i++) {
        if (text.getPosition().y == NCURSE::_strPosGiveY.at(i)) {
            pos_x = NCURSE::_strPosX.at(i);
            NCURSE::_strPosX.pop_back();
            NCURSE::_strPosX.push_back(pos_x);
        }
    }*/
}

Arcade::Input NCURSE::coreInputs()
{
    int c = 0;

    c = getch();
    //std::cout << c << std::endl;
    if (c == 9)
        return Arcade::Input::Escape;
    if (c == 27)
        return Arcade::Input::Escape;
    if (c == 260)
        return Arcade::Input::LEFT;
    if (c == 261)
        return Arcade::Input::RIGHT;
    if (c == 259)
        return Arcade::Input::UP;
    if (c == 258)
        return Arcade::Input::DOWN;
    if (c == 48)
        return Arcade::Input::Num0;
    if (c == 49)
        return Arcade::Input::Num1;
    if (c == 50)
        return Arcade::Input::Num2;
    if (c == 51)
        return Arcade::Input::Num3;
    if (c == 52)
        return Arcade::Input::Num4;
    if (c == 65 || c == 97)
        return Arcade::Input::A;
    if (c == 66 || c == 98)
        return Arcade::Input::B;
    if (c == 67 || c == 99)
        return Arcade::Input::C;
    if (c == 68 || c == 100)
        return Arcade::Input::D;
    if (c == 69 || c == 101)
        return Arcade::Input::E;
    if (c == 70 || c == 102)
        return Arcade::Input::F;
    if (c == 71 || c == 103)
        return Arcade::Input::G;
    if (c == 72 || c == 104)
        return Arcade::Input::H;
    if (c == 73 || c == 105)
        return Arcade::Input::I;
    if (c == 74 || c == 106)
        return Arcade::Input::J;
    if (c == 75 || c == 107)
        return Arcade::Input::K;
    if (c == 76 || c == 108)
        return Arcade::Input::L;
    if (c == 77 || c == 109)
        return Arcade::Input::M;
    if (c == 78 || c == 110)
        return Arcade::Input::N;
    if (c == 79 || c == 111)
        return Arcade::Input::O;
    if (c == 80 || c == 112)
        return Arcade::Input::P;
    if (c == 81 || c == 113)
        return Arcade::Input::Q;
    if (c == 82 || c == 114)
        return Arcade::Input::R;
    if (c == 83 || c == 115)
        return Arcade::Input::S;
    if (c == 84 || c == 116)
        return Arcade::Input::T;
    if (c == 85 || c == 117)
        return Arcade::Input::U;
    if (c == 86 || c == 118)
        return Arcade::Input::V;
    if (c == 87 || c == 119)
        return Arcade::Input::W;
    if (c == 88 || c == 120)
        return Arcade::Input::X;
    if (c == 89 || c == 121)
        return Arcade::Input::Y;
    if (c == 90 || c == 122)
        return Arcade::Input::Z;
    if (c == 127)
        return Arcade::Input::BackSpace;
    if (c == 10)
        return Arcade::Input::Return;
    if (c == 32)
	return Arcade::Input::Space;
    return Arcade::Input::None;
}

void NCURSE::startClock()
{
    _clock = std::chrono::high_resolution_clock::now();
}

void NCURSE::setDeltaTime()
{
    auto elapsed = std::chrono::high_resolution_clock::now() - _clock;
    _clock = std::chrono::high_resolution_clock::now();
    _elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
        elapsed).count();
}

const long double &NCURSE::getDeltaTime() const
{
    return _elapsed;
}

std::string NCURSE::getPseudo() const
{

    return NCURSE::_pseudo;
}

void NCURSE::setPseudo(const std::string str)
{
    NCURSE::_pseudo = str;
}

int NCURSE::drawSprite(Arcade::Sprite)
{
    return 0;
}

void NCURSE::intputMenu(Arcade::Input val)
{
    (void)val;
}

void NCURSE::updateMenu()
{
}
