#include "Game/AiSimple.hpp"

indie::AiSimple::AiSimple(const int &new_id)
: indie::AAI(new_id)
{
}

indie::AiSimple::~AiSimple()
{

}

void indie::AiSimple::loop(const Map &new_map,
                          const int &nb_players) {
    (void)nb_players;
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
        if ((pos.first + 1 < static_cast<int>(new_map.getWidth())) &&
              new_map.at(0, pos.first + 1, pos.second).getType(0) > indie::OBJECTS_ID::EMPTY &&
              new_map.at(0, pos.first + 1, pos.second).getType(0) < indie::OBJECTS_ID::BOX)
            dropPikesBomb();
        else if ((pos.first - 1) >= 0 &&
                  new_map.at(0, pos.first - 1, pos.second).getType(0) > indie::OBJECTS_ID::EMPTY &&
                  new_map.at(0, pos.first - 1, pos.second).getType(0) < indie::OBJECTS_ID::BOX)
            dropPikesBomb();
        else if ((pos.second - 1) >= 0 && new_map.at(0, pos.first, pos.second - 1).getType(0) > indie::OBJECTS_ID::EMPTY &&
                  new_map.at(0, pos.first, pos.second - 1).getType(0) < indie::OBJECTS_ID::BOX)
            dropPikesBomb();
        else if ((pos.second + 1) < static_cast<int>(new_map.getHeight()) &&
                  new_map.at(0, pos.first, pos.second + 1).getType(0) > indie::OBJECTS_ID::EMPTY &&
                  new_map.at(0, pos.first, pos.second + 1).getType(0) < indie::OBJECTS_ID::BOX)
              dropPikesBomb();
        else
          action = indie::AiAction::UNKNOWN;
      }
}
