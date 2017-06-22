#include "Game/Game.hpp"

void indie::Game::checkBonus(indie::Tile &playerTile, indie::Tile &target) {
  indie::Player &player = getPlayerById(playerTile.getObjectId(0));
  indie::OBJECTS_ID type = target.getType(0);

  if (type == indie::OBJECTS_ID::BONUS_SQUAREB) {
    _map.deleteObjectById(target.getObjectId(0));
    target.setElem(0, 0, indie::OBJECTS_ID::EMPTY,
                    false, indie::MODELS_ID::UNKNOWN, true,
                    {0, 0}, "", target.getObjectRotation(0),
                  target.getShiftX(0), target.getShiftY(0));
    player.setBombType(indie::OBJECTS_ID::SQUAREBOMB);
  }
  else if (type >= indie::OBJECTS_ID::BONUS_TENTACLEB) {
    _map.deleteObjectById(target.getObjectId(0));
    target.setElem(0, 0, indie::OBJECTS_ID::EMPTY,
                    false, indie::MODELS_ID::UNKNOWN, true,
                    {0, 0}, "", target.getObjectRotation(0),
                  target.getShiftX(0), target.getShiftY(0));
    player.setBombType(indie::OBJECTS_ID::TENTACLEBOMB);
  }
}

void indie::Game::checkDeath(indie::Tile &playerTile,
                             size_t x, size_t y) {
  indie::Tile &bombTile = _map.at(1, x, y);
  size_t tileSize = bombTile.getTileSize();
  indie::OBJECTS_ID type;

  for (size_t i = 0; i < tileSize; i++) {
    type = bombTile.getType(i);

    if (type >= indie::OBJECTS_ID::SQUAREBOMB &&
        type <= indie::OBJECTS_ID::TENTACLEBOMB &&
        indie::ResourceHandler::isFrameLethal(type, bombTile.getObjectFrameLoop(i))) {

      playerTile.setDoesAnimationChanged(0, true);
      playerTile.setObjectFrameLoop(0, indie::ResourceHandler::getSkeletonFrame("DIE"));
    }
  }
}

indie::Tile &indie::Game::move_left(indie::Tile &player,
                                    size_t x, size_t y) {
  double newShift;
  bool tangible;
  newShift = player.getShiftX(0) - PLAYER_SPEED;
  tangible = (x == 0 || _map.at(0, x - 1, y).isTangible(0) || _map.at(1, x - 1, y).isTangible(0));
  if (newShift < 0.0 && !tangible && player.getShiftY(0) <= 0.3) {
    indie::Tile &nearPlayerTile = _map.at(0, x - 1, y);

    checkBonus(player, nearPlayerTile);
    nearPlayerTile = player;
    player.reset();
    nearPlayerTile.setShiftX(0, 1.0 + newShift);
    nearPlayerTile.setShiftY(0, 0);
    checkDeath(nearPlayerTile, x - 1, y);
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

    checkBonus(player, nearPlayerTile);
    nearPlayerTile = player;
    player.reset();
    nearPlayerTile.setShiftX(0, newShift - 1.0);
    nearPlayerTile.setShiftY(0, 0);
    checkDeath(nearPlayerTile, x + 1, y);
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

    checkBonus(player, nearPlayerTile);
    nearPlayerTile = player;
    player.reset();
    nearPlayerTile.setShiftY(0, newShift - 1.0);
    nearPlayerTile.setShiftX(0, 0.0);
    checkDeath(nearPlayerTile, x, y + 1);
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

    checkBonus(player, nearPlayerTile);
    nearPlayerTile = player;
    player.reset();
    nearPlayerTile.setShiftY(0, 1.0 + newShift);
    nearPlayerTile.setShiftX(0, 0.0);
    checkDeath(nearPlayerTile, x, y - 1);
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

        ntile.setObjectRotation(0, dir);
        ntile.setDoesAnimationChanged(0, true);

        if (!indie::ResourceHandler::isDeathFrame(ntile.getModelId(0), ntile.getObjectFrameLoop(0))) {

          std::pair<size_t, size_t> run_frame = indie::ResourceHandler::getSkeletonFrame("RUN");
          ntile.setObjectFrameLoop(0, run_frame);
        }
      }
    }
  }
}

void indie::Game::SquareBomb(indie::Tile &bombTile, indie::Player &player) {
  size_t objectId = _map.newId();

  _map.addObjectById(objectId);
  player.bomb(objectId);
  bombTile.setElem(bombTile.getTileSize(), objectId,
                   indie::OBJECTS_ID::SQUAREBOMB,
                   true, indie::MODELS_ID::SQUAREBOMB_MODEL, true,
                   indie::ResourceHandler::getNextFrame(indie::OBJECTS_ID::SQUAREBOMB, {0, 0}),
                   indie::ResourceHandler::getTexture(indie::MODELS_ID::SQUAREBOMB_MODEL));
}

