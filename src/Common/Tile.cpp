//
// Author: Marwane Khsime 
// Date: 2017-06-04 05:32:25 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-04 05:32:25
//

#include "Common/Tile.hpp"

indie::Tile::Tile(const Color &color,
                  bool hasModel,
                  std::size_t meshId,
                  std::size_t modelId,
                  ELookAt rotation,
                  const std::string &texture,
                  bool animationChanged,
                  std::pair<size_t, size_t> frameLoop,
                  double shiftX,
                  double shiftY)

    : _color(color),
      _hasModel(hasModel),
      _meshId(meshId),
      _modelId(modelId),
      _modelRotation(rotation),
      _modelTexture(texture),
      _doesAnimationChanged(animationChanged),
      _modelFrameLoop(frameLoop),
      _shiftX(shiftX),
      _shiftY(shiftY)

{

}

indie::Color        indie::Tile::getColor() const { return this->_color; }
void                indie::Tile::setColor(const Color &color) { this->_color = color; }

bool                indie::Tile::hasModel() const { return this->_hasModel; }
void                indie::Tile::setHasModel(bool hm) { this->_hasModel = hm; }

std::size_t         indie::Tile::getMeshId() const { return this->_meshId; }
void                indie::Tile::setMeshId(std::size_t id) { this->_meshId = id; }

std::size_t         indie::Tile::getModelId() const { return this->_modelId; }
void                indie::Tile::setModelId(std::size_t id) { this->_modelId = id; }

indie::ELookAt      indie::Tile::getModelRotation() const { return this->_modelRotation; }
void                indie::Tile::setModelRotation(indie::ELookAt look) { this->_modelRotation = look; }

std::string         indie::Tile::getModelTexture() const { return this->_modelTexture; }
void                indie::Tile::setModelTexture(const std::string &texture) { this->_modelTexture = texture; }

bool                indie::Tile::doesAnimationChanged() const { return this->_doesAnimationChanged; }
void                indie::Tile::setDoesAnimationChanged(bool v) { this->_doesAnimationChanged = v; }

std::pair<std::size_t, std::size_t> indie::Tile::getModelFrameLoop() const { return this->_modelFrameLoop; }
void                indie::Tile::setModelFrameLoop(const std::pair<std::size_t, std::size_t> &fl) { this->_modelFrameLoop = fl; }

double              indie::Tile::getShiftX() const { return this->_shiftX; }
void                indie::Tile::setShiftX(double x) { this->_shiftX = x; }

double              indie::Tile::getShiftY() const { return this->_shiftY; }
void                indie::Tile::setShiftY(double y) { this->_shiftY = y; }