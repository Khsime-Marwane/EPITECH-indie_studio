//
// Author: Marwane Khsime 
// Date: 2017-06-12 21:43:12 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-12 21:43:12
//

#include "Core/Core.hpp"

void    indie::Core::notifyGame() const {

    Event               event;
    std::vector<Event>  events_recorded;

    while (this->_gfx->pollEvents(event)) {
        events_recorded.push_back(event);
    }

    this->_game->notifyEvent(std::move(events_recorded));

}