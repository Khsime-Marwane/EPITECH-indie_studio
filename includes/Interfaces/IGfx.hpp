//
// Author: Marwane Khsime 
// Date: 2017-05-24 03:51:40 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-24 03:51:40
//

#ifndef IGFX_H
# define IGFX_H

#include <vector>
#include <string>
#include <memory>

#include "Event.hpp"
#include "Sound.hpp"
#include "IScene.hpp"
#include "ISprite.hpp"
#include "IModel.hpp"
#include "IMap.hpp"
#include "IGUI.hpp"

namespace indie
{
  ///
  /// \class IGfx
  /// \brief Interface of the graphic lib for the Core program
  ///
  /// This interface will be used by the Core program to manipulate
  /// the irrlicht library.
  /// The Core will always do "request" to the lib, to get
  /// information or ask for displaying the map and GUI, for example.
  /// The IGfxLib will never have a reference to the Core, or
  /// communicate directly with it. Never. Ever.
  ///
  class IGfx
  {
    public:
        ///
        /// \fn virtual ~IGfxLib()
        /// \brief Virtual destructor of the interface.
        ///
        virtual ~IGfx() {};

        // Events
        ///
        /// \fn virtual bool pollEvents(Event &e) = 0
        /// \brief Function to poll events from the graphic lib
        ///
        /// If there is an event to poll, it is filled and true is returned.
        /// If not, false is returned.
        ///
        virtual bool pollEvents(Event &e) = 0;

        // Sound
        ///
        /// \fn virtual bool doesSupportSound() const = 0
        /// \brief Ask if the library support sound
        ///
        virtual bool doesSupportSound() const = 0;
        ///
        /// \fn virtual void loadSounds(std::vector<std::pair<std::string, SoundType > > const &sounds) = 0
        /// \brief Ask the lib to remove and load new sounds
        ///
        virtual void loadSounds(std::vector<std::pair<std::string, SoundType > > const &sounds) = 0;
        ///
        /// \fn virtual void soundControl(const Sound &sound) = 0
        /// \brief Ask the lib to play a sound
        ///
        virtual void soundControl(const Sound &sound) = 0;

        // Fonts
        ///
        /// \fn virtual void &loadFonts(std::vector<std::string> const &Fonts = std::vector<std::string>()) = 0
        /// \brief Load Fonts in the lib from the paths given by the game
        /// \param Fonts to pass the path of the Font to give the lib
        ///        the way to search the assets. If there is no parameter, the default
        ///        font of the lib will be loaded.
        virtual void loadFonts(const std::vector<std::string> &fonts = std::vector<std::string>()) = 0;

        // Models
        ///
        /// \fn virtual void loadScene(std::unique_ptr<IScene> &&scene) = 0
        /// \brief Load Scene in the lib from the paths given by the game
        /// \param Scene to pass the path of the meshes and textures to give the lib
        ///        the way to search the assets
        virtual void loadScene(std::vector<std::unique_ptr<IScene> > &&scene) = 0;

        // Sprites
        ///
        /// \fn virtual void loadSprites(std::vector<std::string> const &Sprites) = 0
        /// \brief Load Sprites in the lib from the paths given by the game
        /// \param Sprites to pass the path of the Sprites to give the lib
        ///        the way to search the assets
        virtual void loadSprites(std::vector<std::unique_ptr<ISprite> > &&sprites) = 0;

        // Models
        ///
        /// \fn virtual void loadModels(std::vector<std::unique_ptr<IModel> > &&models) = 0
        /// \brief Load Models in the lib from the paths given by the game
        /// \param Models to pass the path of the Sprites to give the lib
        ///        the way to search the assets
        virtual void loadModels(std::vector<std::unique_ptr<IModel> > &&models) = 0;

        // Map
        ///
        /// \fn virtual void updateMap(IMap const &map) = 0
        /// \brief Updates the map (no direct display changes are made here)
        ///
        virtual void updateMap(IMap const &map) = 0;

        // GUI
        ///
        /// \fn virtual void updateGUI(IGUI &gui) = 0
        /// \brief Updates the GUI (no direct display changes are made here)
        ///
        virtual void updateGUI(IGUI &gui) = 0;

        // GUI
        ///
        /// \fn virtual void updateLevel(std::size_t flor) = 0
        /// \brief Updates the scene appearance
        ///
        virtual void updateFlor(std::size_t) = 0;

        // Display
        ///
        /// \fn virtual void display() = 0
        /// \brief Display the map and GUI.
        ///
        virtual void display() = 0;

        // Clear
        ///
        /// \fn virtual void clear() = 0
        /// \brief Ask the lib to clear the screen
        ///
        virtual void clear() = 0;
  };
}

#endif // !IGFX_H
