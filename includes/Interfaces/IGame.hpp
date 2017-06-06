//
// Author: Marwane Khsime 
// Date: 2017-05-05 05:01:47 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-05 05:01:47
//

#ifndef IGAME_H
#define IGAME_H

#include <vector>
#include <string>
#include <memory>

#include "Event.hpp"
#include "GameState.hpp"
#include "IStat.hpp"
#include "IMap.hpp"
#include "IGUI.hpp"
#include "ISprite.hpp"
#include "Sound.hpp"
#include "IModel.hpp"

namespace indie
{
  ///
  /// \class IGame
  /// \brief Interface of the Bomberman for the Core program
  ///
  /// This interface will be used by the Core program to manipulate
  /// a game, here the Bomberman, but without knowing any detail about it
  /// The Core will always do "request" to the game, to get
  /// information or ask for processing a game loop, for example.
  /// The IGame will never have a reference to the Core, or
  /// communicate directly with it. Never. Ever.
  ///
  class IGame
  {
    public:
        ///
        /// \fn virtual ~IGame()
        /// \brief Virtual destructor of the interface
        ///
        virtual ~IGame(){};

        // Game state
        ///
        /// \fn virtual GameState getGameState() const = 0
        /// \brief Ask the current game state to the game
        ///
        virtual GameState getGameState() const = 0;

        // Events
        ///
        /// \fn virtual void notifyEvent(std::vector<Event> &&events) = 0
        /// \brief Send events (keyboard, mouse, etc) to the game
        ///
        virtual void notifyEvent(std::vector<Event> &&events) = 0;

/*
        NETWORK PART, working in progress about the architecture

        ///
        /// \fn virtual bool hasNetwork() const = 0
        /// \brief Does network available ?
        ///
        virtual bool hasNetwork() const = 0;

        // Network
        ///
        /// \fn virtual void notifyNetwork(std::vector<NetworkPacket> &&events) = 0
        /// \brief Send network packets to the game
        ///

        virtual void notifyNetwork(std::vector<NetworkPacket> &&events) = 0;

        ///
        /// \fn virtual std::vector<NetworkPacket> &&getNetworkToSend() = 0
        /// \brief Get the network packet to send from the game to the server
        ///
        virtual std::vector<NetworkPacket> getNetworkToSend() = 0;

*/

        // Process
        ///
        /// \fn virtual void process() = 0
        /// \brief Make the game process a game loop
        ///
        virtual void process() = 0;

        // Sprites
        ///
        /// \fn virtual std::vector<std::unique_ptr<ISprite> > getSpritesToLoad() const = 0
        /// \brief get the list of Sprites to load.
        ///
        virtual std::vector<std::unique_ptr<ISprite> > getSpritesToLoad() const = 0;

        // Models
        ///
        /// \fn virtual std::vector<std::unique_ptr<IModel> > getModelsToLoad() const = 0
        /// \brief get the list of Models to load.
        ///
        virtual std::vector<std::unique_ptr<IModel> > getModelsToLoad() const = 0;
        ///
        /// \fn virtual std::vector<size_t> getObjectsId() const = 0
        /// \brief get the list of objects currently in game.
        /// This function is used to indicate to the GFX what objects are still in play
        /// so that they do not have to recreate them.
        ///
        virtual std::vector<size_t> getObjectsId() const = 0;

        // Sound
        ///
        /// \fn virtual std::vector<std::string> getSoundsToLoad() const = 0
        /// \brief get the list of sound files to load.
        ///
        virtual std::vector<std::pair<std::string, SoundType> > getSoundsToLoad() const = 0;

        ///
        /// \fn     virtual std::vector<Sound> getSoundsToPlay() = 0
        /// \brief Get the sounds to play
        ///
        virtual std::vector<Sound> getSoundsToPlay() = 0;
        /* You should return by std::move to not copy your vector and to clear it at the same time */

        // Map
        ///
        /// \fn virtual IMap const &getCurrentMap() const = 0
        /// \brief Get the current version of the map
        ///
        virtual IMap const &getCurrentMap() const = 0;

        // GUI
        ///
        /// \fn virtual IGUI &getGUI() = 0
        /// \brief Get the current version of the GUI to display
        ///
        virtual IGUI &getGUI() = 0;

        // Level
        ///
        /// \fn virtual std::size_t getFlor() const = 0
        /// \brief Get the current flor for the scene level
        ///
        virtual std::size_t getFlor() const = 0;

  };
}

#endif // !IGAME_H