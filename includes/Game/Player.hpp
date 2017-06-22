#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include <map>
# include <vector>
# include <algorithm>
# include "Interfaces/Event.hpp"
# include "Interfaces/ITile.hpp"
# include "Interfaces/IAI.hpp"
# include "Game/AiMedium.hpp"
# include "Game/AiSimple.hpp"
# include "Game/Settings.hpp"
# include "Game/ModelsId.hpp"

namespace indie {
  class Player {
  public:
    Player(size_t,
           indie::Map &,
           size_t,
           PlayerType = PlayerType::PLAYER_HUMAN,
           IA_LEVEL = IA_UNKNOWN);
    ~Player() {};

  public:
    size_t getId() const { return _id; }
    indie::OBJECTS_ID getBombType() const { return _bombType; };
    const std::map<std::string, KeyboardKey> &getBindings() const { return _bindings; };
    int getScore() const { return _score; }
    bool hasBomb(size_t) const;
    bool isAlive() const { return _alive; }
    bool isTired() const { return _bombs.size() > 0; };
    indie::PlayerType getType() const { return _type; }

  public:
    void setBombType(indie::OBJECTS_ID bombType);
    void bomb(size_t id) { _bombs.push_back(id); }
    void useBomb();
    void removeBomb(size_t);
    void updateScore(int points) { _score += points; }
    void die() { _score -= 200; _alive = false; }

  public:
    AiAction think();

  private:
    size_t                             _id;
    std::map<std::string, KeyboardKey> _bindings;
    OBJECTS_ID                         _bombType;
    std::vector<size_t>                _bombs;
    int                                _score;
    bool                               _alive;
    IA_LEVEL                           _level;
    PlayerType                         _type;
    std::unique_ptr<IAI>               _ai;
    indie::Map                         &_map;
    size_t                             _nplayers;
    size_t                             _uses;
  };
};

#endif // PLAYER_HPP
