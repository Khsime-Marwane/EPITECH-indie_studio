//
// Author: Sebastien Jacobin 
// Date: 2017-06-01 21:05:35 
//
// Last Modified by:   Sebastien Jacobin 
// Last Modified time: 2017-06-01 21:05:35
//

#include "Graphical/Gfx.hpp"

bool    indie::irrEventOverlay::OnEvent(const irr::SEvent &irr_event) {

    switch (irr_event.EventType)
    {
        case irr::EET_KEY_INPUT_EVENT:
            return add_key_event(irr_event);
        
        case irr::EET_MOUSE_INPUT_EVENT:
            return add_mouse_event(irr_event);

        case irr::EET_JOYSTICK_INPUT_EVENT:
            return add_joystick_event(irr_event);

        case irr::EET_GUI_EVENT:
            break ;

        case irr::EET_LOG_TEXT_EVENT:
            break ;

        case irr::EET_USER_EVENT:
            break ;
        
        case irr::EGUIET_FORCE_32_BIT:
            break ;
        
        default:
            break ;
    }

    return false;
}

bool     indie::irrEventOverlay::getLastEvent(Event &e) {

    if (!this->_lastEvents.empty()) {

        e.type = this->_lastEvents.front().type;
        e.action = this->_lastEvents.front().action;

        switch (e.type)
        {
            case ET_KEYBOARD:
                e.kb_key = this->_lastEvents.front().kb_key;
                break ;

            case ET_MOUSE:
                e.m_key = this->_lastEvents.front().m_key;
                break ;

            case ET_JOYSTICK:
                e.c_key = this->_lastEvents.front().c_key;
                break ;

            case ET_NONE:
                break ;

            case ET_QUIT:
                break ;

            case ET_BUTTON:
                break ;

            case NB_EVENT_TYPE:
                break ;

            default:
                break;
        }

        e.pos_rel = this->_lastEvents.front().pos_rel;
        e.pos_abs = this->_lastEvents.front().pos_abs;

        this->_lastEvents.pop();

        return true;

    }

    return false;
}

bool    indie::irrEventOverlay::add_key_event(const irr::SEvent &event) {

    if (event.KeyInput.PressedDown && _irrKeyboardKeys.count(event.KeyInput.Key)) {

        Event   newEvent;

        newEvent.type = ET_KEYBOARD;
        newEvent.action = AT_PRESSED;

        newEvent.kb_key = static_cast< KeyboardKey >(indie::_irrKeyboardKeys.at(event.KeyInput.Key));

        newEvent.pos_rel.x = this->_lastEvents.empty() ? 0.0 : this->_lastEvents.back().pos_rel.x;
        newEvent.pos_rel.y = this->_lastEvents.empty() ? 0.0 : this->_lastEvents.back().pos_rel.y;

        newEvent.pos_abs.x = event.MouseInput.X;
        newEvent.pos_abs.y = event.MouseInput.Y;

        this->_lastEvents.push(newEvent);

        return true;
    }

    return false;
}

bool    indie::irrEventOverlay::add_mouse_event(const irr::SEvent &event) {

    if (event.MouseInput.Event == irr::EMIE_LMOUSE_PRESSED_DOWN ||
        event.MouseInput.Event == irr::EMIE_RMOUSE_PRESSED_DOWN) {

        Event   newEvent;

        newEvent.type = ET_MOUSE;
        newEvent.action = AT_PRESSED;

        newEvent.m_key = static_cast< MouseKey >(indie::_irrMouseKeys.at(event.MouseInput.Event));

        newEvent.pos_rel.x = this->_lastEvents.empty() ? 0.0 : this->_lastEvents.back().pos_rel.x;
        newEvent.pos_rel.y = this->_lastEvents.empty() ? 0.0 : this->_lastEvents.back().pos_rel.y;

        newEvent.pos_abs.x = event.MouseInput.X;
        newEvent.pos_abs.y = event.MouseInput.Y;

        this->_lastEvents.push(newEvent);

        return true;
    }

    return false;
}

bool    indie::irrEventOverlay::add_joystick_event(const irr::SEvent &event) {

    Event   newEvent;

    newEvent.type = ET_JOYSTICK;
    newEvent.action = AT_PRESSED;
    newEvent.c_key = C_NONE;

    this->_lastEvents.push(newEvent);

    newEvent.pos_rel.x = this->_lastEvents.empty() ? 0.0 : this->_lastEvents.back().pos_rel.x;
    newEvent.pos_rel.y = this->_lastEvents.empty() ? 0.0 : this->_lastEvents.back().pos_rel.y;

    newEvent.pos_abs.x = event.MouseInput.X;
    newEvent.pos_abs.y = event.MouseInput.Y;

    return true;
}