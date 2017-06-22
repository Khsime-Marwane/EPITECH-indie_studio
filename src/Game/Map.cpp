//
// Author: Marwane Khsime
// Date: 2017-06-04 06:45:22
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-06-04 06:45:22
//

#include <memory>
#include "Game/Map.hpp"

indie::Map::Map()
    : _width(0),
      _height(0),
      _nbLayers(0),
      _sceneId(0),
      _scenePov(ECAMERA_VIEW::DEFAULT),
      _objectsId(),
      _layers(),
      _rawMap(),
      _id(4)
{
  init(0, 2);
}

indie::Map::~Map() {}

void indie::Map::init(size_t which_map, size_t nPlayers) {
  switch (static_cast< GAME_MAP >(which_map))
  {
    case GAME_MAP::LITTLE_MAP:
      this->generate_little_map(nPlayers);
      break ;
    default:
      throw IndieError(_INDIE_GAME_INVALID_MAP_INDEX);
      break ;
  }
}

void indie::Map::clear() {
  _width = 0;
  _height = 0;
  _nbLayers = 0;
  _sceneId = 0;
  _scenePov = ECAMERA_VIEW::DEFAULT;
  _objectsId.clear();
  std::for_each(_layers.begin(), _layers.end(),
  [](std::vector<std::vector<std::unique_ptr< indie::Tile> > > &layer){
    std::for_each(layer.begin(), layer.end(),
    [](std::vector<std::unique_ptr<indie::Tile> > &line){
      line.clear();
    });
  });
  std::for_each(_rawMap.begin(), _rawMap.end(),
  [](std::vector<int> &line){
    line.clear();
  });
  _id = 4;
}

indie::ITile const &indie::Map::at(size_t layer, size_t x, size_t y) const
{
  return *this->_layers[layer][y][x];
}

indie::Tile &indie::Map::at(size_t layer, size_t x, size_t y)
{
  return *this->_layers[layer][y][x];
}

std::size_t  indie::Map::getLayerNb() const { return this->_nbLayers; }

std::size_t  indie::Map::getWidth() const { return this->_width; }

std::size_t  indie::Map::getHeight() const { return this->_height; }

std::size_t  indie::Map::getSceneId() const { return this->_sceneId; }
void         indie::Map::setSceneId(std::size_t sceneId) { this->_sceneId = sceneId; }

indie::ECAMERA_VIEW    indie::Map::getPOV() const { return this->_scenePov; }
void                   indie::Map::setCameraPOV(indie::ECAMERA_VIEW pov) { this->_scenePov = pov; }

const std::vector<std::size_t>    &indie::Map::getObjectsId() const { return this->_objectsId; }

void                        indie::Map::addObjectById(std::size_t add) {
    if (std::find(this->_objectsId.begin(), this->_objectsId.end(), add) == this->_objectsId.end())
        this->_objectsId.push_back(add);
    else
        throw indie::IndieError(_INDIE_GAME_INVALID_OBJECT_ID);
}

void                        indie::Map::deleteObjectById(std::size_t del) {

    if (std::find(this->_objectsId.begin(), this->_objectsId.end(), del) != this->_objectsId.end())
        this->_objectsId.erase(std::remove(this->_objectsId.begin(), this->_objectsId.end(), del),
                               this->_objectsId.end());
    else
        throw indie::IndieError(_INDIE_GAME_INVALID_OBJECT_ID);
}

void                        indie::Map::setObectsId(const std::vector<std::size_t> &ids) {
    this->_objectsId = ids;
}

void         indie::Map::create_layer(std::size_t layer)
{

  this->_layers.push_back(std::vector<std::vector<std::unique_ptr<Tile> > >());

  for (size_t y = 0; y < this->_height; y++)
    {

      this->_layers[layer].push_back(std::vector<std::unique_ptr<indie::Tile>>());

      for (size_t x = 0; x < this->_width; x++)
        {
            this->_layers[layer][y].push_back(std::make_unique< Tile >());
        }

    }

}

