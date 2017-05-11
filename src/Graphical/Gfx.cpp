//
// Author: Marwane Khsime 
// Date: 2017-05-05 17:53:29 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-05 17:53:29
//

#include "Graphical/Gfx.hpp"

indie::Gfx::Gfx()

    // irr::createDevice (deviceType, windowSize, bits, fullscreen, stencilbuffer, vsync, receiver)


    try : _device(irr::createDevice (   irr::video::EDT_OPENGL,
                                        irr::core::dimension2d<irr::u32>(800,600),
                                        32,
                                        false,
                                        true,
                                        false,
                                        0))

    {
        std::cout << "Launching Irrlicht" << std::endl << std::endl << std::endl;
    }

    catch (const std::exception &err) {
        throw err;
}

indie::Gfx::~Gfx() {

}

void    indie::Gfx::display() {
    std::cout << "display" << std::endl;
}

void    indie::Gfx::clear() {
    std::cout << "clear" << std::endl;
}
