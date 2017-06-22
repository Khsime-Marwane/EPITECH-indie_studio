//
// Author: Marwane Khsime
// Date: 2017-06-12 21:25:47
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-06-12 21:25:47
//

#include "Core/Core.hpp"

void        indie::Core::process() {

    // Clear the GFX
    this->_gfx->clear();

    // [ from GFX to GAME ]
    // Notify the game by sending gfx inputs
    this->notifyGame();
    this->_game->setObjectsAnimationState(this->_gfx->getObjectsAnimationState());

    // Run the Game once time
    Timer timer;


    while (timer.Elapsed().count() < 16);
    this->_game->process();

    // [ from GAME to GFX ]
    // Update the game map in the GFX
    this->_gfx->updateMap(this->_game->getCurrentMap());
    // Update the GUI in the GFX
    const std::vector<indie::Sound> &soundsToPlay = _game->getSoundsToPlay();

    std::for_each(soundsToPlay.begin(), soundsToPlay.end(), [this](const indie::Sound &sound) {

        this->_gfx->soundControl(sound);

    });

    this->_gfx->updateGUI(this->_game->getCurrentGUI());



    // Refresh the screen
    this->_gfx->display();

}
