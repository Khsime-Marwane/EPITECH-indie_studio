#include "Game/Game.hpp"

std::pair<size_t, size_t> indie::Game::getNextFallingPillarPos(bool reset) {
  static std::pair<size_t, size_t> fallingStonesPos = {-1, 0};
  static indie::ELookAt dir = ELookAt::EAST;
  static std::vector<size_t> stop = {
    _map.getWidth() - 1, _map.getHeight() - 1, 0, 1
  };
  bool wall = false;

  if (reset) {
    fallingStonesPos = {-1, 0};
    stop = {
      _map.getWidth() - 1, _map.getHeight() - 1, 0, 1
    };
    dir = ELookAt::EAST;
    return {-1, 0};
  }

  if (dir == indie::ELookAt::WEST) { fallingStonesPos.first--; }
  else if (dir == indie::ELookAt::EAST) { fallingStonesPos.first++; }
  else if (dir == indie::ELookAt::SOUTH) { fallingStonesPos.second++; }
  else if (dir == indie::ELookAt::NORTH) { fallingStonesPos.second--; }

  indie::Tile &target = _map.at(0, fallingStonesPos.first, fallingStonesPos.second);
  wall = target.getType(0) == indie::OBJECTS_ID::WALL;

  if (fallingStonesPos.first == stop[0] && dir == ELookAt::EAST) {
  dir = ELookAt::SOUTH;
    stop[0]--;
  }
  else if (fallingStonesPos.second == stop[1] && dir == ELookAt::SOUTH) {
    dir = ELookAt::WEST;
    stop[1]--;
  } else if (fallingStonesPos.first == stop[2] && dir == ELookAt::WEST) {
    stop[2]++;
    dir = ELookAt::NORTH;
  } else if (fallingStonesPos.second == stop[3] && dir == ELookAt::NORTH) {
    stop[3]++;
    dir = ELookAt::EAST;
  }

  if (wall) { return getNextFallingPillarPos(); }
  return fallingStonesPos;
}

void indie::Game::itsRainingStones() {
  std::pair<size_t, size_t> fallingStonesPos = getNextFallingPillarPos();
  size_t objectId;

  indie::Tile &target = _map.at(1, fallingStonesPos.first, fallingStonesPos.second);

  objectId = _map.newId();
  _map.addObjectById(objectId);
  _soundsToPlay.push_back(indie::Sound(indie::SoundId::SOUND_FALLING_STONES, indie::SoundAction::UNIQUE, _settings.volume));
  target.setElem(target.getTileSize(), objectId,
                indie::OBJECTS_ID::FALLING_PILLAR,
                true, indie::MODELS_ID::FALLING_PILLAR_MODEL, true,
                indie::ResourceHandler::getNextFrame(indie::OBJECTS_ID::FALLING_PILLAR, {0, 0}),
                indie::ResourceHandler::getTexture(indie::MODELS_ID::FALLING_PILLAR_MODEL),
                static_cast<indie::ELookAt>(rand() % 4));
}

void indie::Game::fallingStones() {
  static indie::Timer CD;

  if (_settings.timer.Elapsed().count() >= 60000) {
    if (CD.Elapsed().count() >= 500) {
      itsRainingStones();
      CD.Reset();
    }
  }
}
