//
// Author: Marwane Khsime 
// Date: 2017-05-22 17:49:33 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-22 17:49:33
//
#ifndef IRR_EVENT_OVERLAY_HPP
#define IRR_EVENT_OVERLAY_HPP

#include <vector>
#include <map>
#include <queue>
#include "irr/irrlicht.h"
#include "Graphical/IrrlichtEventsCorrespondence.hpp"
#include "Interfaces/Event.hpp"

namespace indie
{

    class irrEventOverlay : public irr::IEventReceiver
    {
        public:
            irrEventOverlay() : _lastEvents() {};
            virtual ~irrEventOverlay() {};

            // Inherited from irrlicht
            virtual bool        OnEvent(const irr::SEvent& event);
            bool                getLastEvent(Event &e);

            irrEventOverlay(const irrEventOverlay &) = delete;
            irrEventOverlay &operator=(const irrEventOverlay &) = delete;

        private:

            bool                add_key_event(const irr::SEvent &event);
            bool                add_mouse_event(const irr::SEvent &event);
            bool                add_joystick_event(const irr::SEvent &event);

            std::queue<Event>   _lastEvents;
    };

}
#endif // !IRR_EVENT_OVERLAY_HPP
