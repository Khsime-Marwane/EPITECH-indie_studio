//
// Author: Marwane Khsime 
// Date: 2017-05-29 02:09:41 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-29 02:09:41
//

#include "Graphical/Gfx.hpp"

irr::video::SColor  indie::Gfx::getSColor(const Color &color) const {
    irr::video::SColor  scolor(color.a, color.r, color.g, color.b);
    return scolor;
}

double                  indie::Gfx::get_real_posX(double pos) const noexcept {
    return pos * this->_driver->getScreenSize().Width;
}

double                  indie::Gfx::get_real_posY(double pos) const noexcept {
    return pos * this->_driver->getScreenSize().Height;
}
