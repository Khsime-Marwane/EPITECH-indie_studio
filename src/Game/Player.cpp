#include "Game/Player.hpp"

indie::Player::Player(size_t id,
                      indie::Map &map,
                      size_t nplayers,
                      indie::PlayerType type, indie::IA_LEVEL level) :
  _id(id),
  _bindings(),
  _bombType(indie::OBJECTS_ID::PIKESBOMB),
  _bombs(),
  _score(0),
  _alive(true),
  _level(level),
  _type(type),
  _ai(),
  _map(map),
  _nplayers(nplayers),
  _uses(2) {
    if (type == indie::PlayerType::PLAYER_AI) {
      if (level == indie::IA_LEVEL::IA_MEDIUM)
        {
          _ai = std::make_unique<indie::AiSimple>(id);
          _bindings = {
            { "LEFT", indie::KeyboardKey::KB_NONE },
            { "RIGHT", indie::KeyboardKey::KB_NONE },
            { "DOWN", indie::KeyboardKey::KB_NONE },
            { "UP", indie::KeyboardKey::KB_NONE },
            { "BOMB", indie::KeyboardKey::KB_NONE }
          };
        }
      else
        {
          _ai = std::make_unique<indie::AiMedium>(id);
          _bindings = {
            { "LEFT", indie::KeyboardKey::KB_NONE },
            { "RIGHT", indie::KeyboardKey::KB_NONE },
            { "DOWN", indie::KeyboardKey::KB_NONE },
            { "UP", indie::KeyboardKey::KB_NONE },
            { "BOMB", indie::KeyboardKey::KB_NONE }
          };
        }
    }
    else
      {
        if (id == 1) {
          _bindings = {
            { "LEFT", indie::KeyboardKey::KB_Q },
            { "RIGHT", indie::KeyboardKey::KB_D },
            { "DOWN", indie::KeyboardKey::KB_S },
            { "UP", indie::KeyboardKey::KB_Z },
            { "BOMB", indie::KeyboardKey::KB_E }
          };
        }
        else if (id == 2) {
          _bindings = {
            { "LEFT", indie::KeyboardKey::KB_ARROW_LEFT },
            { "RIGHT", indie::KeyboardKey::KB_ARROW_RIGHT},
            { "DOWN", indie::KeyboardKey::KB_ARROW_DOWN },
            { "UP", indie::KeyboardKey::KB_ARROW_UP },
            { "BOMB", indie::KeyboardKey::KB_RSHIFT }
          };
        }
        else if (id == 3) {
          _bindings = {
            { "LEFT", indie::KeyboardKey::KB_G },
            { "RIGHT", indie::KeyboardKey::KB_J},
            { "DOWN", indie::KeyboardKey::KB_H },
            { "UP", indie::KeyboardKey::KB_Y },
            { "BOMB", indie::KeyboardKey::KB_T }
          };
        }
        else if (id == 4) {
          _bindings = {
            { "LEFT", indie::KeyboardKey::KB_K },
            { "RIGHT", indie::KeyboardKey::KB_M},
            { "DOWN", indie::KeyboardKey::KB_L },
            { "UP", indie::KeyboardKey::KB_O },
            { "BOMB", indie::KeyboardKey::KB_I }
          };
        }
    }
}

bool indie::Player::hasBomb(size_t id) const {
  return std::find_if(_bombs.begin(), _bombs.end(),
          [&id](const size_t &idSaved) {
            return id == idSaved;
          }) != _bombs.end();
}

void indie::Player::removeBomb(size_t id) {
  _bombs.erase(std::remove(_bombs.begin(), _bombs.end(), id), _bombs.end());
}

indie::AiAction indie::Player::think() {
  _ai->loop(_map, static_cast<int>(_nplayers));
  if (_ai->getAction() >= static_cast<AiAction>(0) && _ai->getAction() < static_cast<AiAction>(4))
    {
      std::pair<int, int> pos;

      pos = _ai->getPosition(_map);
      if (_ai->getAction() == AI_LEFT || _ai->getAction() == AI_RIGHT)
        _map.at(0, pos.first, pos.second).setShiftY(0, 0.0);
      else if (_ai->getAction() == AI_DOWN || _ai->getAction() == AI_UP)
        _map.at(0, pos.first, pos.second).setShiftX(0, 0.0);
    }
  return _ai->getAction();
}

void  indie::Player::setBombType(indie::OBJECTS_ID bombtype)
{
  this->_uses = 2;
  _bombType = bombtype;
}

void  indie::Player::useBomb()
{
  this->_uses--;
  if (this->_uses == 0)
    setBombType(indie::OBJECTS_ID::PIKESBOMB);
}
