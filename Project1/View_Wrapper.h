#pragma once
#include <SFML/Graphics.hpp>
#include "Model_Character.h"
#include "View_Sprite.h"


struct UserInput {
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool shoot = false;
    bool shootProcessed = false;
    bool shootUp = false;
    bool shootDown = false;
    bool shootLeft = false;
    bool shootRight = false;
    bool shootUpProcessed = false;
    bool shootDownProcessed = false;
    bool shootLeftProcessed = false;
    bool shootRightProcessed = false;
};

struct UserInput1 : UserInput {
};

struct UserInput2 : UserInput {
};

class View_Wrapper {
private:
    sf::RenderWindow window;
    UserInput userInput1;
    UserInput userInput2;

    View_Wrapper(int width, int height, const std::string& title) {
        window.create(sf::VideoMode(width, height), title);
        window.setFramerateLimit(60);
    }

    static View_Wrapper* instance;

public:

    static View_Wrapper* getInstance() {
        if (!instance) {
            instance = new View_Wrapper(1088, 640, "JUEGO");
        }
        return instance;
    }

    View_Wrapper() = default;

    UserInput& getUserInput1() { return userInput1; }
    UserInput& getUserInput2() { return userInput2; }

    bool isOpen();
    void close();
    void clear();
    void display();
    void draw(const sf::Drawable& drawable);
    void processEvents();
    template <typename T>
    void spriteDraw(T sprite);
};

View_Wrapper* View_Wrapper::instance = nullptr;

template <typename T>
void View_Wrapper::spriteDraw(T sprite) {
    window.draw(sprite.sprite);
}

