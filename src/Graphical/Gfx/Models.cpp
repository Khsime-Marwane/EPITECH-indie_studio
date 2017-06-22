//
// Author: Marwane Khsime
// Date: 2017-05-29 18:49:20
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-05-29 18:49:20
//

#include "Graphical/Gfx.hpp"

void    indie::Gfx::delete_old_nodes() {

    std::unordered_map<std::size_t, NodeContainer>::iterator it = this->_nodesLoaded.begin();

    while (it != this->_nodesLoaded.end()) {

       if ((std::find(this->_objectsId.begin(), this->_objectsId.end(), it->second.id)) == this->_objectsId.end())
       {
           it->second.node->remove();
           it = this->_nodesLoaded.erase(it);
       } else {
           ++it;
       }

    }

}

void        indie::Gfx::refresh_objects_id(const std::vector<std::size_t> &objects) {
    this->_objectsId.clear();
    this->_objectsId = objects;
}

void        indie::Gfx::loadModels(std::unique_ptr<std::vector<std::unique_ptr<IModel> > > models) {

    // Clear old Models
    this->_meshesLoaded.clear();

    // Load new ones
    for (std::size_t i = 0; i < models->size(); ++i) {

        MeshContainer   container;

        if (!(container.mesh = this->_smgr->getMesh(models->at(i)->getMeshPath().c_str())))
            throw indie::IndieError(_INDIE_GFX_MESH_FAILED);

        this->_meshesLoaded[i] = container;
    }

}

std::vector<indie::AnimationState>  indie::Gfx::getObjectsAnimationState() const {

    std::vector<AnimationState>  list;

    for ( std::unordered_map<std::size_t, NodeContainer>::const_iterator it = this->_nodesLoaded.begin(); it != this->_nodesLoaded.end(); ++it) {

        // Checks whether the object has completed its animation or not
        if (it->second.node &&
            it->second.node->getFrameNr() ==
                static_cast<irr::f32>(it->second.frameLoop.second) ) {

            list.push_back( { it->second.id, true } );   // Completed

        } else {    // Or not

            list.push_back( { it->second.id, false });

        }

    }

    return list;

}
