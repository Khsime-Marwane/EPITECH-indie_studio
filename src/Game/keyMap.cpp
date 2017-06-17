//
// Author: Maud Marel
// Date: 2017-06-12 19:15:39
//

#include <iostream>
#include "Game/keyMap.hpp"

indie::keyMap::keyMap() : act()
{
    act[indie::GameState::MAIN_MENU] = std::bind(&indie::keyMap::act_menu, this, std::placeholders::_1);
    act[indie::GameState::SETTINGS] = std::bind(&indie::keyMap::act_settings, this, std::placeholders::_1);
    act[indie::GameState::SCOREBOARD] = std::bind(&indie::keyMap::act_score, this, std::placeholders::_1);
    act[indie::GameState::ROOM] = std::bind(&indie::keyMap::act_room, this, std::placeholders::_1);
}

indie::keyMap::~keyMap()
{
}

void    indie::keyMap::act_menu(indie::Event event)
{
  (void)event;
    std::cout << "MENU" << std::endl;
}

void    indie::keyMap::act_settings(indie::Event event)
{
  (void)event;
    std::cout << "SETTINGS" << std::endl;
}

void    indie::keyMap::act_score(indie::Event event)
{
  (void)event;
    std::cout << "SCORE" << std::endl;
}

void    indie::keyMap::act_room(indie::Event event)
{
  (void)event;
    std::cout << "ROOM" << std::endl;
}

void    indie::keyMap::manage_keyMap(indie::GameState &gameState, indie::Event event)
{
  (void)event;
    std::cout << "I'm here!" << std::endl;
    act[gameState](event);
}
