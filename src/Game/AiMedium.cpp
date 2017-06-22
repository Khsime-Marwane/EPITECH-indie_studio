#include "Game/AiMedium.hpp"

indie::AiMedium::AiMedium(const int &new_id)
: indie::AAI(new_id)
{
}

indie::AiMedium::~AiMedium()
{

}

void indie::AiMedium::loop(const Map &new_map,
                          const int &nb_players) {
    bool isAlive = false;
    for (int y = 0; y < static_cast<int>(new_map.getHeight()); y++) {
      for (int x = 0; x < static_cast<int>(new_map.getWidth()); x++) {
      if (new_map.at(0, x, y).getType(0) == static_cast<indie::OBJECTS_ID>(this->id))
        {
           isAlive = true;
        }
      }
    }
    if (isAlive)
      {
        getPosition(new_map);
        getEmptyCase(new_map);
        getSafeCase(new_map);
        if (shift_ok == true)
          {
            if (safe_case[pos.second][pos.first] == false
                || new_map.at(1, pos.first, pos.second).getType(0) > static_cast<indie::OBJECTS_ID>(6))
              {
                run(new_map);
              }
            else
              {
                getClosestEnemy(nb_players, new_map);
                goOnEnemy(new_map);
              }
          }
        else
          {
            if (direction == indie::ELookAt::NORTH)
              goUp(new_map);
            else if (direction == indie::ELookAt::SOUTH)
              goDown(new_map);
            else if (direction == indie::ELookAt::EAST)
              goRight(new_map);
            else if (direction == indie::ELookAt::WEST)
              goLeft(new_map);
          }
    }
}
