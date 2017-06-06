//
// Author: Marwane Khsime 
// Date: 2017-06-04 05:06:47 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-04 05:06:47
//

#ifndef SOUND_MANAGER_HPP
# define SOUND_MANAGER_HPP

// UTILS
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
// OPENAL
#include <AL/al.h>
#include <AL/alc.h>
// SNDFILE
#include <sndfile.h>
// SOUND TYPES
#include "Interfaces/Sound.hpp"
#include "Exception/errors_messages.hpp"

namespace indie
{
    class   SoundManager {
        private:
            std::unordered_map<std::size_t, ALuint> _sounds;
            bool                                    _soundSupported;

        public:
            SoundManager();
            ~SoundManager();

            bool    doesSupportSound() const;
            void    soundControl(const Sound &sound);
            void    loadSounds(std::vector<std::pair<std::string, SoundType> > const &soundsToLoad);
    };
}

#endif  // SOUND_MANAGER_HPP