#include "Game/Game.hpp"

void indie::Game::reset() {
  //_map.reset();
  _settings = {
    50.0f, indie::IA_LEVEL::IA_MEDIUM,
    std::vector<indie::Player>(),
    1, indie::PlayMod::PLAY_MOD_UNKNOWN
  };
}

void indie::Game::AIhandler() {
  std::for_each(_settings.players.begin(), _settings.players.end(),
    [this](Player &player) {
      if (player.type == indie::PlayerType::PLAYER_AI) {
        // call ai(player, _settings.difficulty);
      }
    });
}

void indie::Game::splashScreen() {
  _gameState = indie::GameState::MAIN_MENU;
  _gui.loadComponents(_gameState);
}

void indie::Game::gameProcess() {
  bonusTimer();
  updateAnimations();
  handleEvents();
  AIhandler();
}

void indie::Game::menuProcess() {
    handleEvents();
    while (_timer.Elapsed().count() < 70);
    _timer.Reset();
}

void indie::Game::process() {
  static std::map<indie::GameState, indie::TurnHandler> handlers = {
    { indie::GameState::SPLASH_SCREEN, [this]() -> void { this->splashScreen(); } },
    { indie::GameState::INGAME, [this]() -> void { this->gameProcess(); } },
    { indie::GameState::MAIN_MENU, [this]() -> void { this->menuProcess(); } },
    { indie::GameState::SETTINGS, [this]() -> void { this->menuProcess(); } },
    { indie::GameState::ROOM, [this]() -> void { this->menuProcess(); } }
  };
  _soundsToPlay.clear();
  if (handlers.find(_gameState) != handlers.end()) { return handlers[_gameState](); }
  handleEvents();
}
