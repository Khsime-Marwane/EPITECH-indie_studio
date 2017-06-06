//
// Author: Marwane Khsime 
// Date: 2017-05-22 18:44:22 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-22 18:44:22
//

#include "Graphical/Gfx.hpp"

bool    indie::Gfx::doesSupportSound() const {
    return this->_soundManager.doesSupportSound();
}

void    indie::Gfx::loadSounds(std::vector<std::pair<std::string, SoundType > > const &sounds) {
    this->_soundManager.loadSounds(sounds);
}

void    indie::Gfx::soundControl(const Sound &sound) {
    this->_soundManager.soundControl(sound);
}