void indie::Game::PikesBomb(indie::Tile &bombTile,
                            size_t center_x, size_t center_y,
                            indie::Player &player) {
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

                      if (_map.at(0, targetPos.first, targetPos.second).getType(0) == indie::OBJECTS_ID::WALL) {
                        stopPropagation[x] = true;
                      }
                      else
                        {
                          indie::Tile &target = _map.at(1, targetPos.first, targetPos.second);

                          objectId = _map.newId();
                          _map.addObjectById(objectId);
                          player.bomb(objectId);
                          modelId = static_cast<size_t>(indie::MODELS_ID::PIKES_MODEL_1) + rand() % 4;
                          target.setElem(target.getTileSize(), objectId,
                                         indie::OBJECTS_ID::PIKESBOMB,
                                         true, static_cast<indie::MODELS_ID>(modelId), true,
                                         indie::ResourceHandler::getNextFrame(indie::OBJECTS_ID::PIKESBOMB, {0, 0}),
                                         indie::ResourceHandler::getTexture(static_cast<indie::MODELS_ID>(modelId)));

                          if ((_map.at(0, targetPos.first, targetPos.second).getType(0) == indie::OBJECTS_ID::BOX &&
                              _map.at(0, targetPos.first, targetPos.second).getObjectFrameLoop(0) != indie::ResourceHandler::getLethalFrame(indie::OBJECTS_ID::BOX)) ||
                              _map.at(0, targetPos.first, targetPos.second).getType(0) == indie::OBJECTS_ID::WALL) {
                            stopPropagation[x] = true;
                          }
                        }
                    } else { stopPropagation[x] = true; }
                    x++;
                  });
  }
  objectId  = _map.newId();
  _map.addObjectById(objectId);
  player.bomb(objectId);
  bombTile.setElem(bombTile.getTileSize(), objectId,
                   indie::OBJECTS_ID::PIKESBOMB,
                   true, indie::MODELS_ID::PIKES_MODEL_CENTER, true,
                   indie::ResourceHandler::getNextFrame(indie::OBJECTS_ID::PIKESBOMB, {0, 0}),
                   indie::ResourceHandler::getTexture(indie::MODELS_ID::PIKES_MODEL_CENTER));
}

void indie::Game::TentacleBomb(indie::Tile &bombTile,
                               size_t x, size_t y,
                               indie::Player &player) {
  size_t eastSize = 0;
  size_t northSize = 0;
  size_t westSize = 0;
  size_t southSize = 0;
  size_t objectId;

  while (westSize < 6 && x >= (westSize + 1) && _map.at(0, x - (westSize + 1), y).getType(0) != indie::OBJECTS_ID::WALL) { westSize++; }
  while (northSize < 6 && y >= (northSize + 1) && _map.at(0,  x, y - (northSize + 1)).getType(0) != indie::OBJECTS_ID::WALL) { northSize++; }
  while (eastSize < 6 && (x + (eastSize + 1)) < _map.getWidth() && _map.at(0, x + (eastSize + 1), y).getType(0) != indie::OBJECTS_ID::WALL) { eastSize++; }
  while (southSize < 6 && (y + (southSize + 1)) < _map.getHeight() && _map.at(0, x, y + (southSize + 1)).getType(0) != indie::OBJECTS_ID::WALL) { southSize++; }

  std::vector<indie::MODELS_ID> models = {
    indie::MODELS_ID::TENTACLE_MODEL_PORTAL,
    westSize > 0 ? static_cast<indie::MODELS_ID>(westSize + 7) : indie::MODELS_ID::UNKNOWN,
    northSize > 0 ? static_cast<indie::MODELS_ID>(northSize + 7) : indie::MODELS_ID::UNKNOWN,
    eastSize > 0 ? static_cast<indie::MODELS_ID>(eastSize + 7) : indie::MODELS_ID::UNKNOWN,
    southSize > 0 ? static_cast<indie::MODELS_ID>(southSize + 7) : indie::MODELS_ID::UNKNOWN,
  };
  std::vector<indie::ELookAt> dirs = {
    indie::ELookAt::SOUTH,
    indie::ELookAt::NORTH,
    indie::ELookAt::EAST,
    indie::ELookAt::SOUTH,
    indie::ELookAt::WEST
  };
  for (size_t i = 0; i < 5; i++) {
    if (models[i] != indie::MODELS_ID::UNKNOWN)
      {
        objectId = _map.newId();
        if (i != 0) { bombTile.newElem(objectId); }
        _map.addObjectById(objectId);
        player.bomb(objectId);
        bombTile.setElem(bombTile.getTileSize(), objectId,
                         indie::OBJECTS_ID::TENTACLEBOMB,
                         true, models[i], true,
                         indie::ResourceHandler::getNextFrame(indie::OBJECTS_ID::TENTACLEBOMB, {0, 0}),
                         indie::ResourceHandler::getTexture(models[i]),
                         dirs[i]);
      }
  }
}

