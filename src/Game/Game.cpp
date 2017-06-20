#include "Game/Game.hpp"

indie::Game::Game() :
  _timer(),
  _soundsToPlay({indie::Sound(indie::SoundId::SOUND_SKELELETON_SPAWN, indie::SoundAction::UNIQUE, 50.0f)}),
  _music(indie::Sound(indie::SoundId::SOUND_NONE, indie::SoundAction::PLAY, 50.0f)),
  _gameState(SPLASH_SCREEN),
  _events(),
  _map(0),
  _settings({ 50.0f, IA_LEVEL::IA_MEDIUM, std::vector<Player>(), 1, indie::PlayMod::PLAY_MOD_LOCAL}),
  _gui(_settings, _gameState),
  _objectsStates()
 {
 _settings.players.push_back({
   indie::KeyboardKey::KB_Q, indie::KeyboardKey::KB_D,
   indie::KeyboardKey::KB_Z, indie::KeyboardKey::KB_S,
   indie::KeyboardKey::KB_E,
   std::vector<indie::Bonus>(),
   1, indie::PlayerType::PLAYER_HUMAN});
 }

indie::Game::~Game() {}

void indie::Game::initSettings() {
  _settings = {
    50.0f, indie::IA_LEVEL::IA_MEDIUM,
    std::vector<indie::Player>(),
    0, indie::PlayMod::PLAY_MOD_UNKNOWN
  };
}

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
  /*const std::vector<indie::Souns> &gui_sounds = _gui.getSoundsToPlay(); TODO add gui sounds
  _soundsToPlay.inset(_soundsToPlay.begin(), gui_sound.begin()), gui_sounds.end());
   if (_gui.hasVolumeChanged()) {
   _music.mode = indie::Sound::VOLUME;
    _music.volume = _settings.volume;
    _soundsToPlay.push_back(_music);
  }*/
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
