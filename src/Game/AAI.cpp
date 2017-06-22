#include "Game/AAI.hpp"

indie::AAI::AAI(const int &new_id)
: id(new_id),
  shift_ok(true),
  wait(false),
  action(indie::e_AiAction::UNKNOWN),
  direction(),
  pos(),
  empty_case(),
  safe_case(),
  case_safe(),
  pos_enemy()
{
}

indie::AAI::~AAI()
{

}

const int &indie::AAI::getId()
{
  return(this->id);
}

const indie::ELookAt &indie::AAI::getDirection()
{
  return(this->direction);
}

void indie::AAI::goUp(const Map &map)
{
  shift_ok = false;
  if (map.at(0, pos.first, pos.second).getShiftX(0) <= 0.1)
    shift_ok = true;
  this->action = indie::AiAction::AI_UP;
  this->direction = indie::ELookAt::NORTH;
}

void indie::AAI::goDown(const Map &map)
{
  shift_ok = false;
  if (map.at(0, pos.first, pos.second).getShiftX(0) <= 0.1)
    shift_ok = true;
  this->action = indie::AiAction::AI_DOWN;
  this->direction = indie::ELookAt::SOUTH;
}

void indie::AAI::goLeft(const Map &map)
{
  shift_ok = false;
  if (map.at(0, pos.first, pos.second).getShiftY(0) <= 0.1)
    shift_ok = true;
  this->action = indie::AiAction::AI_LEFT;
  this->direction = indie::ELookAt::WEST;
}

void indie::AAI::goRight(const Map &map)
{
  shift_ok = false;
  if (map.at(0, pos.first, pos.second).getShiftY(0) <= 0.0)
    shift_ok = true;
  this->action = indie::AiAction::AI_RIGHT;
  this->direction = indie::ELookAt::EAST;
}

void indie::AAI::dropPikesBomb()
{
  this->action = indie::AiAction::AI_BOMB;
}

void indie::AAI::dropSquareBomb()
{
  this->action = indie::AiAction::AI_BOMB;
}

void indie::AAI::dropTentacleBomb()
{
  this->action = indie::AiAction::AI_BOMB;
}

const std::pair<int, int> &indie::AAI::getPosition(const Map &map)
{
  for (int y = 0; y < static_cast<int>(map.getHeight()); y++) {
    for (int x = 0; x < static_cast<int>(map.getWidth()); x++) {
      if (map.at(0, x, y).getType(0) == static_cast<indie::OBJECTS_ID>(this->id))
      {
        pos.first = x;
        pos.second = y;
        return (pos);
      }
    }
  }
  return (pos);
}

void indie::AAI::getClosestSafeCase(const Map &map)
{
  case_safe.first = 50;
  case_safe.second = 50;
  for (int y = 0; y < static_cast<int>(map.getHeight()); y++)
    {
      for (int x = 0; x < static_cast<int>(map.getWidth()); x++)
        {
          int new_safe;
          int old_safe;

          if (pos.first - x < 0)
            new_safe = (pos.first - x) * -1;
          else
            new_safe = (pos.first - x);
          if (pos.second - y < 0)
            new_safe = new_safe + (pos.second - y) * -1;
          else
            new_safe = new_safe + (pos.second - y);
          if (pos.first - case_safe.first < 0)
            old_safe = (pos.first - case_safe.first) * -1;
          else
            old_safe = (pos.first - case_safe.first);
          if (pos.second - case_safe.second < 0)
            old_safe = old_safe + (pos.second - case_safe.second) * -1;
          else
            old_safe = old_safe + (pos.second - case_safe.second);
          if (pos.first - x == 0)
            new_safe = new_safe + pos.first - x;
          if (pos.second == 0)
            new_safe = new_safe + pos.second - y;
          if (safe_case[y][x] == true &&
              new_safe <= old_safe ) {
                case_safe = {x, y};
              }
        }
  }
}

