//
// Author: Marwane Khsime 
// Date: 2017-04-08 05:10:30 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-04-08 05:10:30
//

#ifndef IRRLICHT_EVENTS_CORRESPONDENCE_HPP
# define IRRLICHT_EVENTS_CORRESPONDENCE_HPP

#include <unordered_map>

#include "Extern/irr/Keycodes.h"
#include "Interfaces/Event.hpp"

// Desable warnings in this file
#if defined( __clang__ )
    #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

namespace indie
{

    const std::unordered_map<int, indie::KeyboardKey>   _irrKeyboardKeys = {

        { -1, indie::KB_NONE },
        { irr::EKEY_CODE::KEY_KEY_A, indie::KB_A },
        { irr::EKEY_CODE::KEY_KEY_B, indie::KB_B },
        { irr::EKEY_CODE::KEY_KEY_C, indie::KB_C },
        { irr::EKEY_CODE::KEY_KEY_D, indie::KB_D },
        { irr::EKEY_CODE::KEY_KEY_E, indie::KB_E },
        { irr::EKEY_CODE::KEY_KEY_F, indie::KB_F },
        { irr::EKEY_CODE::KEY_KEY_G, indie::KB_G },
        { irr::EKEY_CODE::KEY_KEY_H, indie::KB_H },
        { irr::EKEY_CODE::KEY_KEY_I, indie::KB_I },
        { irr::EKEY_CODE::KEY_KEY_J, indie::KB_J },
        { irr::EKEY_CODE::KEY_KEY_K, indie::KB_K },
        { irr::EKEY_CODE::KEY_KEY_L, indie::KB_L },
        { irr::EKEY_CODE::KEY_KEY_M, indie::KB_M },
        { irr::EKEY_CODE::KEY_KEY_N, indie::KB_N },
        { irr::EKEY_CODE::KEY_KEY_O, indie::KB_O },
        { irr::EKEY_CODE::KEY_KEY_P, indie::KB_P },
        { irr::EKEY_CODE::KEY_KEY_Q, indie::KB_Q },
        { irr::EKEY_CODE::KEY_KEY_R, indie::KB_R },
        { irr::EKEY_CODE::KEY_KEY_S, indie::KB_S },
        { irr::EKEY_CODE::KEY_KEY_T, indie::KB_T },
        { irr::EKEY_CODE::KEY_KEY_U, indie::KB_U },
        { irr::EKEY_CODE::KEY_KEY_V, indie::KB_V },
        { irr::EKEY_CODE::KEY_KEY_W, indie::KB_W },
        { irr::EKEY_CODE::KEY_KEY_X, indie::KB_X },
        { irr::EKEY_CODE::KEY_KEY_Y, indie::KB_Y },
        { irr::EKEY_CODE::KEY_KEY_Z, indie::KB_Z },
        { irr::EKEY_CODE::KEY_KEY_0, indie::KB_0 },
        { irr::EKEY_CODE::KEY_KEY_1, indie::KB_1 },
        { irr::EKEY_CODE::KEY_KEY_2, indie::KB_2 },
        { irr::EKEY_CODE::KEY_KEY_3, indie::KB_3 },
        { irr::EKEY_CODE::KEY_KEY_4, indie::KB_4 },
        { irr::EKEY_CODE::KEY_KEY_5, indie::KB_5 },
        { irr::EKEY_CODE::KEY_KEY_6, indie::KB_6 },
        { irr::EKEY_CODE::KEY_KEY_7, indie::KB_7 },
        { irr::EKEY_CODE::KEY_KEY_8, indie::KB_8 },
        { irr::EKEY_CODE::KEY_KEY_9, indie::KB_9 },
        { irr::EKEY_CODE::KEY_LEFT, indie::KB_ARROW_LEFT },
        { irr::EKEY_CODE::KEY_RIGHT, indie::KB_ARROW_RIGHT },
        { irr::EKEY_CODE::KEY_UP, indie::KB_ARROW_UP },
        { irr::EKEY_CODE::KEY_DOWN, indie::KB_ARROW_DOWN },
        { irr::EKEY_CODE::KEY_SPACE, indie::KB_SPACE },
        { irr::EKEY_CODE::KEY_RETURN, indie::KB_ENTER },
        { irr::EKEY_CODE::KEY_BACK, indie::KB_BACKSPACE },
        { irr::EKEY_CODE::KEY_LCONTROL, indie::KB_LCTRL },
        { irr::EKEY_CODE::KEY_RCONTROL, indie::KB_RCTRL },
        { irr::EKEY_CODE::KEY_LSHIFT, indie::KB_LSHIFT },
        { irr::EKEY_CODE::KEY_RSHIFT, indie::KB_RSHIFT },
        { irr::EKEY_CODE::KEY_TAB, indie::KB_TAB },
        { irr::EKEY_CODE::KEY_ESCAPE, indie::KB_ESCAPE },
        { irr::EKEY_CODE::KEY_PRIOR, indie::KB_PAGEUP },
        { irr::EKEY_CODE::KEY_NEXT, indie::KB_PAGEDOWN },
        { irr::EKEY_CODE::KEY_HOME, indie::KB_HOME },
        { irr::EKEY_CODE::KEY_END, indie::KB_END },
        { irr::EKEY_CODE::KEY_F1, indie::KB_FN1 },
        { irr::EKEY_CODE::KEY_F2, indie::KB_FN2 },
        { irr::EKEY_CODE::KEY_F3, indie::KB_FN3 },
        { irr::EKEY_CODE::KEY_F4, indie::KB_FN4 },
        { irr::EKEY_CODE::KEY_F5, indie::KB_FN5 },
        { irr::EKEY_CODE::KEY_F6, indie::KB_FN6 },
        { irr::EKEY_CODE::KEY_F7, indie::KB_FN7 },
        { irr::EKEY_CODE::KEY_F8, indie::KB_FN8 },
        { irr::EKEY_CODE::KEY_F9, indie::KB_FN9 },
        { irr::EKEY_CODE::KEY_F10, indie::KB_FN10 },
        { irr::EKEY_CODE::KEY_F11, indie::KB_FN11 },
        { irr::EKEY_CODE::KEY_F12, indie::KB_FN12 },
        { irr::EKEY_CODE::KEY_PERIOD, indie::KB_DOT },  // '.'
        { irr::EKEY_CODE::KEY_SUBTRACT, indie::KB_MINUS },
        { irr::EKEY_CODE::KEY_ADD, indie::KB_PLUS },
        { irr::EKEY_CODE::KEY_DELETE, indie::KB_DELETE },
        { irr::EKEY_CODE::KEY_MULTIPLY, indie::KB_ASTERISK } // '*'

        // '?' Not supported
        // ':' Not supported
        // '"' Not supported
        // '{' and '}' Not supported
        // '(' and ')' Not supported
        // '|' Not supported
        // '!' Not supported
        // '@' Not supported
        // '#' Not supported
        // '$' Not supported
        // '*' Not supported
        // '%' Not supported
        // '^' Not supported
        // '&' Not supported
        // '_' Not supported
        //

    };

    const std::unordered_map<int, int>   _irrMouseKeys = {

        { irr::EMIE_LMOUSE_PRESSED_DOWN, indie::MouseKey::M_LEFT_CLICK },
        { irr::EMIE_RMOUSE_PRESSED_DOWN, indie::MouseKey::M_RIGHT_CLICK }
        // Scroll is not supported

    };

    const std::unordered_map<int, int>   _irrControllerKey = {

        { -1, C_NONE }

    };

}

// Disable exit warning
#if defined(__clang__)
    #pragma clang diagnostic pop
#endif

#endif // IRRLICHT_EVENTS_CORRESPONDENCE_HPP
