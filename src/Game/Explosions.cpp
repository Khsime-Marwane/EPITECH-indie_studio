#include "Game/Game.hpp"

void indie::Game::kill(indie::Tile &player) {
  player.setObjectFrameLoop(0, indie::ResourceHandler::getSkeletonFrame("DIE"));
  player.setDoesAnimationChanged(0, true);
}

void indie::Game::explodeBox(indie::Tile &box) {
  box.setObjectFrameLoop(0, indie::ResourceHandler::getLethalFrame(indie::OBJECTS_ID::BOX));
  box.setDoesAnimationChanged(0, true);
}

void indie::Game::squareExplosion(size_t center_x, size_t center_y) {
  indie::OBJECTS_ID type;
  size_t target_x;
  size_t target_y;

  for (int c = -2; c < 3; c++) {
    for (int y = -2; y < 3; y++) {
      target_x = center_x + c;
      target_y = center_y + y;
      if (((c == 0 || c % 2 != 0) || (y == 0 || y % 2 != 0)) &&
          target_x < _map.getWidth() && target_y < _map.getHeight()) {
        indie::Tile &playerTarget = _map.at(0, target_x, target_y);

        type = playerTarget.getType(0);
        if (type >= indie::OBJECTS_ID::PLAYER_ONE && type <= indie::OBJECTS_ID::PLAYER_FOURTH) { kill(playerTarget); }
        else if (type == indie::OBJECTS_ID::BOX) { explodeBox(playerTarget); }
      }
    }
  }
}

void indie::Game::tentacleExplosion(size_t center_x, size_t center_y, size_t size, size_t i) {
  indie::ELookAt dir = _map.at(1, center_x, center_y).getObjectRotation(i);
  indie::OBJECTS_ID type;

  for (size_t n = 1; n <= size; n++) {
    type = indie::OBJECTS_ID::UNKNOWN;
    if (dir == indie::ELookAt::NORTH && center_x >= n) { // left tentacle
      indie::Tile &playerTarget = _map.at(0, center_x - n, center_y);
      type = playerTarget.getType(0);
      if (type >= indie::OBJECTS_ID::PLAYER_ONE && type <= indie::OBJECTS_ID::PLAYER_FOURTH) { kill(playerTarget); }
      else if (type == indie::OBJECTS_ID::BOX) { explodeBox(playerTarget); }
    }
    else if (dir == indie::ELookAt::EAST && center_y >= n) {// top tentacle
      indie::Tile &playerTarget = _map.at(0, center_x, center_y - n);
      type = playerTarget.getType(0);
      if (type >= indie::OBJECTS_ID::PLAYER_ONE && type <= indie::OBJECTS_ID::PLAYER_FOURTH) { kill(playerTarget); }
      else if (type == indie::OBJECTS_ID::BOX) { explodeBox(playerTarget); }
    }
    else if (dir == indie::ELookAt::SOUTH && (center_x + n) < _map.getWidth()) { // right tentacle
      indie::Tile &playerTarget = _map.at(0, center_x + n, center_y);
      type = playerTarget.getType(0);
      if (type >= indie::OBJECTS_ID::PLAYER_ONE && type <= indie::OBJECTS_ID::PLAYER_FOURTH) { kill(playerTarget); }
      else if (type == indie::OBJECTS_ID::BOX) { explodeBox(playerTarget); }
    }
    else if (dir == indie::ELookAt::WEST && (center_y + n) < _map.getHeight()) { // bottom tentacle
      indie::Tile &playerTarget = _map.at(0, center_x, center_y + n);
      type = playerTarget.getType(0);
      if (type >= indie::OBJECTS_ID::PLAYER_ONE && type <= indie::OBJECTS_ID::PLAYER_FOURTH) { kill(playerTarget); }
      else if (type == indie::OBJECTS_ID::BOX) { explodeBox(playerTarget); }
    }
  }
}

void indie::Game::pikesTrap(size_t center_x, size_t center_y) {
    indie::OBJECTS_ID type;
    indie::Tile &playerTarget = _map.at(0, center_x, center_y);

    type = playerTarget.getType(0);
    if (type >= indie::OBJECTS_ID::PLAYER_ONE && type <= indie::OBJECTS_ID::PLAYER_FOURTH) { kill(playerTarget); }
    else if (type == indie::OBJECTS_ID::BOX) { explodeBox(playerTarget); }
}

void indie::Game::explode(indie::Tile &tile, size_t i, size_t center_x, size_t center_y) {
  static std::map<indie::MODELS_ID, std::function<void(size_t, size_t, size_t)> > explosionHandlers = {
    { indie::MODELS_ID::SQUAREBOMB_MODEL, [this](size_t x, size_t y, size_t at){ (void)at; this->squareExplosion(x, y); } },
    { indie::MODELS_ID::PIKES_MODEL_1, [this](size_t x, size_t y, size_t at){ (void)at; this->pikesTrap(x, y); } },
    { indie::MODELS_ID::PIKES_MODEL_2, [this](size_t x, size_t y, size_t at){ (void)at; this->pikesTrap(x, y); } },
    { indie::MODELS_ID::PIKES_MODEL_3, [this](size_t x, size_t y, size_t at){ (void)at; this->pikesTrap(x, y); } },
    { indie::MODELS_ID::PIKES_MODEL_4, [this](size_t x, size_t y, size_t at){ (void)at; this->pikesTrap(x, y); } },
    { indie::MODELS_ID::PIKES_MODEL_CENTER, [this](size_t x, size_t y, size_t at){ (void)at; this->pikesTrap(x, y); } },
    { indie::MODELS_ID::TENTACLE_MODEL_1, [this](size_t x, size_t y, size_t at){ this->tentacleExplosion(x, y, 1, at); } },
    { indie::MODELS_ID::TENTACLE_MODEL_2, [this](size_t x, size_t y, size_t at){ this->tentacleExplosion(x, y, 2, at); } },
    { indie::MODELS_ID::TENTACLE_MODEL_3, [this](size_t x, size_t y, size_t at){ this->tentacleExplosion(x, y, 3, at); } },
    { indie::MODELS_ID::TENTACLE_MODEL_4, [this](size_t x, size_t y, size_t at){ this->tentacleExplosion(x, y, 4, at); } },
    { indie::MODELS_ID::TENTACLE_MODEL_5, [this](size_t x, size_t y, size_t at){ this->tentacleExplosion(x, y, 5, at); } },
    { indie::MODELS_ID::TENTACLE_MODEL_6, [this](size_t x, size_t y, size_t at){ this->tentacleExplosion(x, y, 6, at); } },
    { indie::MODELS_ID::TENTACLE_MODEL_PORTAL, [this](size_t x, size_t y, size_t at){ this->tentacleExplosion(x, y, 0, at); } }
  };
  indie::MODELS_ID bombType = tile.getModelId(i);

  if (explosionHandlers.find(bombType) != explosionHandlers.end()) { explosionHandlers[bombType](center_x, center_y, i); }
}
