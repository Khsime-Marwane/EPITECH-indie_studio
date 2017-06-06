//
// Author: Marwane Khsime 
// Date: 2017-05-29 02:10:07 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-29 02:10:07
//

#include "Graphical/Gfx.hpp"

void    indie::Gfx::loadFonts(const std::vector<std::string> &fonts_to_load) {

    this->_fonts.clear();

    if (fonts_to_load.empty()) {
            irr::gui::IGUIFont  *fnt;

            if (!(fnt = this->_guienv->getFont("Fonts/fontlucida.png"))) {
                throw IndieError(_INDIE_GFX_DEFAULT_FONT_FAILED);
            }
            this->_fonts.push_back(fnt);
    }

    else {

        for ( auto &elem : fonts_to_load ) {

            irr::gui::IGUIFont  *fnt;

            if (!(fnt = this->_guienv->getFont(elem.c_str())))
                throw IndieError(_INDIE_GFX_FONT_FAILED);
            else
                this->_fonts.push_back(fnt);

        }

    }
}
