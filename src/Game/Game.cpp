#include "Game/Game.hpp"

indie::Game::Game() :
  _players(),
  _soundsToPlay(),
  _music(indie::Sound(indie::SoundId::SOUND_NONE, indie::SoundAction::PLAY, 50.0f)),
  _gameState(SPLASH_SCREEN),
  _events(),
  _map(),
  _settings(_players),
  _gui(_settings, _gameState),
  _objectsStates()
 {
  srand(0);
 }

indie::Game::~Game() {}

indie::GameState indie::Game::getGameState() const {
  return _gameState;
}

void indie::Game::notifyEvent(std::vector<Event> &&events) {
  _events.insert(_events.end(), events.begin(), events.end());
}

const std::vector<size_t> &indie::Game::getObjectsId() const {
  return _map.getObjectsId();
}

const std::vector<indie::Sound> &indie::Game::getSoundsToPlay() const {
  return _soundsToPlay;
}

const indie::IMap &indie::Game::getCurrentMap() const {
  return _map;
}

const indie::IGUI &indie::Game::getCurrentGUI() const {
  return _gui;
}

void indie::Game::setObjectsAnimationState(const std::vector<indie::AnimationState> &objectsStates) {
  _objectsStates = objectsStates;
}

indie::Player &indie::Game::getBombOwner(size_t bombId) {
  std::vector<std::unique_ptr<indie::Player> >::iterator player_it;

  player_it = std::find_if(_players.begin(), _players.end(),
                [&bombId](std::unique_ptr<indie::Player> &player) {
                  return player->hasBomb(bombId);
                });
  return *(*player_it);
}

indie::Player &indie::Game::getPlayerById(size_t playerId) {
  std::vector<std::unique_ptr<indie::Player> >::iterator player_it;

  player_it = std::find_if(_players.begin(), _players.end(),
            [&playerId](std::unique_ptr<indie::Player> &player)-> bool {
              return player->getId() == playerId;
            });
  return *(*player_it);
}

void indie::Game::reward() {
  std::for_each(_players.begin(), _players.end(),
  [&](std::unique_ptr<indie::Player> &player) {
    if (player->isAlive()) {
      _soundsToPlay.push_back(indie::Sound(indie::SoundId::SOUND_EVIL_LAUGH, indie::SoundAction::UNIQUE, _settings.volume));
      player->updateScore(500);
    }
  });
}

bool indie::Game::isEnded() const {
  int nPlayers = 0;

  nPlayers =
    std::accumulate(_players.begin(), _players.end(), 0,
    [](int i, const std::unique_ptr<Player> &player)->int {
      return i + static_cast<int>(player->isAlive());
    });
  return nPlayers < 2;
}

void indie::Game::reset() {
  _players.clear();
  _music = indie::Sound(indie::SoundId::SOUND_NONE, indie::SoundAction::PLAY, 50.0f);
  _events.clear();
  _map.clear();
  _objectsStates.clear();
  _settings.timer.Reset();
}

void indie::Game::start() {
  size_t totalPlayers = _settings.nPlayers + _settings.nAIs;

  reset();
  _map.init(0, totalPlayers);
  getNextFallingPillarPos(true);
  _soundsToPlay.push_back(indie::Sound(indie::SoundId::SOUND_SKELELETON_SPAWN, indie::SoundAction::UNIQUE, _settings.volume));

  for (size_t i = 1; i <= _settings.nPlayers; i++) {
    _players.push_back(std::make_unique<indie::Player>(i, _map, totalPlayers));
  }
  for (size_t i = _settings.nPlayers + 1; i <= totalPlayers; i++) {
    _players.push_back(std::make_unique<indie::Player>(i, _map, totalPlayers,
                                    indie::PlayerType::PLAYER_AI, _settings.difficulty));
  }
}
