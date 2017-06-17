//
// Author: Marwane Khsime 
// Date: 2017-05-27 18:13:29 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-27 18:13:29
//

namespace indie
{
    ///
    ///\brief Errors Messages
    ///

    // ------- GLOBAL
    # define _INDIE_LAUNCHING_FAILED                "Indie : Launching failed."
    // ------- CORE
    # define _INDIE_CORE_INIT_FAILED                "Indie Core : Construction Failed."
    # define _INDIE_CORE_LOADING_FAILED             "Indie Core : Failed to get resources to load from the game to library."
    // ------- GFX
    # define _INDIE_GFX_FONT_FAILED                 "Indie Gfx : Failed to load font. Default font will be loaded instead."
    # define _INDIE_GFX_DEFAULT_FONT_FAILED         "Indie Gfx : Failed to load default font."
    # define _INDIE_GFX_MESH_FAILED                 "Indie Gfx : Failed to load mesh."
    # define _INDIE_GFX_TEXTURE_FAILED              "Indie Gfx : Failed to load / apply texture."
    # define _INDIE_GFX_SPRITE_FAILED               "Indie Gfx : Failed to load sprite : "
    # define _INDIE_GFX_DOME_FAILED                 "Indie Gfx : Failed to load dome."
    # define _INDIE_GFX_GUI_FAILED                  "Indie Gfx : Failed to load gui : "
    # define _INDIE_GFX_SCENE_IS_INVALID            "Indie Gfx : Invalid scene selected."
    # define _INDIE_GFX_DEVICE_IS_OFF               "Indie Gfx : Can not display anything because the driver is not running."
    # define _INDIE_GFX_INVALID_CAMERA_POV          "Indie Gfx : Invalid Point of view selected for the camera. The default view will be set instead."
    // ------- GAME
    # define _INDIE_GAME_INVALID_MAP_INDEX          "Indie Game : Invalid map selected in factory."
    # define _INDIE_GAME_INVALID_OBJECT_ID          "Indie Game : Invalid object id selected for addition / deletion."
    // ------- SOUND MANAGER
    # define _INDIE_SOUND_NOT_SUPPORTED             "Indie Sound : Sound mode not supported."
    # define _INDIE_SOUND_MODE_NOT_FOUND            "Indie Sound : Sound mode not found."
    # define _INDIE_SOUND_NOT_FOUND                 "Indie Sound : Sound not found."
    # define _INDIE_SOUND_DEVICE_NOT_FOUND          "Indie Sound : No sound device found."
    # define _INDIE_SOUND_CONTEXT_FAILED            "Indie Sound : Failed to create context for sound."
    # define _INDIE_SOUND_ACTIVE_CONTEXT_FAILED     "Indie Sound : Failed to active context for sound."
}