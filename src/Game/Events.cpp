#include "Game/Game.hpp"

indie::Tile &indie::Game::move_left(indie::Tile &player,
                                    size_t x, size_t y) {
  double newShift;
  bool tangible;

  newShift = player.getShiftX(0) - PLAYER_SPEED;
  tangible = (x == 0 || _map.at(0, x - 1, y).isTangible(0) || _map.at(1, x - 1, y).isTangible(0));
  if (newShift < 0.0 && !tangible && player.getShiftY(0) <= 0.3) {
    indie::Tile &nearPlayerTile = _map.at(0, x - 1, y);

    nearPlayerTile = player;
    player.reset();
    nearPlayerTile.setShiftX(0, 1.0 + newShift);
    return nearPlayerTile;
  }
  else if (tangible || player.getShiftY(0) > 0.3) { player.setShiftX(0, newShift < 0.3 ? 0.3 : newShift); }
  else if (player.getShiftY(0) <= 0.3 && newShift >= 0.0) { player.setShiftX(0, newShift); }
  return player;
}

indie::Tile &indie::Game::move_right(indie::Tile &player,
                                      size_t x, size_t y) {
  double newShift;
  bool tangible;

  newShift = player.getShiftX(0) + PLAYER_SPEED;
  tangible = (x == (_map.getWidth() - 1) || _map.at(0, x + 1, y).isTangible(0) || _map.at(1, x + 1, y).isTangible(0));
  if (newShift >= 1.0 && !tangible && player.getShiftY(0) <= 0.3) {
    indie::Tile &nearPlayerTile = _map.at(0, x + 1, y);

    nearPlayerTile = player;
    player.reset();
    nearPlayerTile.setShiftX(0, newShift - 1.0);
    return nearPlayerTile;
  }
  else if (tangible || player.getShiftY(0) > 0.3) { player.setShiftX(0, newShift > 0.3 ? 0.3 : newShift); }
  else if (player.getShiftY(0) <= 0.3 && newShift < 1.0) { player.setShiftX(0, newShift); }
  return player;
}

indie::Tile &indie::Game::move_down(indie::Tile &player,
                                    size_t x, size_t y) {
  double newShift;
  bool tangible;

  newShift = player.getShiftY(0) + PLAYER_SPEED;
  tangible = (y == (_map.getHeight() - 1) || _map.at(0, x, y + 1).isTangible(0) || _map.at(1, x, y + 1).isTangible(0));
  if (newShift >= 1.0 && !tangible && player.getShiftX(0) <= 0.3) {
    indie::Tile &nearPlayerTile = _map.at(0, x, y + 1);

    nearPlayerTile = player;
    player.reset();
    nearPlayerTile.setShiftY(0, newShift - 1.0);
    nearPlayerTile.setShiftX(0, 0.0);
    return nearPlayerTile;
  }
  else if (tangible || player.getShiftX(0) > 3.0) { player.setShiftY(0, 0.0); }
  else if (player.getShiftX(0) <= 0.3 && newShift < 1.0) { player.setShiftY(0, newShift); }
  return player;
}

indie::Tile &indie::Game::move_up(indie::Tile &player,
                                  size_t x, size_t y) {
  double newShift;
  bool tangible;

  newShift = player.getShiftY(0) - PLAYER_SPEED;
  tangible = (y == 0 || _map.at(0, x, y - 1).isTangible(0) || _map.at(1, x, y - 1).isTangible(0));
  if (newShift < 0.0 && !tangible && player.getShiftX(0) <= 0.3) {
    indie::Tile &nearPlayerTile = _map.at(0, x, y - 1);

    nearPlayerTile = player;
    player.reset();
    nearPlayerTile.setShiftY(0, 1.0 + newShift);
    nearPlayerTile.setShiftX(0, 0.0);
    return nearPlayerTile;
  }
  else if (tangible || player.getShiftX(0) > 3.0) { player.setShiftY(0, newShift > 0.3 ? newShift : 0.3); }
  else if (player.getShiftX(0) <= 0.3 && newShift >= 0.0) { player.setShiftY(0, newShift); }
  return player;
}

