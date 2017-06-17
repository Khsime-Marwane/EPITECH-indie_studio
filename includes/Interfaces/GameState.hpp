//
// Author: Marwane Khsime
// Date: 2017-05-05 05:08:14
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-05-05 05:08:14
//

#ifndef IGAME_STATE_H
# define IGAME_STATE_H

namespace indie
{
    ///
    /// \enum GameState
    /// \brief Describes current game state
    ///
    enum GameState
    {
        NONE = -1,
        SPLASH_SCREEN,
        MAIN_MENU,
        INGAME,
        SETTINGS,
        HELP,
        ROOM,
        SCOREBOARD,
        QUIT
    };

}

#endif // IGAME_STATE_H
