//
// Author: Marwane Khsime 
// Date: 2017-05-05 17:41:58 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-05 17:41:58
//

#ifndef GFX_HPP
# define GFX_HPP

#include <string>
#include <iostream>

#include "Interfaces/IGfx.hpp"
#include "Exception/exception.hpp"
#include "irr/irrlicht.h"

namespace indie
{

    class Gfx : public indie::IGfx {

        public:
            Gfx();
            virtual ~Gfx();

            virtual void    display();
            virtual void    clear();

            void    operator=(const Gfx& gfx) = delete;
            Gfx(const Gfx &gfx) = delete;

        private:
            irr::IrrlichtDevice *_device;

    };

}

# endif //  GFX_HPP
