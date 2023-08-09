#pragma once
#include <thread>
#include <mutex>
#include <vector>
#include <memory>
#include "View_Wrapper.h"
#include "Controller_Update.h"
#include "Controller_Game.h"
#include "Model_Player.h"
#include "Model_Game.h"
#include "Model_Item.h"
#include "View_Player.h"
#include "View_Game.h"
#include "Controller_Player.h"
#include "Controller_Enemy.h"
#include "Controller_Bullet.h"
#include "Controller_Item.h"
#include "Controller_Room.h"
#include "Controller_Level1.h"

class GameState;

class Controller_Game {
private:
    std::unique_ptr<GameState> currentState;

public:


    View_Wrapper* ventana;
    Controller_Game();
    void runGame();
    void changeState(std::unique_ptr<GameState> newState);
};

class GameState {
public:
    virtual ~GameState() = default;
    virtual void update(Controller_Game& game) = 0;
};



class Level1State : public GameState {
private:
    Controller_Level1 level1Controller;

public:
    Level1State() : level1Controller() {}
    void update(Controller_Game& game) override {
        level1Controller.update();
    }
};