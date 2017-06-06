//
// Author: Maud Marel
// Date: 2017-05-23 14:09:04
//

#include <iostream>
#include <chrono>
#include <thread>
#include <memory>
#include "Core/Core.hpp"

indie::Core::Core() : _gameState(indie::GameState::MENU), _gameLoad(), _sounds()
{
}

indie::Core::~Core()
{
}

indie::Core::Core(Core const &copy) : _gameState(copy._gameState), _gameLoad(copy._gameLoad), _sounds(copy._sounds)
{
  (void)copy;
}

indie::Core &indie::Core::operator=(Core const &copy)
{
    if (&copy == this) return *this;
    (void)copy;
    return (*this);
}

indie::GameState    indie::Core::getGameState() const
{
    return (_gameState);
}

void    indie::Core::setGameState(const indie::GameState state)
{
    _gameState = state;
}

void    indie::Core::load_sound_lib()
{
    _sounds = _gameLoad->getSoundsToPlay();
}

void    indie::Core::getEventGame(indie::Gfx &_gfx)
{
    Event event;
    std::vector<Event> _events;

    if (_gfx.pollEvents(event))
    {
      _events.push_back(event);
      _gameLoad->notifyEvent(std::move(_events));
    }
}

void    indie::Core::display_game(indie::Gfx &_gfx)
{
    getEventGame(_gfx);
    _gameLoad->process();
    for (std::vector<indie::Sound>::const_iterator it = _sounds.begin(); it != _sounds.end(); it++)   
        _gfx.soundControl(*it);       

    // TODO : CHECK LOAD ATTEMPT
    _gfx.loadSprites(_gameLoad->getSpritesToLoad());
    _gfx.loadModels(_gameLoad->getModelsToLoad());
    _gfx.updateMap(_gameLoad->getCurrentMap());
    _gfx.updateGUI(_gameLoad->getGUI());
    _gfx.display();
}

void    indie::Core::display_menu(indie::Gfx &_gfx)
{
    std::cout << "DISPLAY MENU" << std::endl;
    (void)_gfx;
}

void    indie::Core::display_loop()
{
    int state;
    indie::Gfx _gfx;
    //_gameLoad = 

    /*
    ** Loop en fonction des GameState
    */
    while ((state = getGameState()) != indie::GameState::QUIT)
    {
        _gfx.clear();
        switch(state)
        {
            case indie::GameState::LOADING :
            {
                std::cout << "LOADING" << std::endl;
                load_sound_lib();
                break;
            }
            case indie::GameState::INGAME :
            {
                std::cout << "INGAME" << std::endl;
                display_game(_gfx);
                break;
            }
            case indie::GameState::MENU :
            {
                std::cout << "MENU" << std::endl;
                display_menu(_gfx);
                break;
            }
            default:
                break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void    indie::Core::display()
{

    std::cout << "display Core" << std::endl;

    //display_loop(_gfx);
}
