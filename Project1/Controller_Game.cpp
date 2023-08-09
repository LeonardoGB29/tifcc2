#include <thread>
#include <iostream>
#include<filesystem>
#include "View_Wrapper.h"
#include "View_Player.h"
#include "View_Sprite.h"
#include "View_Game.h"
#include "View_Item.h"
#include "Model_Player.h"
#include "Model_Enemy.h"
#include "Model_Game.h"
#include "Controller_Update.h"
#include "Controller_Collision.h"
#include "Controller_Game.h"
#include "Controller_Player.h"
#include "Controller_Enemy.h"
#include "Controller_Bullet.h"
#include "Bullet.h"
#include "View_Room.h"
#include "Model_LevelRooms.h"
#include "Controller_LevelRooms.h"
#include "Controller_Level1.h"

Controller_Game::Controller_Game()
    : currentState(std::make_unique<Level1State>()) {}

void Controller_Game::runGame() {
    while (ventana->isOpen()) {
        currentState->update(*this);
    }
}

void Controller_Game::changeState(std::unique_ptr<GameState> newState) {
    currentState = std::move(newState);
}