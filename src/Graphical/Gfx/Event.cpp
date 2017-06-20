//
// Author: Marwane Khsime
// Date: 2017-06-03 19:40:20
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-06-03 19:40:20
//

#include "Graphical/Gfx.hpp"

bool        indie::Gfx::pollEvents(std::vector<Event> &events) {

    if (this->_eventsOverlay.getLastEvent(events)) {
        return true;
    }
    return false;
}
