//
// Author: Marwane Khsime 
// Date: 2017-05-22 19:17:54 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-22 19:17:54
//

#include "Graphical/Gfx.hpp"

void    indie::Gfx::draw_cube(const ITile &tile, std::size_t x, std::size_t y) {
    (void)tile;
    (void)x;
    (void)y;
}

void    indie::Gfx::draw_model(const ITile &tile, std::size_t x, std::size_t y) {

    (void)x;(void)y;(void)tile;
    if (this->_nodesLoaded.count(tile.getModelId()) != 0) {

        // Just set Position and frames
        irr::scene::IAnimatedMeshSceneNode  *node = this->_nodesLoaded[tile.getModelId()].node;

        if (tile.doesAnimationChanged())
            node->setFrameLoop(static_cast< irr::s32 >(tile.getModelFrameLoop().first),
                               static_cast< irr::s32 >(tile.getModelFrameLoop().second));
        
        node->setPosition(irr::core::vector3df(static_cast< float >(x),
                                               static_cast< float >(y),
                                               10.0f));
    } else {

        // We create a new one
        NodeContainer           newModel;
        irr::core::vector3df    position(static_cast< float >(x),
                                         static_cast< float >(y),
                                         10.0f);
        irr::core::vector3df    rotation(0.0f, 0.0f, 0.0f);

        if ((newModel.node =
                this->_smgr->addAnimatedMeshSceneNode(this->_meshesLoaded[0].mesh,
                                                      NULL,
                                                      1,
                                                      position,
                                                      rotation)) == nullptr)
                throw IndieError(_INDIE_GFX_TEXTURE_FAILED);

        newModel.id = tile.getModelId();
        newModel.node->setFrameLoop(static_cast< irr::s32 >(tile.getModelFrameLoop().first),
                                    static_cast< irr::s32 >(tile.getModelFrameLoop().second));
        newModel.node->setCurrentFrame(static_cast< float >(tile.getModelFrameLoop().first));
        this->_nodesLoaded[tile.getModelId()] = newModel;
    }

}

void    indie::Gfx::delete_old_nodes() {

    std::unordered_map<std::size_t, NodeContainer>::iterator it;

    for (it = this->_nodesLoaded.begin(); it != this->_nodesLoaded.end(); ++it) {

       if ((std::find(this->_objectsId.begin(), this->_objectsId.end(), it->second.id)) == this->_objectsId.end())
       {
           it->second.node->remove();
           this->_nodesLoaded.erase(it);
       }

    }

}

void    indie::Gfx::updateMap(const IMap &map) {

    std::size_t nbLayers    = map.getLayerNb();
    std::size_t map_width   = map.getWidth();
    std::size_t map_height  = map.getHeight();

    // Delete nodes unused
    this->delete_old_nodes();

    // Layers
    for (std::size_t layer = 0; layer < nbLayers; ++layer) {

        for (std::size_t y = 0; y < map_height; ++y) {

            for (std::size_t x = 0; x < map_width; ++x) {

                // To change when tile will be ready
                // Tile   tile = map.at(layer, x, y);

                if (map.at(layer, x, y).hasModel())
                    this->draw_model(map.at(layer, x, y), x, y);
                else
                    this->draw_cube(map.at(layer, x ,y ), x, y);

            }

        }

    }

    return ;
}