//
// Author: Marwane Khsime 
// Date: 2017-06-12 21:43:12 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-12 21:43:12
//

#include "Core/Core.hpp"

void    indie::Core::notifyGame() const {

    std::vector<Event>  events_recorded;

    if (this->_gfx->pollEvents(events_recorded)) {
        this->_game->notifyEvent(std::move(events_recorded));
    }

}