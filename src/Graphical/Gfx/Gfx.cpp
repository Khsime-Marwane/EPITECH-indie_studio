//
// Author: Marwane Khsime
// Date: 2017-05-05 17:53:29
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-05-05 17:53:29
//

#include "Graphical/Gfx.hpp"

indie::Gfx::Gfx()

    // irr::createDevice (deviceType, windowSize, bits, fullscreen, stencilbuffer, vsync, receiver)

    try : 
          // Device
          _device(irr::createDevice (   irr::video::EDT_OPENGL,
                                        irr::core::dimension2d<irr::u32>(SCREEN_WIDTH, SCREEN_HEIGHT),
                                        32,
                                        false,
                                        true,
                                        false,
                                        NULL) ),
          // Irrlicht Items
          _driver(this->_device->getVideoDriver()),
          _smgr(this->_device->getSceneManager()),
          _camera(),
          _guienv(this->_device->getGUIEnvironment()),
          // Font
          _fonts(),
          // Events Management
          _eventsOverlay(),
          // Scenes Management
          _scenesLoaded(),
          _dome(),
          // Models Management
          _meshesLoaded(),
          _nodesLoaded(),
          _objectsId(),
          // Sound
          _soundManager(),
          // Sprites Management
          _sprites(),
          // Utils
          // ------------   N       E      S      W
          _orientation( { 180.0f, 270.0f, 0.0f, 90.0f }),
          _infos(0),
          _introFinished(false)
    {

        std::cout << "Launching Irrlicht GFX" << std::endl;

        this->_device->setWindowCaption(L"BAUNTLET");

/*        irr::SKeyMap keyMap[5];

        keyMap[0].Action = irr::EKA_MOVE_FORWARD;
        keyMap[0].KeyCode = irr::KEY_KEY_Z;
        keyMap[1].Action = irr::EKA_MOVE_BACKWARD;
        keyMap[1].KeyCode = irr::KEY_KEY_S;
        keyMap[2].Action = irr::EKA_STRAFE_LEFT;
        keyMap[2].KeyCode = irr::KEY_KEY_Q;
        keyMap[3].Action = irr::EKA_STRAFE_RIGHT;
        keyMap[3].KeyCode = irr::KEY_KEY_D;
        keyMap[4].Action = irr::EKA_JUMP_UP;
        keyMap[4].KeyCode = irr::KEY_SPACE;

        this->_camera = this->_smgr->addCameraSceneNodeFPS(0, 100.0f, 0.025f, -1, keyMap, 5);
*/
         this->_camera = this->_smgr->addCameraSceneNode(NULL,
                                                        //                    x     y     z
                                                        irr::core::vector3df(0.0f, 0.0f, 0.0f), // Position
                                                        irr::core::vector3df(0.0f, 0.0f, 0.0f)  // Angle
                                                        );

        this->set_window_settings();
    }

    catch (const std::exception &err) {
        std::cerr << err.what() << std::endl;
        throw err;
}

indie::Gfx::~Gfx() {}

void    indie::Gfx::display() {

    if (this->_device->run())
    {

        this->_guienv->drawAll();

        #if DEBUG_MODE
            this->displayGraphicalInfos();
        #endif

        this->_driver->endScene();

    }   else {

        throw indie::IndieError(_INDIE_GFX_DEVICE_IS_OFF);

    }

}

void    indie::Gfx::clear() {
    this->_driver->beginScene(true, true, SBlack);
}

void    indie::Gfx::set_window_settings() {

    // Hide Cursor
    this->_device->getCursorControl()->setVisible(false);

    // Load Default Font
    this->loadFonts();

    // Set Event Receiver
    this->_device->setEventReceiver(&this->_eventsOverlay);

    // Image Quality
    this->_driver->setTextureCreationFlag (irr::video::ETCF_OPTIMIZED_FOR_QUALITY, true);

    // Desable Log
    this->_device->getLogger()->setLogLevel(irr::ELL_WARNING);
}

void    indie::Gfx::displayGraphicalInfos() {

    //  Camera Position
    irr::core::vector3df posCam = this->_camera->getPosition();
    std::string camTxt = "CAMERA POS ( " +  std::to_string(posCam.X) + ", " +
                                            std::to_string(posCam.Y) + ", " +
                                            std::to_string(posCam.Z) + " )";
    this->draw_text(camTxt, 0.0f, 0.0f, SGreen, SBlack);

    irr::core::vector3df pos = this->_camera->getAbsolutePosition();
    irr::core::vector3df target = this->_camera->getTarget();
    irr::core::vector3df dir = target - pos;

    std::string dirTxt = "CAMERA ANGLE ( " +  std::to_string(dir.X) + ", " +
                                              std::to_string(dir.Y) + ", " +
                                              std::to_string(dir.Z) + " )";
    this->draw_text(dirTxt, 0.0f, 0.025f, SGreen, SBlack);

    //  FPS
    std::string fpsTxt("FPS : " + std::to_string(this->_driver->getFPS()));
    this->draw_text(fpsTxt, 0.0f, 0.050f, SGreen, SBlack);
}
