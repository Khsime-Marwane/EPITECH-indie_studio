#include "Game/Game.hpp"

void indie::Game::kill(indie::Tile &player, size_t bombId) {
    if (!indie::ResourceHandler::isDeathFrame(indie::MODELS_ID::SKELETON_MODEL, player.getObjectFrameLoop(0)))
    {
      _soundsToPlay.push_back(indie::Sound(indie::SoundId::SOUND_SKELELETON_DIE, indie::SoundAction::UNIQUE, _settings.volume));
      updateScore(bombId, 1000);
      player.setObjectFrameLoop(0, indie::ResourceHandler::getSkeletonFrame("DIE"));
      player.setDoesAnimationChanged(0, true);
    }
}

void indie::Game::explodeBox(indie::Tile &box, size_t bombId) {
  if (!indie::ResourceHandler::isDeathFrame(indie::MODELS_ID::BOX_MODEL, box.getObjectFrameLoop(0)))
    {
      updateScore(bombId);
      box.setObjectFrameLoop(0, indie::ResourceHandler::getLethalFrame(indie::OBJECTS_ID::BOX));
      box.setDoesAnimationChanged(0, true);
    }
}

int indie::Game::chainExplosion(size_t center_x, size_t center_y,
                                  size_t bombId) {
  indie::Tile &bombTile = _map.at(1, center_x, center_y);
  indie::MODELS_ID model;
  indie::OBJECTS_ID type;
  size_t tileSize;
  int chained = 0;

  tileSize = bombTile.getTileSize();
  for (size_t i = 0; i < tileSize; i++) {
    type = bombTile.getType(i);
    model = bombTile.getModelId(i);

    if (bombId != bombTile.getObjectId(i) &&
        (model == indie::MODELS_ID::TENTACLE_MODEL_PORTAL ||
          model == indie::MODELS_ID::SQUAREBOMB_MODEL) &&
        !indie::ResourceHandler::isFrameLethal(type, bombTile.getObjectFrameLoop(i))) {

          chained++;
          bombTile.setElem(i, bombTile.getObjectId(i), type,
                          true, model, true,
                          indie::ResourceHandler::getLethalFrame(type),
                          bombTile.getObjectTexture(i), bombTile.getObjectRotation(i));
          explode(bombTile, i, center_x, center_y);
        }
  }
  return chained;
}

void indie::Game::simpleExplosion(size_t center_x, size_t center_y,
                                  size_t bombId,
                                  bool chain,
                                  bool ownerIsPlayer) {
  indie::OBJECTS_ID type;
  indie::Tile &playerTarget = _map.at(0, center_x, center_y);
  int chainedPoints = 0;

  type = playerTarget.getType(0);
  if (chain && ownerIsPlayer) {
    indie::Player &player = getBombOwner(bombId);

    chainedPoints = chainExplosion(center_x, center_y, bombId) * 50;
    player.updateScore(chainedPoints);
  } else if (chain) { chainExplosion(center_x, center_y, bombId); }
  if (type >= indie::OBJECTS_ID::PLAYER_ONE && type <= indie::OBJECTS_ID::PLAYER_FOURTH) { kill(playerTarget, bombId); }
  else if (type == indie::OBJECTS_ID::BOX) { explodeBox(playerTarget, bombId); }
}

void indie::Game::squareExplosion(size_t center_x, size_t center_y,
                                  size_t bombId) {
  size_t target_x;
  size_t target_y;

  simpleExplosion(center_x, center_y, bombId, false);
  for (int c = -2; c < 3; c++) {
    for (int y = -2; y < 3; y++) {
      target_x = center_x + c;
      target_y = center_y + y;
      if (((c == 0 || c % 2 != 0) || (y == 0 || y % 2 != 0)) &&
          target_x < _map.getWidth() && target_y < _map.getHeight()) {
        simpleExplosion(target_x, target_y, bombId);
      }
    }
  }
}

