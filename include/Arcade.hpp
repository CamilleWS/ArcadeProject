//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// Hpp
//

#ifndef Arcade_hpp
#define Arcade_hpp

#include <string>

namespace Arcade {
    class Vector2i {
        public:
        Vector2i(int x = 0, int y = 0);

        ~Vector2i();

        Vector2i &operator=(const Arcade::Vector2i &other);

        int x;
        int y;
    };

    class Vector2f {
        public:
        Vector2f(float x = 0, float y = 0);

        ~Vector2f();

        Vector2f &operator=(const Arcade::Vector2f &other);

        float x;
        float y;
    };

    class Sprite {
        public:
        Sprite(const std::string &string = "tmp",
            Arcade::Vector2f position = Arcade::Vector2f());

        ~Sprite();

        Sprite &operator=(const Arcade::Sprite &other);

        void setPosition(Arcade::Vector2f);

        void setName(const std::string &string);

        const Arcade::Vector2f &getPosition() const;

        const std::string &getName() const;

        protected:
        Arcade::Vector2f _position;
        std::string _name;
    };

    enum Input {
        None,
        Backspace,
        Escape,
        Return,
        Space,
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        Num0,
        Num1,
        Num2,
        Num3,
        Num4,
        LEFT,
        RIGHT,
        UP,
        DOWN,
        LeftClick,
        RightClick,
        BackSpace,
    };

    class Color {
        public:
        Color(int r = 0, int g = 0, int b = 0, int a = 0,
            std::string color = std::string("Black"));

        ~Color();

        Color &operator=(const Arcade::Color &other);

        int r;
        int g;
        int b;
        int a;
        std::string color;
    };

    class Text {
        public:
        Text(const std::string &string, Arcade::Color color = Arcade::Color(),
            Arcade::Vector2f position = Arcade::Vector2f(), size_t size = 30
        );

        ~Text();

        void move(Arcade::Vector2f move);

        void setPosition(Arcade::Vector2f);

        void setString(const std::string &string);

        void setColor(Arcade::Color color);

        const Arcade::Vector2f &getPosition() const;

        const std::string &getString() const;

        const Arcade::Color &getColor() const;

        size_t getSize() const;

        void setSize(size_t size);

        private:
        Arcade::Vector2f _position;
        Arcade::Color _color;
        std::string _string;
        size_t _size;
    };

    class Rectangle {
        public:
        Rectangle(Arcade::Vector2f size = Arcade::Vector2f(),
            Arcade::Vector2f position = Arcade::Vector2f(),
            Arcade::Color color = Arcade::Color());

        ~Rectangle();

        void move(Arcade::Vector2f move);

        void setPosition(Arcade::Vector2f position);

        void setSize(Arcade::Vector2f position);

        void setColor(Arcade::Color color);

        const Arcade::Vector2f &getPosition() const;

        const Arcade::Vector2f &getSize() const;

        const Arcade::Color &getColor() const;

        protected:
        Arcade::Vector2f _size;
        Arcade::Vector2f _position;
        Arcade::Color _color;
    };

    class Circle {
        public:
        Circle(float r, Arcade::Vector2f position = Arcade::Vector2f(),
            Arcade::Color color = Arcade::Color());

        ~Circle();

        void move(Arcade::Vector2f move);

        void setPosition(Arcade::Vector2f position);

        void setRadius(float r);

        void setColor(Arcade::Color color);

        const Arcade::Vector2f &getPosition() const;

        const float &getRadius() const;

        const Arcade::Color &getColor() const;

        protected:
        Arcade::Vector2f _position;
        float _r;
        Arcade::Color _color;
    };
}

#endif
