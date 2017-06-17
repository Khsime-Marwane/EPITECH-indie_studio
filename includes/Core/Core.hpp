//
// Core.hh for coore in /home/marelm/EPITECH/Projects_tek2/C++_II/cpp_indie_studio
//
// Made by maud.marel@epitech.eu
// Login   <maud.marel@epitech.eu>
//
// Started on  Thu May  4 16:03:42 2017 maud.marel@epitech.eu
// Last update Tue Jun  6 15:53:13 2017 maud.marel@epitech.eu
//

#ifndef CORE_HPP_
# define CORE_HPP_

#include <chrono>
#include <thread>
         
#include "Interfaces/GameState.hpp"
#include "Graphical/Gfx.hpp"
#include "Game/Game.hpp"
#include "Interfaces/IGame.hpp"
#include "Interfaces/Sound.hpp"

namespace indie
{

  class	Core
  {
    public:
      Core();
      ~Core();

      Core(Core const &) = delete;
      Core  &operator=(Core const &) = delete;

      void              runCoreLoop();

    private:

      void              loading();
      void              process();
      void              notifyGame() const;

      std::unique_ptr<indie::IGfx>     _gfx;
      std::unique_ptr<indie::IGame>   _game;
      std::vector<indie::Sound>       _sounds;
      GameState                       _gameState;
  };
}

#endif /* !CORE_HPP_ */
