//
// Author: Marwane Khsime 
// Date: 2017-06-05 07:42:19 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-05 07:42:19
//

#include "Graphical/Gfx.hpp"

void    indie::Gfx::draw_dome() {

    if (this->_dome) {

    irr::core::rect<irr::s32>   position(0,
                                            0,
                                            static_cast<irr::s32>(this->get_real_posX(1.0)),
                                            static_cast<irr::s32>(this->get_real_posY(1.0))
                                        );
    irr::core::rect<irr::s32>   sprite_area(0,
                                            0,
                                            this->_dome->getSize().Width,
                                            this->_dome->getSize().Height
                                            );
    this->_driver->draw2DImage( this->_dome,
                                position,
                                sprite_area,
                                0,
                                NULL,
                                true);
    }
}

void    indie::Gfx::update_dome(const std::string &dome) {

    irr::video::ITexture *image;

    image = this->_driver->getTexture(dome.c_str());

    if (image) {

        this->_dome = image;

    } // End Drawing Frame

    else {
        std::cout << _INDIE_GFX_DOME_FAILED << std::endl;
    }

}

void    indie::Gfx::update_scene(std::size_t scene) {

    if (scene >= this->_scenesLoaded.size()) {
        std::cerr << _INDIE_GFX_SCENE_IS_INVALID << std::endl;
    }

    for (std::size_t i = 0; i < this->_scenesLoaded.size(); ++i) {

        for (std::size_t j = 0; j < this->_scenesLoaded.at(i)._scene.size(); ++j) {

            if (scene == i) {
                this->_scenesLoaded.at(i)._scene.at(j).second->setVisible(true);
            } else {
                this->_scenesLoaded.at(i)._scene.at(j).second->setVisible(false);
            }
        }

        if (scene == i)
            this->update_dome(this->_scenesLoaded.at(i)._dome);
    }

}

void    indie::Gfx::loadScenes(std::unique_ptr<std::vector<std::unique_ptr<indie::IScene> > > scenes) {


    // Clear the old Scene
    for (std::size_t i = 0; i < this->_scenesLoaded.size(); ++i) {
        
        for (std::size_t j = 0; j < this->_scenesLoaded.at(i)._scene.size(); ++j) {
            this->_scenesLoaded.at(i)._scene.at(j).second->remove();
        }
        this->_scenesLoaded.at(i)._scene.clear();

    }

    this->_scenesLoaded.clear();

    for (std::size_t i = 0; i < scenes->size(); ++i) {
        
        indie::SceneContainer   scene_container( std::vector<
                                                    std::pair<irr::scene::IMesh *,
                                                    irr::scene::IMeshSceneNode *>
                                                 >(),
                                                 scenes->at(i)->getDome(),
                                                 scenes->at(i)->getStartX(),
                                                 scenes->at(i)->getStartY(),
                                                 scenes->at(i)->getStartZ() );

        for (std::size_t j = 0; j < scenes->at(i)->getNumberParts(); ++j) {

            irr::scene::IMesh   *mesh = this->_smgr->getMesh(scenes->at(i)->getScenePartAtPos(j).first.c_str());

            if (!mesh) {
                throw IndieError(_INDIE_GFX_MESH_FAILED);
            }

            irr::scene::IMeshSceneNode *node =
                this->_smgr->addMeshSceneNode(mesh,
                                              NULL,
                                              1,
                                              irr::core::vector3df(0.0f, 0.0f, 0.0f),
                                              irr::core::vector3df(0.0f, 0.0f, 0.0f));

            if (node) {
                node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                node->setMaterialTexture(0, this->_driver->getTexture(scenes->at(i)->getScenePartAtPos(j).second.c_str()));
            } else {
                std::cerr << _INDIE_GFX_TEXTURE_FAILED << std::endl;
            }

            node->setVisible(false);

            scene_container._scene.push_back( { mesh, node } );
        }

        scene_container._dome = scenes->at(i)->getDome();
        this->_scenesLoaded.push_back(scene_container);
    }

}