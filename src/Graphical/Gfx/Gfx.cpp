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


    try : _device(irr::createDevice (   irr::video::EDT_OPENGL,
                                        irr::core::dimension2d<irr::u32>(800,600),
                                        32,
                                        false,
                                        true,
                                        false,
                                        0)),
          _driver(this->_device->getVideoDriver()),
          _smgr(this->_device->getSceneManager()),
          _guienv(this->_device->getGUIEnvironment())

    {
        
        std::cout << "Launching Irrlicht" << std::endl << std::endl << std::endl;

        this->_device->setWindowCaption(L"BAUNTLET");

        // this->_guienv->addStaticText(L"BAUNTLET",
        //                             irr::core::rect<irr::s32>(10,10,260,22), true);

        irr::scene::IAnimatedMesh   *mesh = this->_smgr->getMesh("models/SkeletonWizard.b3d");

        if (!mesh) {
            this->_device->drop();
            throw indie::exception::Error("Failed to get mesh");
        }

        irr::scene::IAnimatedMeshSceneNode *node = this->_smgr->addAnimatedMeshSceneNode(mesh);

        if (node) {
            node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            node->setMD2Animation(irr::scene::EMAT_STAND);
            node->setMaterialTexture(0, this->_driver->getTexture("textures/blue_wizard.png"));
        }

        irr::SKeyMap keyMap[5];

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

        this->_smgr->addCameraSceneNodeFPS(0, 100.0f, 0.025f, -1, keyMap, 5);

        // this->_smgr->addCameraSceneNode(0,
        //                                 irr::core::vector3df(4.0f, 4.0f, 4.0f),
        //                                 irr::core::vector3df(0.0f, 5.0f, 0.0f));

        while (this->_device->run())
        {
            this->_driver->beginScene(true, true, irr::video::SColor(255, 0, 0, 0));

            this->_smgr->drawAll();
            this->_guienv->drawAll();

            this->_driver->endScene();

        }
    }

    catch (const std::exception &err) {
        throw err;
}

indie::Gfx::~Gfx() {
}

void    indie::Gfx::display() {
    std::cout << "display" << std::endl;
}

void    indie::Gfx::clear() {
    std::cout << "clear" << std::endl;
}
