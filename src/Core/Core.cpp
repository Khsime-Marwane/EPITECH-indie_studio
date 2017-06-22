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

        switch(this->_gameState) {

            case indie::GameState::QUIT:
                return ;
                break ;

            case indie::GameState::SPLASH_SCREEN: // To change when splash will be ready
                 this->_gfx->launchIntro();
                this->loading();
                this->process();
                break ;


            case indie::GameState::INGAME:
                this->process();
                break;

            case indie::GameState::MAIN_MENU:
                this->process();
                break;

            case indie::GameState::SCOREBOARD:
                this->process();
                break;

            case indie::GameState::SETTINGS:
                this->process();
                break;

            case indie::GameState::PAUSE_GAME:
                this->process();
                break;

            case indie::GameState::ROOM:
                this->process();
                break ;

            case indie::GameState::ENDGAME:
                this->process();
                break ;

            case indie::GameState::NONE:
            default:
                break ;

        } // switch

  }
}
