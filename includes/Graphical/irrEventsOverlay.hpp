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
            irrEventOverlay() {
                for (std::size_t i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
                    this->KeysDown[i] = false;
            };
            virtual ~irrEventOverlay() {};

            // Inherited from irrlicht
            virtual bool        OnEvent(const irr::SEvent& event);
            bool                getLastEvent(std::vector<Event> &e);

            irrEventOverlay(const irrEventOverlay &) = delete;
            irrEventOverlay &operator=(const irrEventOverlay &) = delete;

        private:

            bool                          KeysDown[irr::KEY_KEY_CODES_COUNT];
    };

}
#endif // !IRR_EVENT_OVERLAY_HPP
