#ifndef SETTINGS_HPP
# define SETTINGS_HPP

# include "Interfaces/Event.hpp"
# include "Interfaces/Sound.hpp"
# include "Common/Timer.hpp"

namespace indie {

    class Player;

    typedef enum        e_PlayerType {
      PLAYER_UNKNOWN = -1,
      PLAYER_HUMAN,
      PLAYER_AI
    }                     PlayerType;

    typedef enum          e_IA_LEVEL {
      IA_UNKNOWN = -1,
      IA_MEDIUM,
      IA_HARD
    }                     IA_LEVEL;

    typedef enum          e_PLAY_MOD {
      PLAY_MODE_UNKNOWN = -1,
      PLAY_MODE_LOCAL,
      PLAY_MODE_ONLINE_HOST,
      PLAY_MODE_ONLINE_CLIENT
    }                     PlayMode;

    struct              Settings {
      const std::vector<std::unique_ptr<indie::Player> > &players;
      float                     volume;
      IA_LEVEL                  difficulty;
      PlayMode                  mode;
      size_t                    nPlayers;
      size_t                    nAIs;
      Sound                     music;
      Timer                     timer;
      Settings(const std::vector<std::unique_ptr<indie::Player> > &players_,
                float volume_ = 50.0f,
                IA_LEVEL difficulty_ = IA_LEVEL::IA_MEDIUM,
                PlayMode mode_ = PlayMode::PLAY_MODE_LOCAL,
                size_t nPlayers_ = 0, size_t nAIs_ = 0,
                Sound music_ = Sound(indie::SoundId::SOUND_NONE)) :
        players(players_), volume(volume_), difficulty(difficulty_), mode(mode_),
        nPlayers(nPlayers_), nAIs(nAIs_), music(music_), timer(){}
    };
}

# include "Game/Player.hpp"

#endif // SETTINGS_HPP