void indie::Game::tentacleExplosion(size_t center_x, size_t center_y,
                                    size_t size, size_t i,
                                    size_t bombId) {
  indie::ELookAt dir = _map.at(1, center_x, center_y).getObjectRotation(i);

  simpleExplosion(center_x, center_y, bombId, false);
  for (size_t n = 1; n <= size; n++) {
    if (dir == indie::ELookAt::NORTH && center_x >= n) { // left tentacle
      simpleExplosion(center_x - n, center_y, bombId);
    }
    else if (dir == indie::ELookAt::EAST && center_y >= n) {// top tentacle
      simpleExplosion(center_x, center_y - n, bombId);
    }
    else if (dir == indie::ELookAt::SOUTH && (center_x + n) < _map.getWidth()) { // right tentacle
      simpleExplosion(center_x + n, center_y, bombId);
    }
    else if (dir == indie::ELookAt::WEST && (center_y + n) < _map.getHeight()) { // bottom tentacle
      simpleExplosion(center_x, center_y + n, bombId);
    }
  }
}

void indie::Game::explode(indie::Tile &tile, size_t i, size_t center_x, size_t center_y) {
  static std::map<indie::MODELS_ID, std::function<void(size_t, size_t, size_t, size_t)> > explosionHandlers = {
    { indie::MODELS_ID::SQUAREBOMB_MODEL, [this](size_t x, size_t y, size_t at, size_t bombId){ (void)at; this->squareExplosion(x, y, bombId); } },
    { indie::MODELS_ID::PIKES_MODEL_1, [this](size_t x, size_t y, size_t at, size_t bombId){ (void)at; this->simpleExplosion(x, y, bombId); } },
    { indie::MODELS_ID::PIKES_MODEL_2, [this](size_t x, size_t y, size_t at, size_t bombId){ (void)at; this->simpleExplosion(x, y, bombId); } },
    { indie::MODELS_ID::PIKES_MODEL_3, [this](size_t x, size_t y, size_t at, size_t bombId){ (void)at; this->simpleExplosion(x, y, bombId); } },
    { indie::MODELS_ID::PIKES_MODEL_4, [this](size_t x, size_t y, size_t at, size_t bombId){ (void)at; this->simpleExplosion(x, y, bombId); } },
    { indie::MODELS_ID::PIKES_MODEL_CENTER, [this](size_t x, size_t y, size_t at, size_t bombId){ (void)at; this->simpleExplosion(x, y, bombId); } },
    { indie::MODELS_ID::TENTACLE_MODEL_1, [this](size_t x, size_t y, size_t at, size_t bombId){ this->tentacleExplosion(x, y, 1, at, bombId); } },
    { indie::MODELS_ID::TENTACLE_MODEL_2, [this](size_t x, size_t y, size_t at, size_t bombId){ this->tentacleExplosion(x, y, 2, at, bombId); } },
    { indie::MODELS_ID::TENTACLE_MODEL_3, [this](size_t x, size_t y, size_t at, size_t bombId){ this->tentacleExplosion(x, y, 3, at, bombId); } },
    { indie::MODELS_ID::TENTACLE_MODEL_4, [this](size_t x, size_t y, size_t at, size_t bombId){ this->tentacleExplosion(x, y, 4, at, bombId); } },
    { indie::MODELS_ID::TENTACLE_MODEL_5, [this](size_t x, size_t y, size_t at, size_t bombId){ this->tentacleExplosion(x, y, 5, at, bombId); } },
    { indie::MODELS_ID::TENTACLE_MODEL_6, [this](size_t x, size_t y, size_t at, size_t bombId){ this->tentacleExplosion(x, y, 6, at, bombId); } },
    { indie::MODELS_ID::TENTACLE_MODEL_PORTAL, [this](size_t x, size_t y, size_t at, size_t bombId){ this->tentacleExplosion(x, y, 0, at, bombId); } },
    { indie::MODELS_ID::FALLING_PILLAR_MODEL, [this](size_t x, size_t y, size_t at, size_t bombId){ (void)at; this->simpleExplosion(x, y, bombId, true, false); } }
  };
  indie::MODELS_ID bombType = tile.getModelId(i);

  if (explosionHandlers.find(bombType) != explosionHandlers.end()) { explosionHandlers[bombType](center_x, center_y, i, tile.getObjectId(i)); }
}
