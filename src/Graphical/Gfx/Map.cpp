//
// Author: Marwane Khsime
// Date: 2017-05-22 19:17:54
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-05-22 19:17:54
//

#include "Graphical/Gfx.hpp"

void    indie::Gfx::draw_model(const ITile &tile, std::size_t x, std::size_t z, std::size_t index) {

    if (this->_nodesLoaded.count(tile.getObjectId(index)) != 0) {

        // Just set Position, Rotation and frames here
        irr::scene::IAnimatedMeshSceneNode  *node = this->_nodesLoaded[tile.getObjectId(index)].node;

        if (tile.doesAnimationChanged(index)) {
            this->_nodesLoaded[tile.getObjectId(index)].frameLoop = tile.getObjectFrameLoop(index);
            node->setFrameLoop(static_cast< irr::s32 >(tile.getObjectFrameLoop(index).first),
                               static_cast< irr::s32 >(tile.getObjectFrameLoop(index).second));
        }

        node->setPosition(irr::core::vector3df(this->_scenesLoaded[this->_infos._current_scene]._startX + static_cast< float >(x) + static_cast< float >(tile.getShiftX(index)),
                                               this->_scenesLoaded[this->_infos._current_scene]._startY,
                                               this->_scenesLoaded[this->_infos._current_scene]._startZ - static_cast< float >(z) - static_cast< float >(tile.getShiftY(index))));


        node->setRotation(irr::core::vector3df(0.0f, this->_orientation[static_cast<std::size_t>(tile.getObjectRotation(index))], 0.0f));

    } else {
        // We create a new one
        NodeContainer           newModel;
        irr::core::vector3df    position(this->_scenesLoaded[this->_infos._current_scene]._startX + static_cast< float >(x) + static_cast< float >(tile.getShiftX(index)),
                                         this->_scenesLoaded[this->_infos._current_scene]._startY,
                                         this->_scenesLoaded[this->_infos._current_scene]._startZ - static_cast< float >(z) - static_cast< float >(tile.getShiftY(index)));
        irr::core::vector3df    rotation(0.0f, this->_orientation[static_cast<std::size_t>(tile.getObjectRotation(index))], 0.0f);

        if ((newModel.node =
                this->_smgr->addAnimatedMeshSceneNode(this->_meshesLoaded[static_cast<std::size_t>(tile.getModelId(index))].mesh,
                                                      NULL,
                                                      1,
                                                      position,
                                                      rotation)) == nullptr)
                throw IndieError(_INDIE_GFX_TEXTURE_FAILED);

        if (newModel.node)
            {
                newModel.node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                newModel.node->setMD2Animation(irr::scene::EMAT_STAND);
                newModel.node->setMaterialTexture(0, this->_driver->getTexture(tile.getObjectTexture(index).c_str()) );
            }

        newModel.id = tile.getObjectId(index);
        newModel.modelId = static_cast< size_t >(tile.getModelId(index));
        newModel.frameLoop = tile.getObjectFrameLoop(index);
        newModel.node->setFrameLoop(static_cast< irr::s32 >(tile.getObjectFrameLoop(index).first),
                                    static_cast< irr::s32 >(tile.getObjectFrameLoop(index).second));
        newModel.node->setCurrentFrame(static_cast< float >(tile.getObjectFrameLoop(index).first));
        newModel.node->setLoopMode(false);
        this->_nodesLoaded[tile.getObjectId(index)] = newModel;
    }

}

void    indie::Gfx::updateMap(const IMap &map) {

    std::size_t nbLayers    = map.getLayerNb();
    std::size_t map_width   = map.getWidth();
    std::size_t map_height  = map.getHeight();

    // If the scene has changed, we update it
    if (map.getSceneId() != this->_infos._current_scene || !this->_infos._scene_loaded_once) {
        this->update_scene(map.getSceneId());
        this->_infos._current_scene = map.getSceneId();
        this->_infos._scene_loaded_once = true;
    }

    // Delete nodes unused
    this->refresh_objects_id(map.getObjectsId());
    this->delete_old_nodes();

    // Camera POV
    this->set_camera_pov(map);

    // Layers
    for (std::size_t layer = 0; layer < nbLayers; ++layer) {

        for (std::size_t y = 0; y < map_height; ++y) {

            // Note : we named the variable z because the x-axis of the map
            // corresponds to the z-axis on our 3d planes
            for (std::size_t z = 0; z < map_width; ++z) {

                // Here we loop on the tile to get all elements that are on it.
                for (std::size_t index = 0, thickness = map.at(layer, z, y).getTileSize();
                     thickness > 0 && index < thickness;
                     ++index) {

                    if (map.at(layer, z, y).hasModel(index)) {
                        this->draw_model(map.at(layer, z, y), z, y, index);
                    }

                }

            }

        }

    }

    this->_smgr->drawAll();

    return ;
}