void indie::AAI::getClosestEnemy(const int &nb_players, const Map &map)
{
  pos_enemy.first = 50;
  pos_enemy.second = 50;
  for (int y = 0; y < static_cast<int>(map.getHeight()); y++) {
    for (int x = 0; x < static_cast<int>(map.getWidth()); x++) {
      for (int player_id = 1; player_id < nb_players; player_id++)
        {
          if (this->id != player_id &&
              map.at(0, x, y).getType(0) == static_cast<indie::OBJECTS_ID>(player_id)
              && (x + y) < (pos_enemy.first + pos_enemy.second)) {
                pos_enemy = {x, y};
        }
      }
    }
  }
}

const indie::e_AiAction &indie::AAI::getAction()
{
  return (this->action);
}

void indie::AAI::getEmptyCase(const Map &map)
{
  this->empty_case.clear();
  if (pos.first + 1 < static_cast<int>(map.getWidth()) && map.at(0, pos.first + 1, pos.second).getType(0) == indie::OBJECTS_ID::EMPTY)
    this->empty_case.push_back({pos.first + 1, pos.second});
  if (pos.first - 1 >= 0 && map.at(0, pos.first - 1, pos.second).getType(0)  == indie::OBJECTS_ID::EMPTY)
    this->empty_case.push_back({pos.first - 1, pos.second});
  if (pos.second + 1 < static_cast<int>(map.getHeight()) && map.at(0, pos.first, pos.second + 1).getType(0)  == indie::OBJECTS_ID::EMPTY)
    this->empty_case.push_back({pos.first, pos.second + 1});
  if (pos.second - 1 >= 0 && map.at(0, pos.first, pos.second - 1).getType(0)  == indie::OBJECTS_ID::EMPTY)
    this->empty_case.push_back({pos.first, pos.second -1});
}

void indie::AAI::getSafeCase(const Map &map)
{
  for (int y = 0; y < static_cast<int>(map.getHeight()); y++) {
    for (int x = 0; x < static_cast<int>(map.getWidth()); x++) {
      this->safe_case[y][x] = true;
    }
  }
  for (int y = 0; y < static_cast<int>(map.getHeight()); y++) {
    for (int x = 0; x < static_cast<int>(map.getWidth()); x++) {
      if (map.at(0, x, y).getType(0) == static_cast<indie::OBJECTS_ID>(id)
          && map.at(1, x, y).getType(0) > static_cast<indie::OBJECTS_ID>(6))
        this->safe_case[y][x] = false;
      else if (map.at(0, x, y).getType(0) != static_cast<indie::OBJECTS_ID>(id)
          && map.at(0, x, y).getType(0) > static_cast<indie::OBJECTS_ID>(0)
          && map.at(0, x, y).getType(0) <= static_cast<indie::OBJECTS_ID>(6))
          {
            this->safe_case[y][x] = false;
          }
      else if (map.at(1, x, y).getModelId(0) == indie::MODELS_ID::PIKES_MODEL_CENTER)
        {
          for (int square_y = y - 4; square_y <= y + 4; square_y++)
            {
              if (square_y >= 0 && square_y < static_cast<int>(map.getHeight()))
                    this->safe_case[square_y][x] = false;
            }
          for (int square_x = x - 4; square_x <= x + 4; square_x++)
            {
              if (square_x >= 0 && square_x < static_cast<int>(map.getWidth()))
                    this->safe_case[y][square_x] = false;
            }
        }
      else if (map.at(1, x, y).getType(0) == indie::OBJECTS_ID::TENTACLEBOMB)
        {
          for (int square_y = y - 7; square_y <= y + 7; square_y++)
            {
              if (square_y >= 0 && square_y < static_cast<int>(map.getHeight()))
                    this->safe_case[square_y][x] = false;
            }
          for (int square_x = x - 7; square_x <= x + 7; square_x++)
            {
              if (square_x >= 0 && square_x < static_cast<int>(map.getWidth()))
                    this->safe_case[y][square_x] = false;
            }
        }
      else if (map.at(1, x, y).getType(0) == indie::OBJECTS_ID::SQUAREBOMB)
        {
          for (int square_y = y - 2; square_y <= y + 2; square_y++) {
            for (int square_x = x - 2; square_x <= x + 2; square_x++) {
              if (square_y >= 0 && square_y < static_cast<int>(map.getHeight())
                  && square_x >= 0 && square_x < static_cast<int>(map.getWidth()))
                    this->safe_case[square_y][square_x] = false;
              }
            }
        }
      }
    }
}

