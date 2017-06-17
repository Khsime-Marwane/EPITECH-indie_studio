//
// Author: Maud Marel
// Date: 2017-06-12 18:41:39
//

#ifndef KEYMAP_HPP_
# define KEYMAP_HPP_

#include <map>
#include <functional>

#include "Interfaces/GameState.hpp"
#include "Interfaces/Event.hpp"

namespace indie
{
    class keyMap
    {
        std::map<indie::GameState, std::function<void(Event)> > act;

    public:
        keyMap();
        virtual ~keyMap();

        void    act_menu(indie::Event);
        void    act_settings(indie::Event);
        void    act_score(indie::Event);
        void    act_room(indie::Event);
        void    manage_keyMap(indie::GameState &, indie::Event event);
    };
}

#endif /* !KEYMAP_HPP_ */
