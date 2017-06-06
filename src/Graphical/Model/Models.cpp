//
// Author: Marwane Khsime 
// Date: 2017-05-29 15:35:12 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-29 15:35:12
//

#include "Graphical/Model.hpp"

indie::Model::Model(const std::string &meshPath,
                    std::vector<std::pair<size_t, size_t> > frameSequences)
    :   _meshPath(meshPath),
        _frameSequences(frameSequences)
{};

std::string indie::Model::getMeshPath() const {
    return this->_meshPath;
}

std::vector<std::pair<size_t, size_t> > indie::Model::getAnimationsFrames() const {
    return this->_frameSequences;
}