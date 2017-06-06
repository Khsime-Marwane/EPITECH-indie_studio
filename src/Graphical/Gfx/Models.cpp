//
// Author: Marwane Khsime 
// Date: 2017-05-29 18:49:20 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-29 18:49:20
//

#include "Graphical/Gfx.hpp"

void        indie::Gfx::loadObjectsId(const std::vector<std::size_t> &objects) {
    this->_objectsId.clear();
    this->_objectsId = objects;
}

void        indie::Gfx::loadModels(std::vector<std::unique_ptr<IModel> > &&models) {

    // Clear old Models
    this->_meshesLoaded.clear();

    // Load new ones
    for (std::size_t i = 0; i < models.size(); ++i) {

        MeshContainer   container;

        if (!(container.mesh = this->_smgr->getMesh(models[i]->getMeshPath().c_str())))
            throw indie::IndieError(_INDIE_GFX_MESH_FAILED);

        container.frameSequences = models[i]->getAnimationsFrames();

        this->_meshesLoaded[i] = container;
    }

}