size_t indie::Map::newId() {
  return ++_id;
}

void  indie::Map::initTiles() {
  int y = 0;
  int x;
  std::for_each(_layers[0].begin(), _layers[0].end(),
    [&](std::vector<std::unique_ptr<Tile> > &line) {
      x = 0;
      std::for_each(line.begin(), line.end(),
      [&](std::unique_ptr<Tile> &tile) {
        indie::OBJECTS_ID type;

        type = static_cast<indie::OBJECTS_ID>(_rawMap[y][x]);
        tile->setType(0, type);
        switch (type) {

          case indie::OBJECTS_ID::PLAYER_ONE:
            tile->setHasModel(0, true);
            tile->setModelId(0, indie::MODELS_ID::SKELETON_MODEL);
            _objectsId.push_back(1);
            tile->setObjectId(0, 1);
            tile->setObjectTexture(0, "Textures/SkeletonMage/Blue.png");
            tile->setObjectFrameLoop(0, indie::ResourceHandler::getSkeletonFrame("SPAWN"));
            tile->setObjectRotation(0, indie::ELookAt::EAST);
            break;

          case indie::OBJECTS_ID::PLAYER_TWO:
            tile->setHasModel(0, true);
            tile->setModelId(0, indie::MODELS_ID::SKELETON_MODEL);
            _objectsId.push_back(2);
            tile->setObjectId(0, 2);
            tile->setObjectTexture(0, "Textures/SkeletonMage/Red.png");
            tile->setObjectFrameLoop(0, indie::ResourceHandler::getSkeletonFrame("SPAWN"));
            tile->setShiftX(0, 0.3);
            tile->setObjectRotation(0, indie::ELookAt::SOUTH);
            break;

          case indie::OBJECTS_ID::PLAYER_THREE:
            tile->setHasModel(0, true);
            tile->setModelId(0, indie::MODELS_ID::SKELETON_MODEL);
            _objectsId.push_back(3);
            tile->setObjectId(0, 3);
            tile->setObjectTexture(0, "Textures/SkeletonMage/Yellow.png");
            tile->setObjectFrameLoop(0, indie::ResourceHandler::getSkeletonFrame("SPAWN"));
            tile->setShiftX(0, 0.3);
            tile->setObjectRotation(0, indie::ELookAt::WEST);
            break;

          case indie::OBJECTS_ID::PLAYER_FOURTH:
            tile->setHasModel(0, true);
            tile->setModelId(0, indie::MODELS_ID::SKELETON_MODEL);
            _objectsId.push_back(4);
            tile->setObjectId(0, 4);
            tile->setObjectTexture(0, "Textures/SkeletonMage/Green.png");
            tile->setObjectFrameLoop(0, indie::ResourceHandler::getSkeletonFrame("SPAWN"));
            tile->setObjectRotation(0, indie::ELookAt::NORTH);
            break;

          case indie::OBJECTS_ID::BOX:
            tile->setHasModel(0, true);
            tile->setModelId(0, indie::MODELS_ID::BOX_MODEL);
            _objectsId.push_back(++_id);
            tile->setObjectId(0, _id);
            tile->setObjectTexture(0, "Map/Box.png");
            break;

          case indie::OBJECTS_ID::WALL:
          case indie::OBJECTS_ID::EMPTY:
          case indie::OBJECTS_ID::SQUAREBOMB:
          case indie::OBJECTS_ID::PIKESBOMB:
          case indie::OBJECTS_ID::TENTACLEBOMB:
          case indie::OBJECTS_ID::FALLING_PILLAR:
          case indie::OBJECTS_ID::BONUS_TENTACLEB:
          case indie::OBJECTS_ID::BONUS_SQUAREB:
          case indie::OBJECTS_ID::UNKNOWN:
          default:
            break;
      }
      x++;
    });
    y++;
  });
}