void indie::Game::move(size_t playerId,
                        indie::ELookAt dir) {
  static std::map<indie::ELookAt, std::function<Tile &(indie::Tile &, size_t, size_t)> > moves_handlers = {
    { indie::ELookAt::NORTH, [this](indie::Tile &tile, size_t x, size_t y)->indie::Tile &{ return move_up(tile, x, y); } },
    { indie::ELookAt::SOUTH, [this](indie::Tile &tile, size_t x, size_t y)->indie::Tile &{ return move_down(tile, x, y); } },
    { indie::ELookAt::WEST, [this](indie::Tile &tile, size_t x, size_t y) ->indie::Tile &{ return move_left(tile, x, y); } },
    { indie::ELookAt::EAST, [this](indie::Tile &tile, size_t x, size_t y) ->indie::Tile &{ return move_right(tile, x, y); } },
  };

  if (moves_handlers.find(dir) == moves_handlers.end()) { return; }
  for (std::size_t y = 0; y < _map.getHeight(); y++) {
    for (std::size_t x = 0; x < _map.getWidth(); x++) {
      indie::Tile &tile = _map.at(0, x, y);
      if (tile.getType(0) == static_cast<indie::OBJECTS_ID>(playerId) &&
          !indie::ResourceHandler::isDeathFrame(indie::MODELS_ID::SKELETON_MODEL, tile.getObjectFrameLoop(0))) {

          indie::Tile &ntile = moves_handlers[dir](tile, x, y);
          std::pair<size_t, size_t> run_frame = indie::ResourceHandler::getSkeletonFrame("RUN");

          ntile.setObjectRotation(0, dir);
          ntile.setDoesAnimationChanged(0, true);
          ntile.setObjectFrameLoop(0, run_frame);
      }
    }
  }
}

void indie::Game::SquareBomb(indie::Tile &bombTile) {
  size_t objectId = _map.newId();

  _map.addObjectById(objectId);
  bombTile.setElem(bombTile.getTileSize(), objectId,
                  indie::OBJECTS_ID::SQUAREBOMB,
                  true, indie::MODELS_ID::SQUAREBOMB_MODEL, true,
                  indie::ResourceHandler::getNextFrame(indie::OBJECTS_ID::SQUAREBOMB, {0, 0}),
                  indie::ResourceHandler::getTexture(indie::MODELS_ID::SQUAREBOMB_MODEL));
}

void indie::Game::PikesBomb(indie::Tile &bombTile, size_t center_x, size_t center_y) {
  size_t objectId;
  size_t modelId;
  size_t x;
  std::vector<std::pair<size_t, size_t>> targets;
  std::vector<bool> stopPropagation = { false, false, false, false };

  for (size_t i = 1; i <= 3; i++) {
    x = 0;
    targets = { {center_x - i,  center_y},
                {center_x,      center_y - i},
                {center_x + i,  center_y},
                {center_x,      center_y + i } };

    std::for_each(targets.begin(), targets.end(),
      [&](std::pair<size_t, size_t> &targetPos) {

        if (!stopPropagation[x] &&
            targetPos.first < _map.getWidth() && targetPos.second < _map.getHeight()) {

          indie::Tile &target = _map.at(1, targetPos.first, targetPos.second);

          objectId = _map.newId();
          _map.addObjectById(objectId);
          modelId = static_cast<size_t>(indie::MODELS_ID::PIKES_MODEL_1) + rand() % 4;
          target.setElem(target.getTileSize(), objectId,
                          indie::OBJECTS_ID::PIKESBOMB,
                          true, static_cast<indie::MODELS_ID>(modelId), true,
                          indie::ResourceHandler::getNextFrame(indie::OBJECTS_ID::PIKESBOMB, {0, 0}),
                          indie::ResourceHandler::getTexture(static_cast<indie::MODELS_ID>(modelId)));

          if (_map.at(0, targetPos.first, targetPos.second).getType(0) == indie::OBJECTS_ID::BOX ||
              _map.at(0, targetPos.first, targetPos.second).getType(0) == indie::OBJECTS_ID::WALL) {
            stopPropagation[x] = true;
          }
        } else { stopPropagation[x] = true; }
        x++;
    });
  }
  objectId  = _map.newId();
  _map.addObjectById(objectId);
  bombTile.setElem(0, objectId,
                  indie::OBJECTS_ID::PIKESBOMB,
                  true, indie::MODELS_ID::PIKES_MODEL_CENTER, true,
                  indie::ResourceHandler::getNextFrame(indie::OBJECTS_ID::PIKESBOMB, {0, 0}),
                  indie::ResourceHandler::getTexture(indie::MODELS_ID::PIKES_MODEL_CENTER));
}

