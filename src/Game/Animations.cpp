#include "Game/Game.hpp"

void indie::Game::removeObject(indie::Tile &tile, size_t &i) {
  indie::OBJECTS_ID type = tile.getType(i);
  size_t objectId = tile.getObjectId(i);

  if (type == indie::OBJECTS_ID::BOX) {
    popBonus(tile, i);
    _map.deleteObjectById(objectId);
    return;
  }
  else if (type >= indie::OBJECTS_ID::SQUAREBOMB && type <= indie::OBJECTS_ID::TENTACLEBOMB){
    deleteBombSaves(objectId);
  }
  else if (tile.getModelId(i) == indie::MODELS_ID::SKELETON_MODEL) {
    Player &player = getPlayerById(objectId);

    player.die();
    _gui.loadComponents(_gameState);
  }
  tile.deleteElement(i--);
  _map.deleteObjectById(objectId);
}

void indie::Game::updatePlayerAnimation(indie::Tile &tile, size_t i) {
  tile.setDoesAnimationChanged(i, true);
  tile.setObjectFrameLoop(i, indie::ResourceHandler::getSkeletonFrame("IDLE"));
}

void indie::Game::updateBombAnimation(indie::Tile &tile, size_t &i,
                                      indie::OBJECTS_ID objectType, size_t x, size_t y) {
  std::pair<size_t, size_t> nextframe = indie::ResourceHandler::getNextFrame(objectType, tile.getObjectFrameLoop(i));

  if (nextframe.first == 0 && nextframe.second == 0) {
    removeObject(tile, i);
    return;
  }
  if (indie::ResourceHandler::isFrameLethal(tile.getType(i), nextframe)) {
    explode(tile, i, x, y);
  }

  tile.setDoesAnimationChanged(i, true);
  tile.setObjectFrameLoop(i, nextframe);
}

std::vector<indie::AnimationState>::const_iterator indie::Game::getAnimationStateIt(size_t id) const {
  return std::find_if(_objectsStates.begin(), _objectsStates.end(),
          [&id](const AnimationState &animation)->bool {
            return animation.id == id;
          });
}

void indie::Game::updateAnimations() {
  indie::OBJECTS_ID objectType;
  size_t tileSize;
  std::vector<indie::AnimationState>::const_iterator animation_it;

  if (_objectsStates.size() == 0) { return; }

  for (std::size_t layer = 0; layer < _map.getLayerNb(); layer++) {
    for (std::size_t y = 0; y < _map.getHeight(); y++) {
      for (std::size_t x = 0; x < _map.getWidth(); x++) {
        indie::Tile &tile = _map.at(layer, x, y);


        tileSize = tile.getTileSize();
        for (size_t i = 0, pos = 0; i < tileSize; i++, pos++) {

          objectType = tile.getType(pos);
          if ((animation_it = getAnimationStateIt(tile.getObjectId(pos))) != _objectsStates.end()) {

            if ((*animation_it).over &&
              indie::ResourceHandler::isDeathFrame(tile.getModelId(pos), tile.getObjectFrameLoop(pos))) {

              removeObject(tile, pos);
              if (isEnded()) {
                reward();
                _gameState = indie::GameState::ENDGAME;
                _gui.loadComponents(_gameState);
                return;
              }

            }
            else if ((*animation_it).over &&
                objectType >= indie::OBJECTS_ID::PLAYER_ONE &&
                objectType <= indie::OBJECTS_ID::PLAYER_FOURTH) {
              updatePlayerAnimation(tile, pos);
            }
            else if ((*animation_it).over &&
                      objectType >= indie::OBJECTS_ID::SQUAREBOMB &&
                      objectType <= indie::OBJECTS_ID::FALLING_PILLAR) {

              updateBombAnimation(tile, pos, objectType, x, y);
            }
            else if (!(*animation_it).over) {
              tile.setDoesAnimationChanged(pos, false);
            }
          }
        }
      }
    }
  }
}
