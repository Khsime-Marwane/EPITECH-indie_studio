#ifndef SETTINGS_HPP
# define SETTINGS_HPP

# include "Interfaces/Event.hpp"

namespace indie {

    typedef enum          e_BonusType {
      BONUS_UNKNOWN = -1,
      BONUS_SQUAREBOMB = 7,
      BONUS_TENTACLEBOMB = 9
    }                     BonusType;

    typedef struct  s_Bonus {
      BonusType     type;
      size_t        duration;
    }               Bonus;

    typedef enum        e_PlayerType {
      PLAYER_UNKNOWN = -1,
      PLAYER_HUMAN,
      PLAYER_AI
    }                     PlayerType;

    typedef struct        s_Player {
      KeyboardKey         move_left;
      KeyboardKey         move_right;
      KeyboardKey         move_up;
      KeyboardKey         move_down;
      KeyboardKey         bomb;
      std::vector<Bonus>  bonus;
      size_t              id;
      PlayerType          type;
    }                     Player;

    typedef enum          e_IA_LEVEL {
      IA_UNKNOWN = -1,
      IA_EASY,
      IA_MEDIUM,
      IA_HARD
    }                     IA_LEVEL;

    typedef enum          e_PLAY_MOD {
      PLAY_MOD_UNKNOWN = -1,
      PLAY_MOD_LOCAL,
      PLAY_MOD_ONLINE_HOST,
      PLAY_MOD_ONLINE_CLIENT
    }                     PlayMod;

    struct              Settings {
      float                     volume;
      IA_LEVEL                  difficulty;
      std::vector<Player>       players;
      int                       nplayers;
      PlayMod                   mod;
    };
}


#endif // SETTINGS_HPP
