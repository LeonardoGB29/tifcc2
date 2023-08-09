#pragma once
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
#include "View_Player.h"
#include "View_Game.h"
#include "Controller_Player.h"
#include "Controller_Enemy.h"
#include "Controller_Bullet.h"
#include "Controller_Item.h"
#include "Model_Item.h"
#include "Controller_Room.h"

class Controller_Level1 {
private:

    Controller_Update<Controller_Character> player_Updater;
    Controller_Update<Controller_Enemy> enemy_Updater;
    Controller_Update<Controller_Bullet> bullet_Updater;

    std::vector<Controller_Player> controllerPlayers;
    std::vector<std::shared_ptr<Controller_Enemy>> controllerEnemies;

    std::vector<Controller_Collision> collisionEnemies;
    std::vector<Controller_Collision> collisionPlayers;

    std::vector<Model_Item> modelItems;
    std::vector<Controller_Item> controllerItems;

    Model_Game gameModel;
    View_Game gameView;

    View_Wrapper* ventana;

    Model_TypeMap map;
    Controller_Room controllerRoom;
    Controller_LevelRooms levelRooms;

public:

    Controller_Level1(); 
    void update();
    void Control_Collision_Enemy_Enemy();
    void Control_RoomElemets(Controller_Room&);
};