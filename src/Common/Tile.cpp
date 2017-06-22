//
// Author: Marwane Khsime
// Date: 2017-06-04 05:32:25
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-06-04 05:32:25
//

#include "Game/Tile.hpp"

indie::Tile::Tile()

    :
      _hasModel( { false }),
      _modelId( { indie::MODELS_ID::UNKNOWN }),
      _objectId( { 0 }),
      _objectRotation( { indie::ELookAt::SOUTH }),
      _objectTexture( { "" }),
      _doesAnimationChanged( { false }),
      _objectFrameLoop({ { 0, 0 } }),
      _shiftX( { 0.0 } ),
      _shiftY( { 0.0 }),
      _type( { indie::OBJECTS_ID::EMPTY })
{

}

std::size_t         indie::Tile::getTileSize() const { return this->_hasModel.size(); }

bool                indie::Tile::hasModel(std::size_t at) const { return this->_hasModel.at(at); }
void                indie::Tile::setHasModel(std::size_t at, bool hm) { this->_hasModel.at(at) = hm; }

indie::MODELS_ID   indie::Tile::getModelId(std::size_t at) const { return this->_modelId.at(at); }
void                indie::Tile::setModelId(std::size_t at, indie::MODELS_ID id) { this->_modelId.at(at) = id; }
std::size_t         indie::Tile::getObjectId(std::size_t at) const { return this->_objectId.at(at); }
void                indie::Tile::setObjectId(std::size_t at, std::size_t id) { this->_objectId.at(at) = id; }

indie::ELookAt      indie::Tile::getObjectRotation(std::size_t at) const { return this->_objectRotation.at(at); }
void                indie::Tile::setObjectRotation(std::size_t at, indie::ELookAt look) { this->_objectRotation.at(at) = look; }

std::string         indie::Tile::getObjectTexture(std::size_t at) const { return this->_objectTexture.at(at); }
void                indie::Tile::setObjectTexture(std::size_t at, const std::string &texture) { this->_objectTexture.at(at) = texture; }

bool                indie::Tile::doesAnimationChanged(std::size_t at) const { return this->_doesAnimationChanged.at(at); }
void                indie::Tile::setDoesAnimationChanged(std::size_t at, bool v) { this->_doesAnimationChanged.at(at) = v; }

std::pair<std::size_t, std::size_t> indie::Tile::getObjectFrameLoop(std::size_t at) const { return this->_objectFrameLoop.at(at); }
void                indie::Tile::setObjectFrameLoop(std::size_t at, const std::pair<std::size_t, std::size_t> &fl) { this->_objectFrameLoop.at(at) = fl; }

double              indie::Tile::getShiftX(std::size_t at) const { return this->_shiftX.at(at); }
void                indie::Tile::setShiftX(std::size_t at, double x) { this->_shiftX.at(at) = x; }

double              indie::Tile::getShiftY(std::size_t at) const { return this->_shiftY.at(at); }
void                indie::Tile::setShiftY(std::size_t at, double y) { this->_shiftY.at(at) = y; }

indie::OBJECTS_ID indie::Tile::getType(std::size_t at) const { return this->_type.at(at); }
void                indie::Tile::setType(std::size_t at, OBJECTS_ID type) { this->_type.at(at) = type; }

indie::Tile         &indie::Tile::operator=(const indie::Tile &other) {
  if (this != &other) {
    _hasModel = other._hasModel;
    _modelId = other._modelId;
    _objectId = other._objectId;
    _objectRotation = other._objectRotation;
    _objectTexture = other._objectTexture;
    _doesAnimationChanged = other._doesAnimationChanged;
    _objectFrameLoop = other._objectFrameLoop;
    _shiftX = other._shiftX;
    _shiftY = other._shiftY;
    _type = other._type;
  }
  return *this;
}

void              indie::Tile::reset() {
  this->_hasModel =  { false };
  this->_modelId = { indie::MODELS_ID::UNKNOWN };
  this->_doesAnimationChanged = { true };
  this->_objectFrameLoop =  { { 0,0 } };
  this->_shiftY = { 0.0 };
  this->_shiftX = { 0.0 };
  this->_type = { indie::OBJECTS_ID::EMPTY };
  _objectId = { 0 };
}

void  indie::Tile::deleteElement(size_t i) {
  if (_hasModel.size() == 1) { return reset(); }
  _hasModel.erase(_hasModel.begin() + i);
  _modelId.erase(_modelId.begin() + i);
  _objectId.erase(_objectId.begin() + i);
  _objectRotation.erase(_objectRotation.begin() + i);
  _objectTexture.erase(_objectTexture.begin() + i);
  _doesAnimationChanged.erase(_doesAnimationChanged.begin() + i);
  _objectFrameLoop.erase(_objectFrameLoop.begin() + i);
  _shiftX.erase(_shiftX.begin() + i);
  _shiftY.erase(_shiftY.begin() + i);
  _type.erase(_type.begin() + i);
}

bool  indie::Tile::isTangible(size_t at) const {
  return  _type[at] != indie::OBJECTS_ID::EMPTY &&
          _type[at] != indie::OBJECTS_ID::PIKESBOMB &&
          _type[at] != indie::OBJECTS_ID::BONUS_SQUAREB &&
          _type[at] != indie::OBJECTS_ID::BONUS_TENTACLEB;
}

void  indie::Tile::newElem(size_t id) {
  _hasModel.push_back(false);
  _modelId.push_back(indie::MODELS_ID::UNKNOWN);
  _objectId.push_back(id);
  _objectRotation.push_back(indie::ELookAt::SOUTH);
  _doesAnimationChanged.push_back(false);
  _objectFrameLoop.push_back({0,0});
  _shiftX.push_back(0.0);
  _shiftY.push_back(0.0);
  _type.push_back(indie::OBJECTS_ID::EMPTY);
  _objectTexture.push_back("");
}

void indie::Tile::setElem(size_t at, size_t id, indie::OBJECTS_ID type,
                          bool hasModel, indie::MODELS_ID modelId,
                          bool doesAnimationChanged, std::pair<size_t, size_t> frames,
                          std::string texture,
                          indie::ELookAt rotation,
                          double shiftX, double shiftY) {
  if (at == _hasModel.size()) {
    if (at == 1  && _type[0] == indie::OBJECTS_ID::EMPTY){ at = 0; }
    else { newElem(id); }
  }
  _hasModel[at] = hasModel;
  _modelId[at] = modelId;
  _objectId[at] = id;
  _objectRotation[at] = rotation;
  _objectTexture[at] = texture;
  _doesAnimationChanged[at] = doesAnimationChanged;
  _objectFrameLoop[at] = frames;
  _shiftX[at] = shiftX;
  _shiftY[at] = shiftY;
  _type[at] = type;
}
