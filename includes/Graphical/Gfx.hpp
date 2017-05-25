//
// Author: Marwane Khsime 
// Date: 2017-05-05 17:41:58 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-05 17:41:58
//

#ifndef GFX_HPP
# define GFX_HPP

#include <string>
#include <iostream>

#include "Interfaces/IGfx.hpp"
#include "Exception/exception.hpp"
#include "Common/common.hpp"
#include "irr/irrlicht.h"

namespace indie
{

    #define SOUND_SUPPORTED TRUE

    class Gfx : public indie::IGfx {

        public:
            //  Constructor / Destructor
            Gfx();
            virtual ~Gfx();

            // Interfaces

            //  Main
            virtual void    display();
            virtual void    clear();
            //  Events
            virtual bool    pollEvents(Event &e);
            //  Sound
            virtual bool    doesSupportSound() const;
            virtual void    loadSounds(std::vector<std::pair<std::string, SoundType > > const &sounds);
            virtual void    soundControl(const Sound &sound);
            // Sprites
            virtual void    loadSprites(std::vector<std::unique_ptr<ISprite> > &&sprites);
            //  Map
            virtual void    updateMap(IMap const &map);
            // IGUI
            virtual void    updateGUI(IGUI &gui);
            //  Forbidden
            void            operator=(const Gfx& gfx) = delete;
            Gfx(const Gfx &gfx) = delete;

            std::unique_ptr<irr::IrrlichtDevice>        _device;
            irr::video::IVideoDriver                    *_driver;
            irr::scene::ISceneManager                   *_smgr;
            irr::gui::IGUIEnvironment                   *_guienv;

        private:

    };

}

# endif //  GFX_HPP
