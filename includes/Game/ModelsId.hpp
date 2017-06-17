//
// Author: Marwane Khsime
// Date: 2017-06-08 01:06:38
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-06-08 01:06:38
//

#ifndef MODELS_ID_HPP
# define MODELS_ID_HPP

namespace indie
{

    enum class MODELS_ID : int {

        UNKNOWN = -1,
        SKELETON_MODEL = 0,
        BOX_MODEL = 1,
        EXPLOSION_MODEL = 2,
        TRAP_MODEL = 3

    };

    enum class OBJECTS_ID : int {

        UNKNOWN = -1,
        EMPTY = 0,
        PLAYER_ONE = 1,
        PLAYER_TWO = 2,
        PLAYER_THREE = 3,
        PLAYER_FOURTH = 4,
        BOX = 5,
        WALL = 6,
        SQUAREBOMB = 7,
        PIKESBOMB = 8,
        TENTACLEBOMB = 9
    };

    typedef struct s_AnimationState {
      size_t id;
      bool over;
    }              AnimationState;

  # define SQUAREBOMB_FRAMECD 5
  # define PIKESBOMB_FRAMECD 5
  # define TENTACLESBOMB_FRAMECD 5
}

#endif // MODELS_ID_HPP
