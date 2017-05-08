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
        //! Unknown game state
        NONE = -1,

        //! Loading (need to load sounds / sprites)
	    LOADING,

        //! Splash screen
        SPLASH_SCREEN,

        //! In game
        INGAME,

        //! In menu
        MENU,

        //! Quitting
        QUIT,

        //! Number of game states
        NB_GAME_STATE
    };

}

#endif // IGAME_STATE_H