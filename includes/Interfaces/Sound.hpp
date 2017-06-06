//
// Author: Marwane Khsime 
// Date: 2017-05-05 04:36:43 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-05 04:36:43
//

#ifndef SOUND_HPP
#define SOUND_HPP

namespace indie
{

    ///
    /// \enum SoundMode
    /// \brief Used to control the way sound is played
    ///
    enum SoundAction
    {
        //! Sound played once
        UNIQUE,

        //! Sound played indefinitly (common for musics)
        REPEAT,

        //! Update the volume
    	VOLUME,

        //! Play the sound specified
	    PLAY,

        //! Pause the sound specified
        PAUSE,

        //! Resume the sound specified
        RESUME,

        //! Stop the sound specified
        STOP
    };

    ///
    /// \enum SoundType
    /// \brief Used to differenciate the sound type
    ///
    /// It might be very usefull with some sound libraries which need to know
    /// this type of differences
    ///
    enum SoundType
    {
        //! The soud is a music (long)
        MUSIC,

        //! The sound is a normal sound (short)
        SOUND
    };

    ///
    /// \struct SoundMode
    /// \brief Contain informations on the sound to play and how to play it
    ///
    struct Sound
    {

        unsigned int    id;     //< Id of the sound
        SoundAction     mode;   //< Mode of the sound (control)
        float           volume; //< Volume

        ///
        /// \fn Sound(unsigned int id, SoundMode mode = UNIQUE, SoundType type = SOUND, float volume = 50.0f);
        /// \brief Constructor of a sound
        /// \param id Id of the sound to be controlled
        /// \param mode Mode of Sound
        /// \param type Type of Sound
        /// \param volume Volume of Sound
        ///
        Sound(unsigned int id_, SoundAction mode_ = UNIQUE, float volume_ = 50.0f)
            :   id(id_), mode(mode_), volume(volume_) {}

    };

}

#endif // !SOUND_HPP
