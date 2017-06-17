//
// Author: Maud Marel
// Date: 2017-05-23 14:09:04
//

#include <iostream>
#include <chrono>
#include <thread>
#include <memory>
#include "Core/Core.hpp"

indie::Core::Core()
    :
        _gfx(std::make_unique<indie::Gfx>()),
        _game(std::make_unique<indie::Game>()), // set make unique with the game when merge will be ok with game part
        _sounds(),
        _gameState(indie::GameState::NONE)
{
  std::cout << "core ctor\n";
    if (!this->_gfx || !this->_game)
        throw indie::IndieError(_INDIE_CORE_INIT_FAILED);
}

indie::Core::~Core()
{
    if (this->_gfx)
        this->_gfx.reset();
    if (this->_game)
        this->_gfx.reset();
}

void            indie::Core::runCoreLoop()
{

    while (42) {

        this->_gameState = this->_game->getGameState();
        this->_gfx->clear();

        switch(this->_gameState) {

            case indie::GameState::QUIT:
                return ;
                break ;

            case indie::GameState::SPLASH_SCREEN: // To change when splash will be ready.
                this->loading();
                this->process();
                break ;


            case indie::GameState::INGAME:
            case indie::GameState::MAIN_MENU:
            case indie::GameState::SCOREBOARD:
            case indie::GameState::SETTINGS:
            case indie::GameState::HELP:
            case indie::GameState::ROOM:
                this->process();
                break ;

            case indie::GameState::NONE:
            default:
                break ;

        } // switch

  }
}
