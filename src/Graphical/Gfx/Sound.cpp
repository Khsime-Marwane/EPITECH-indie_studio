//
// Author: Marwane Khsime 
// Date: 2017-05-22 18:44:22 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-22 18:44:22
//

#include "Graphical/Gfx.hpp"

bool    indie::Gfx::doesSupportSound() const {
    return SOUND_SUPPORTED;
}

void    indie::Gfx::loadSounds(_UNUSED std::vector<std::pair<std::string, SoundType > > const &sounds) {
    return ;
}

void    indie::Gfx::soundControl(_UNUSED const Sound &sound) {
    return ;
}