void indie::AAI::run(const Map &map)
{
  bool action_done = false;
  getClosestSafeCase(map);
  for (long unsigned int i = 0; i < this->empty_case.size(); i++) {
    if (case_safe.first < this->pos.first && empty_case[i].first < this->pos.first)
      {
        action_done = true;
        goLeft(map);
        i = this->empty_case.size();
      }
    else if (case_safe.first > this->pos.first &&  empty_case[i].first > this->pos.first)
      {
        action_done = true;
        goRight(map);
        i = this->empty_case.size();
      }
    else if (case_safe.second < this->pos.second && empty_case[i].second < this->pos.second)
      {
        action_done = true;
        goUp(map);
        i = this->empty_case.size();
      }
    else if (case_safe.second > this->pos.second && empty_case[i].second > this->pos.second)
      {
        action_done = true;
        goDown(map);
        i = this->empty_case.size();
      }
  }
  if (action_done == false)
    {
      if (safe_case[pos.second][pos.first + 1] == true)
        goRight(map);
      if (safe_case[pos.second][pos.first - 1] == true)
        goLeft(map);
      if (safe_case[pos.second - 1][pos.first] == true)
        goUp(map);
      if (safe_case[pos.second + 1][pos.first] == true)
        goDown(map);
    }
}

void indie::AAI::goOnEnemy(const Map &map)
{
  bool action_done = false;
  for (long unsigned int i = 0; i < this->empty_case.size(); i++) {
    if (((pos_enemy.second - this->pos.second) == 1 && (pos_enemy.first- this->pos.first) == 0)
              || ((pos_enemy.second - this->pos.second) == 0 && (pos_enemy.first- this->pos.first) == 1)
              || ((pos_enemy.second - this->pos.second) == 0 && (pos_enemy.first- this->pos.first) == -1)
              || ((pos_enemy.second - this->pos.second) == -1 && (pos_enemy.first- this->pos.first) == 0))
      {
        action_done = true;
        i = this->empty_case.size();
        dropPikesBomb();
      }
    else if (pos_enemy.first < this->pos.first && empty_case[i].first < this->pos.first &&
            safe_case[pos.second][pos.first - 1] == true)
      {
        action_done = true;
        goLeft(map);
        i = this->empty_case.size();
      }
    else if (pos_enemy.first > this->pos.first && empty_case[i].first > this->pos.first &&
            safe_case[pos.second][pos.first + 1] == true)
      {
        action_done = true;
        goRight(map);
        i = this->empty_case.size();
      }
    else if (pos_enemy.second < this->pos.second && empty_case[i].second < this->pos.second &&
            safe_case[pos.second - 1][pos.first] == true)
      {
        action_done = true;
        goUp(map);
        i = this->empty_case.size();
      }
    else if (pos_enemy.second > this->pos.second && empty_case[i].second > this->pos.second &&
            safe_case[pos.second + 1][pos.first] == true)
      {
        action_done = true;
        goDown(map);
        i = this->empty_case.size();
      }
  }
  if (action_done == false)
    {
      if (action == indie::AiAction::AI_DOWN && pos.second > 0 && map.at(0, pos.first, pos.second - 1).getType(0) == static_cast<indie::OBJECTS_ID>(5))
        dropPikesBomb();
      if (action == indie::AiAction::AI_UP && (pos.second + 1) < static_cast<int>(map.getHeight()) && map.at(0, pos.first, pos.second + 1).getType(0) == static_cast<indie::OBJECTS_ID>(5))
        dropPikesBomb();
      if (action == indie::AiAction::AI_LEFT && pos.first > 0 && map.at(0, pos.first - 1, pos.second).getType(0) == static_cast<indie::OBJECTS_ID>(5))
        dropPikesBomb();
      if (action == indie::AiAction::AI_RIGHT && (pos.first + 1) < static_cast<int>(map.getWidth()) && map.at(0, pos.first + 1, pos.second).getType(0) == static_cast<indie::OBJECTS_ID>(5))
        dropPikesBomb();
    }
}
