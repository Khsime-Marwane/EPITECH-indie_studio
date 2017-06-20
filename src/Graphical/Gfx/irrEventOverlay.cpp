//
// Author: Sebastien Jacobin 
// Date: 2017-06-01 21:05:35 
//
// Last Modified by:   Sebastien Jacobin 
// Last Modified time: 2017-06-01 21:05:35
//

#include "Graphical/Gfx.hpp"

bool    indie::irrEventOverlay::OnEvent(const irr::SEvent &irr_event) {

    if (irr_event.EventType == irr::EET_KEY_INPUT_EVENT)
    {
        this->KeysDown[irr_event.KeyInput.Key] = irr_event.KeyInput.PressedDown;
    }
    return false;
}

bool        indie::irrEventOverlay::getLastEvent(std::vector<Event> &events) {

    bool    hasEvent = false;

    for (int i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i) {

        if (this->KeysDown[i] && _irrKeyboardKeys.count(i)) {

            indie::Event    e;

            hasEvent = true;

            e.type = ET_KEYBOARD;
            e.action = AT_PRESSED;

            e.kb_key = indie::_irrKeyboardKeys.at(i);

            e.pos_rel.x = 0.0;
            e.pos_rel.y = 0.0;
            e.pos_abs.x = 0.0;
            e.pos_abs.y = 0.0;

            events.push_back(e);

        }

    }

    return hasEvent;
}