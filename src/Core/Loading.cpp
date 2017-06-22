//
// Author: Marwane Khsime
// Date: 2017-06-12 20:34:32
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-06-12 20:34:32
//

#include "Core/Core.hpp"

void    indie::Core::loading() {

    try {

    // Sounds
    this->_gfx->loadSounds(this->_game->getSoundsToLoad());

    // Scenes
    this->_gfx->loadScenes(this->_game->getScenesToLoad());

    // Models
    this->_gfx->loadModels(this->_game->getModelsToLoad());

    // Sprites
    this->_gfx->loadSprites(this->_game->getSpritesToLoad());


    } catch (const std::exception &err) {

      throw indie::IndieError(_INDIE_CORE_LOADING_FAILED);

    }
}
