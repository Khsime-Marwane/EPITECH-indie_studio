//
// Author: Marwane Khsime
// Date: 2017-06-03 19:40:20
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-06-03 19:40:20
//

#include "Graphical/Gfx.hpp"

bool        indie::Gfx::pollEvents(Event &e) {

    if (this->_eventsOverlay.getLastEvent(e)) {
        return true;
    }
    return false;
}