void indie::Game::TentacleBomb(indie::Tile &bombTile, size_t x, size_t y) {
  size_t eastSize = 1;
  size_t northSize = 1;
  size_t westSize = 1;
  size_t southSize = 1;
  size_t objectId;

  while (westSize < 6 && x >= westSize && _map.at(0, x - westSize, y).getType(0) == indie::OBJECTS_ID::EMPTY) { westSize++; }
  while (northSize < 6 && y >= northSize && _map.at(0,  x, y - northSize).getType(0) == indie::OBJECTS_ID::EMPTY) { northSize++; }
  while (eastSize < 6 && (x + eastSize) < _map.getWidth() && _map.at(0, x + eastSize, y).getType(0) == indie::OBJECTS_ID::EMPTY) { eastSize++; }
  while (southSize < 6 && (y + southSize) < _map.getHeight() && _map.at(0, x, y + southSize).getType(0) == indie::OBJECTS_ID::EMPTY) { southSize++; }
  std::vector<indie::MODELS_ID> models = {
    indie::MODELS_ID::TENTACLE_MODEL_PORTAL,
    static_cast<indie::MODELS_ID>(westSize + 7),
    static_cast<indie::MODELS_ID>(northSize + 7),
    static_cast<indie::MODELS_ID>(eastSize + 7),
    static_cast<indie::MODELS_ID>(southSize + 7)
  };
  std::vector<indie::ELookAt> dirs = {
    indie::ELookAt::SOUTH,
    indie::ELookAt::NORTH,
    indie::ELookAt::EAST,
    indie::ELookAt::SOUTH,
    indie::ELookAt::WEST
  };
  for (size_t i = 0; i < 5; i++) {
    objectId = _map.newId();
    if (i != 0) { bombTile.newElem(objectId); }
    _map.addObjectById(objectId);
    bombTile.setElem(bombTile.getTileSize(), objectId,
                    indie::OBJECTS_ID::TENTACLEBOMB,
                    true, models[i], true,
                    indie::ResourceHandler::getNextFrame(indie::OBJECTS_ID::TENTACLEBOMB, {0, 0}),
                    indie::ResourceHandler::getTexture(models[i]),
                    dirs[i]);
  }
}

void indie::Game::bomb(size_t playerId) {
  static std::map<indie::OBJECTS_ID, std::function<void(indie::Tile &, size_t, size_t)> > bombHandlers = {
    { indie::OBJECTS_ID::SQUAREBOMB, [this](indie::Tile &tile, size_t x, size_t y){ (void)x; (void)y; this->SquareBomb(tile); } },
    { indie::OBJECTS_ID::PIKESBOMB, [this](indie::Tile &tile, size_t x, size_t y){ this->PikesBomb(tile,x , y); } },
    { indie::OBJECTS_ID::TENTACLEBOMB, [this](indie::Tile &tile, size_t x, size_t y){ this->TentacleBomb(tile, x, y); } }
  };
  indie::OBJECTS_ID type = getBombType(playerId);
  indie::SoundId sound;
  int bombId;

  for (std::size_t y = 0; y < _map.getHeight(); y++) {
    for (std::size_t x = 0; x < _map.getWidth(); x++) {
      if (_map.at(0, x, y).getType(0) == static_cast<indie::OBJECTS_ID>(playerId)) {
        if (indie::ResourceHandler::isDeathFrame(indie::MODELS_ID::SKELETON_MODEL, _map.at(0, x, y).getObjectFrameLoop(0)) || _map.at(1, x, y).getType(0) != indie::OBJECTS_ID::EMPTY) { return; }
        indie::Tile &bombTile = _map.at(1, x, y);

        bombId = static_cast<int>(type) - static_cast<int>(indie::OBJECTS_ID::SQUAREBOMB);
        bombId += static_cast<int>(indie::SoundId::SOUND_EXPLOSION_1);
        sound = static_cast<indie::SoundId>(bombId);
        bombHandlers[type](bombTile, x, y);
        _soundsToPlay.push_back(indie::Sound(sound, indie::SoundAction::UNIQUE, _settings.volume));
        return;
      }
    }
  }
}

void indie::Game::handleEvents() {
  std::for_each(_events.begin(), _events.end(),
  [this](const Event &event) {
    std::vector<indie::Player>::iterator it;
    if (_gameState == indie::GameState::INGAME &&
        event.type == indie::EventType::ET_KEYBOARD &&
        event.action == indie::ActionType::AT_PRESSED) {
        if ((it = std::find_if(_settings.players.begin(), _settings.players.end(),
                  [&event](Player &psettings)-> bool{
                    return event.kb_key == psettings.move_left;
                  })) != _settings.players.end()) { move((*it).id, indie::ELookAt::WEST); }
        else if ((it = std::find_if(_settings.players.begin(), _settings.players.end(),
                        [&event](Player &psettings)-> bool{
                          return event.kb_key == psettings.move_right;
                        })) != _settings.players.end()) { move((*it).id, indie::ELookAt::EAST); }
        else if ((it = std::find_if(_settings.players.begin(), _settings.players.end(),
                        [&event](Player &psettings)-> bool{
                          return event.kb_key == psettings.move_down;
                        })) != _settings.players.end()) { move((*it).id, indie::ELookAt::SOUTH); }
        else if ((it = std::find_if(_settings.players.begin(), _settings.players.end(),
                        [&event](Player &psettings)-> bool{
                          return event.kb_key == psettings.move_up;
                        })) != _settings.players.end()) { move((*it).id, indie::ELookAt::NORTH); }
        else if ((it = std::find_if(_settings.players.begin(), _settings.players.end(),
                        [&event](Player &psettings)-> bool{
                          return event.kb_key == psettings.bomb;
                        })) != _settings.players.end()) { bomb((*it).id); }

      } else { _gui.notifyEvent(event); }
  });
  _events.clear();
}
