//
// Author: Marwane Khsime
// Date: 2017-06-04 06:45:22
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-06-04 06:45:22
//

#include <memory>
#include "Game/Map.hpp"

indie::Map::Map(std::size_t which_map)
    : _width(0),
      _height(0),
      _nbLayers(0),
      _sceneId(0),
      _scenePov(ECAMERA_VIEW::DEFAULT),
      _objectsId(),
      _layers(),
      _rawMap()
{

    switch (static_cast< GAME_MAP >(which_map))
    {
        case GAME_MAP::LITTLE_MAP:
            this->generate_little_map();
            break ;

        default:
            throw IndieError(_INDIE_GAME_INVALID_MAP_INDEX);
            break ;
    }

}

indie::Map::~Map() {

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

    if (std::find(this->_objectsId.begin(), this->_objectsId.end(), del) == this->_objectsId.end())
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

void  indie::Map::initTiles() {
  int nobjects = 0;
  int y = 0;
  int x;

  std::for_each(_layers[0].begin(), _layers[0].end(),
    [&](std::vector<std::unique_ptr<Tile> > &line) {
      std::cout << "init tiles y " << y << std::endl;
      x = 0;
      std::for_each(line.begin(), line.end(),
      [&](std::unique_ptr<Tile> &tile) {
        indie::OBJECTS_ID type;

          std::cout << "init tiles x " << x << std::endl;
        type = static_cast<indie::OBJECTS_ID>(_rawMap[y][x]);
        tile->setType(0, type);
        switch (type) {
          case indie::OBJECTS_ID::EMPTY:
            tile->setHasModel(0, false);
            tile->setType(0, indie::OBJECTS_ID::EMPTY);
            break;

          case indie::OBJECTS_ID::WALL:
            tile->setHasModel(0, false);
            tile->setType(0, indie::OBJECTS_ID::WALL);
            break;

          case indie::OBJECTS_ID::PLAYER_ONE:
          std::cout << "player one\n";
            tile->setHasModel(0, true);
            std::cout << "a\n";
            tile->setType(0, indie::OBJECTS_ID::PLAYER_ONE);
            std::cout << "b\n";
            tile->setModelId(0, indie::MODELS_ID::SKELETON_MODEL);
            std::cout << "c\n";
            _objectsId.push_back(++nobjects);
            std::cout << "d\n";
            tile->setObjectId(0, nobjects);
            std::cout << "e\n";
            tile->setObjectTexture(0, "Textures/SkeletonMage/Blue.png");
            std::cout << "f\n";
            tile->setDoesAnimationChanged(0, false);
            std::cout << "g\n";
            tile->setObjectFrameLoop(0, indie::Tile::getSkeletonFrame("SPAWN"));
            std::cout << "player one setted\n";
            break;

          case indie::OBJECTS_ID::PLAYER_TWO:
            tile->setHasModel(0, true);
            tile->setType(0, indie::OBJECTS_ID::PLAYER_TWO);
            tile->setModelId(0, indie::MODELS_ID::SKELETON_MODEL);
            _objectsId.push_back(++nobjects);
            tile->setObjectId(0, nobjects);
            tile->setObjectTexture(0, "Textures/SkeletonMage/Red.png");
            tile->setDoesAnimationChanged(0, false);
            tile->setObjectFrameLoop(0, indie::Tile::getSkeletonFrame("SPAWN"));
            break;

          case indie::OBJECTS_ID::PLAYER_THREE:
            tile->setHasModel(0, true);
            tile->setType(0, indie::OBJECTS_ID::PLAYER_THREE);
            tile->setModelId(0, indie::MODELS_ID::SKELETON_MODEL);
            _objectsId.push_back(++nobjects);
            tile->setObjectId(0, nobjects);
            tile->setObjectTexture(0, "Textures/SkeletonMage/Yellow.png");
            tile->setDoesAnimationChanged(0, false);
            tile->setObjectFrameLoop(0, indie::Tile::getSkeletonFrame("SPAWN"));
            break;

          case indie::OBJECTS_ID::PLAYER_FOURTH:
            tile->setHasModel(0, true);
            tile->setType(0, indie::OBJECTS_ID::PLAYER_FOURTH);
            tile->setModelId(0, indie::MODELS_ID::SKELETON_MODEL);
            _objectsId.push_back(++nobjects);
            tile->setObjectId(0, nobjects);
            tile->setObjectTexture(0, "Textures/SkeletonMage/Green.png");
            tile->setDoesAnimationChanged(0, false);
            tile->setObjectFrameLoop(0, indie::Tile::getSkeletonFrame("SPAWN"));
            break;

          case indie::OBJECTS_ID::BOX:
            tile->setHasModel(0, true);
            tile->setType(0, indie::OBJECTS_ID::BOX);
            tile->setModelId(0, indie::MODELS_ID::BOX_MODEL);
            _objectsId.push_back(++nobjects);
            tile->setObjectId(0, nobjects);
            tile->setObjectTexture(0, "Map/Box.png");
            tile->setDoesAnimationChanged(0, true);
            tile->setObjectFrameLoop(0, std::pair<std::size_t, std::size_t>(0, 0));
            break;

          case indie::OBJECTS_ID::SQUAREBOMB:
          case indie::OBJECTS_ID::PIKESBOMB:
          case indie::OBJECTS_ID::TENTACLEBOMB:
          case indie::OBJECTS_ID::UNKNOWN:
          default:
            break;
      }
      x++;
    });
    y++;
  });
}