void indie::Game::bomb(size_t playerId) {
  static std::map<indie::OBJECTS_ID, std::function<void(indie::Tile &, size_t, size_t, indie::Player &)> > bombHandlers = {
    { indie::OBJECTS_ID::SQUAREBOMB, [this](indie::Tile &tile, size_t x, size_t y, indie::Player &player){ (void)x; (void)y; this->SquareBomb(tile, player); } },
    { indie::OBJECTS_ID::PIKESBOMB, [this](indie::Tile &tile, size_t x, size_t y, indie::Player &player){ this->PikesBomb(tile, x, y, player); } },
    { indie::OBJECTS_ID::TENTACLEBOMB, [this](indie::Tile &tile, size_t x, size_t y, indie::Player &player){ this->TentacleBomb(tile, x, y, player); } }
  };
  indie::Player &player = getPlayerById(playerId);
  indie::OBJECTS_ID type = player.getBombType();
  indie::SoundId sound;

  int bombId;

  if (player.isTired()) { return; }

  player.useBomb();
  for (std::size_t y = 0; y < _map.getHeight(); y++) {
    for (std::size_t x = 0; x < _map.getWidth(); x++) {
      if (_map.at(0, x, y).getType(0) == static_cast<indie::OBJECTS_ID>(playerId)) {
        if (indie::ResourceHandler::isDeathFrame(indie::MODELS_ID::SKELETON_MODEL, _map.at(0, x, y).getObjectFrameLoop(0))) { return; }
        indie::Tile &bombTile = _map.at(1, x, y);

        bombId = static_cast<int>(type) - static_cast<int>(indie::OBJECTS_ID::SQUAREBOMB);
        bombId += static_cast<int>(indie::SoundId::SOUND_EXPLOSION_1);
        sound = static_cast<indie::SoundId>(bombId);
        bombHandlers[type](bombTile, x, y, player);
        _map.at(0, x, y).setDoesAnimationChanged(0, true);
        _map.at(0, x, y).setObjectFrameLoop(0, indie::ResourceHandler::getSkeletonFrame("CAST"));
        _soundsToPlay.push_back(indie::Sound(sound, indie::SoundAction::UNIQUE, _settings.volume));
        return;
      }
    }
  }
}

void indie::Game::handleEvents() {
  static std::map<std::string, std::function<void(size_t)> > eventHandlers = {
    { "LEFT", [this](size_t id) { move(id, indie::ELookAt::WEST); }},
    { "RIGHT", [this](size_t id) { move(id, indie::ELookAt::EAST); }},
    { "DOWN", [this](size_t id) { move(id, indie::ELookAt::SOUTH); }},
    { "UP", [this](size_t id) { move(id, indie::ELookAt::NORTH); }},
    { "BOMB", [this](size_t id) { bomb(id); }}
  };

  GameState state = _gameState;
  float volume = _settings.volume;
  ECAMERA_VIEW view = _map.getPOV();

  std::for_each(_events.begin(), _events.end(),
                [&](const Event &event) {
                  if (_gameState == indie::GameState::INGAME &&
                      event.type == indie::EventType::ET_KEYBOARD &&
                      event.action == indie::ActionType::AT_PRESSED) {

                    if (std::find_if(_players.begin(), _players.end(),
                                 [&](std::unique_ptr<indie::Player> &player){

                                   if (player->isAlive()) {
                                     const std::map<std::string, indie::KeyboardKey> &bindings = player->getBindings();
                                     std::map<std::string, indie::KeyboardKey>::const_iterator binding_it;

                                     binding_it = std::find_if(bindings.begin(), bindings.end(),
                                                               [&event](const std::pair<std::string, indie::KeyboardKey> &binding) {
                                                                 return binding.second == event.kb_key;
                                                               });
                                     if (binding_it != bindings.end()) {
                                       eventHandlers[(*binding_it).first](player->getId());
                                       return true;
                                     }
                                   }

                                   return false;
                        }) == _players.end()) {
                          if ((event.kb_key == KB_PAGEUP || event.kb_key == KB_PAGEDOWN) && view == _map.getPOV()) {
                            _map.setCameraPOV(_map.getPOV() == ECAMERA_VIEW::DEFAULT ? ECAMERA_VIEW::INCLINED : ECAMERA_VIEW::DEFAULT);
                          }
                          else { _gui.notifyEvent(event); }
                        }
                  } else if (_gameState == state) { _gui.notifyEvent(event); }

  });
  std::vector<indie::Sound> &gui_sounds = _gui.getSounds();

  _soundsToPlay.insert(_soundsToPlay.begin(), gui_sounds.begin(), gui_sounds.end());
  _events.clear();
  gui_sounds.clear();
  if (volume < _settings.volume || volume > _settings.volume) {
    _soundsToPlay.push_back(indie::Sound(_settings.music.id, indie::SoundAction::VOLUME,
                                        _settings.volume, indie::SoundType::MUSIC));
  }
  if (state != indie::GameState::PAUSE_GAME && state != _gameState &&
      _gameState == indie::GameState::INGAME) {
    start();
  }
}
