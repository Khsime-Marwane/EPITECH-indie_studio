#ifndef IAI_HPP
# define IAI_HPP

# include "Game/Tile.hpp"
# include "Game/Map.hpp"
# include <vector>

namespace indie {


  typedef enum e_AiAction {
    UNKNOWN = -1,
    AI_UP,
    AI_DOWN,
    AI_LEFT,
    AI_RIGHT,
    AI_BOMB
  }                 AiAction;

  class IAI
  {
    public:
      virtual ~IAI() { };
      virtual const int &getId() = 0;
      virtual const ELookAt &getDirection() = 0;
      virtual void goUp(const Map &map) = 0;
      virtual void goDown(const Map &map) = 0;
      virtual void goLeft(const Map &map) = 0;
      virtual void goRight(const Map &map) = 0;
      virtual void dropPikesBomb() = 0;
      virtual void dropSquareBomb() = 0;
      virtual void dropTentacleBomb() = 0;
      virtual const std::pair<int, int> &getPosition(const Map &) = 0;
      virtual void getClosestEnemy(const int &, const Map &) = 0;
      virtual const indie::e_AiAction &getAction() = 0;
      virtual void getEmptyCase(const Map &) = 0;
      virtual void getClosestSafeCase(const Map &map) = 0;
      virtual void getSafeCase(const Map &) = 0;
      virtual void run(const Map &map) = 0;
      virtual void goOnEnemy(const Map &map) = 0;
      virtual void loop(const Map &, const int &) = 0;
  };

};

#endif /* IAI_HPP */
