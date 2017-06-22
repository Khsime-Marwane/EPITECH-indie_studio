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
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <thread>
#include <array>
#include <cmath>

#include "irr/irrlicht.h"
#include "Interfaces/IGfx.hpp"
#include "Common/common.hpp"
#include "Graphical/Model.hpp"
#include "Game/Scene.hpp"
#include "Game/Map.hpp"
#include "Graphical/irrEventsOverlay.hpp"
#include "Sound/SoundManager.hpp"
#include "Exception/exception.hpp"
#include "GfxContainers.hpp"
#include "Game/ModelsId.hpp"

namespace indie
{

    // GLOBAL PARAMETERS
    # define FULLSCREEN         TRUE
    # define SCREEN_WIDTH       1920
    # define SCREEN_HEIGHT      1080
    # define DEBUG_MODE         FALSE
    # define DEFAULT_FONT       0
    // COLORS
    const irr::video::SColor  SBlack(255, 0, 0, 0);
    const irr::video::SColor  SWhite(255, 255, 255, 255);
    const irr::video::SColor  SRed(255, 255, 0, 0);
    const irr::video::SColor  SGreen(255, 0, 255, 0);
    const irr::video::SColor  SBlue(255, 0, 0, 255);
	const irr::video::SColor  SYellow(255, 255, 255, 0);
	const irr::video::SColor  SMagenta(255, 255, 0, 255);
	const irr::video::SColor  SCyan(255, 0, 255, 255);
    const irr::video::SColor  Trr(0, 0, 0, 0);

    class Gfx : public indie::IGfx {

        ///
        /// \enum EDIRECTION
        ///	\brief Indicate the direction where the model is looking at.
        ///
        enum EDIRECTION {

            IRR_NORTH = 0,
            IRR_EAST = 1,
            IRR_SOUTH = 2,
            IRR_WEST = 3

        };

        //
        // Member Functions
        //
        public:
            //  Constructor / Destructor
            Gfx();
            virtual ~Gfx();

            // Interfaces

            //  Main
            virtual void        display();
            virtual void        clear();
            // SplashScreen
            virtual void        launchIntro();
            //  Events
            virtual bool        pollEvents(std::vector<Event> &events);
            //  Sound
            virtual bool        doesSupportSound() const;
            virtual void        loadSounds(std::unique_ptr<std::vector<std::pair<std::string, SoundType > > > sounds);
            virtual void        soundControl(const Sound &sound);
            //  Scene
            virtual void        loadScenes(std::unique_ptr<std::vector<std::unique_ptr<IScene> > > scene);
            //  Sprites
            virtual void        loadSprites(std::unique_ptr<std::vector<std::unique_ptr<ISprite> > > sprites);
            //  Models
            virtual void        loadModels(std::unique_ptr<std::vector<std::unique_ptr<IModel> > > models);
            virtual std::vector<AnimationState>  getObjectsAnimationState() const;
            //  FONTS
            virtual void        loadFonts(const std::vector<std::string> &fonts_to_load = std::vector<std::string>());
            //  GUI
            virtual void        updateGUI(const IGUI &gui);
            //  Map
            virtual void        updateMap(const IMap &map);
            //  Not allowed
            Gfx &operator=(const Gfx& gfx) = delete;
            Gfx(const Gfx &gfx) = delete;

        private:

            // Scene appearance
            virtual void        update_scene(std::size_t);
            virtual void        update_dome(const std::string &);

            // Window Settings
            void                set_window_settings();

            // Game Info
            void                displayGraphicalInfos();

            // Camera Management
            void                set_camera_pov(const IMap &map);

            // Update and Drawing
            void                draw_model(const ITile &tile, std::size_t x, std::size_t z, std::size_t index);
            void                draw_component_sprite(const IComponent &cmp);
            void                draw_dome();
            void                draw_component_text(const IComponent &cmp);
            void                draw_text(const std::string &txt,
                                          double x, double y,
                                          const irr::video::SColor &txtColor = irr::video::SColor(255,0,0,0),
                                          const irr::video::SColor &bgColor = irr::video::SColor(255,255,255,255));
            void                play_animation(const std::vector<std::string> &frames);

            void                refresh_objects_id(const std::vector<std::size_t> &objects);
            void                delete_old_nodes();

            // Utils
            irr::video::SColor  getSColor(const Color &color) const;
            double              get_real_posX(double pos) const noexcept;
            double              get_real_posY(double pos) const noexcept;

            template < class T >
            irr::core::vector3df    get_mesh_size(T const *mesh) const {
                return mesh->getTransformedBoundingBox().getExtent();
            }

            template < class T >
            void    set_mesh_dimensions(T *mesh, const irr::core::vector3df &size) {

                irr::core::vector3df        edges_length = mesh->getTransformedBoundingBox().getExtent();
                irr::core::vector3df        current_scale = mesh->getScale();

                mesh->setScale( irr::core::vector3df({

                    (current_scale.X * size.X) / edges_length.X,
                    (current_scale.Y * size.Y) / edges_length.Y,
                    (current_scale.Z * size.Z) / edges_length.Z

                }));

            }

        //
        // Member Variables
        //
        public:
            // move in private, here for the moment for debug


            // Irrlicht Items
            std::unique_ptr<irr::IrrlichtDevice>                _device;
            irr::video::IVideoDriver                            *_driver;
            irr::scene::ISceneManager                           *_smgr;
            irr::scene::ICameraSceneNode                        *_camera;
            irr::gui::IGUIEnvironment                           *_guienv;
            std::vector<irr::gui::IGUIFont *>                   _fonts;

            // Events
            irrEventOverlay                                     _eventsOverlay;

            // Scene Management
            std::vector<SceneContainer>                         _scenesLoaded;
            irr::video::ITexture                                *_dome;

            // Models Management
            std::unordered_map<std::size_t, MeshContainer>      _meshesLoaded;
            std::unordered_map<std::size_t, NodeContainer>      _nodesLoaded;
            std::vector<std::size_t> _objectsId;


            // Sound Manager
            SoundManager                                        _soundManager;

            // Sprites
            std::unordered_map<std::size_t, std::vector<irr::video::ITexture *> >   _sprites;

            // Utils
            const std::array< float, 4 >                        _orientation;
            GfxInfos                                            _infos;
            bool                                                _introFinished;
    };

}

# endif //  GFX_HPP
