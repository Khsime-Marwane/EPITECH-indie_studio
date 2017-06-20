#include "Game/Game.hpp"

void indie::Game::bonusTimer() {
  std::for_each(_settings.players.begin(), _settings.players.end(),
    [](indie::Player &playerInfo){
      std::remove_if(playerInfo.bonus.begin(), playerInfo.bonus.end(),
        [](indie::Bonus &bonus){
          bonus.duration--;
          return bonus.duration == 0;
        });
    });
}

std::vector<indie::Player>::const_iterator indie::Game::getPlayerSettings(size_t id) const {
  return std::find_if(_settings.players.begin(), _settings.players.end(),
        [&id](const indie::Player &playerInfo){
          return playerInfo.id == id;
        });
}

indie::OBJECTS_ID indie::Game::getBombType(size_t playerId) const {
  std::vector<indie::Player>::const_iterator playerInfo_it = getPlayerSettings(playerId);
  std::vector<indie::Bonus>::const_iterator bonus_it;

  bonus_it =
  std::find_if((*playerInfo_it).bonus.begin(), (*playerInfo_it).bonus.end(),
    [](const indie::Bonus &bonus){
      return bonus.type == BONUS_SQUAREBOMB || bonus.type == BONUS_TENTACLEBOMB;
    });
    //return indie::OBJECTS_ID::TENTACLEBOMB;
    //return indie::OBJECTS_ID::SQUAREBOMB;
  if (bonus_it == (*playerInfo_it).bonus.end()) { return indie::OBJECTS_ID::PIKESBOMB; }
  return static_cast<indie::OBJECTS_ID>((*bonus_it).type);
}
