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

    enum SoundId {
      SOUND_NONE = -1,
      SOUND_MENU,
      SOUND_GAME_FAULT_LINES,
      SOUND_GAME_INNONCENCE_MANGLED,
      SOUND_GAME_TANDAVA,
      SOUND_EXPLOSION_1,
      SOUND_EXPLOSION_2,
      SOUND_EXPLOSION_3,
      SOUND_SKELELETON_SPAWN
    };
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

        SoundId    id;     //< Id of the sound
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
        Sound(SoundId id_, SoundAction mode_ = UNIQUE, float volume_ = 50.0f)
            : id(id_), mode(mode_), volume(volume_) {}

    };

}

#endif // !SOUND_HPP
