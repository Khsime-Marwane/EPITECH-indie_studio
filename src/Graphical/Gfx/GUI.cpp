//
// Author: Marwane Khsime 
// Date: 2017-05-22 19:17:21 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-22 19:17:21
//

#include "Graphical/Gfx.hpp"

// Desable warnings in this file
#if defined( __clang__ )
    #pragma clang diagnostic push
        #pragma clang diagnostic ignored "-Wnarrowing"
        #pragma clang diagnostic ignored "-Wfloat-conversion"
        #pragma clang diagnostic ignored "-Wsign-conversion"
#elif defined( __GNUC__ ) || defined( __GNUG__ )
    #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wnarrowing"
        #pragma GCC diagnostic ignored "-Wfloat-conversion"
#elif defined( _MSC_VER )
    #pragma warning( push )
        #pragma warning( disable: 4996 )
#endif

void    indie::Gfx::draw_text(const std::string &txtAsString,
                              double x, double y,
                              const irr::video::SColor &txtColor,
                              const irr::video::SColor &bgColor) {

    const wchar_t *txt = helper::Helper::get().getWC(txtAsString.c_str());

    irr::core::dimension2d<irr::u32> area = this->_fonts[DEFAULT_FONT]->getDimension(txt);
    irr::core::dimension2d<irr::u32> cmp_pos(this->get_real_posX(x), this->get_real_posY(y));
    irr::core::rect<irr::s32> position = {
        cmp_pos.Width,
        cmp_pos.Height,
        cmp_pos.Width + area.Width,
        cmp_pos.Height + area.Height
    };

    // Draw the background
    this->_driver->draw2DRectangle(bgColor, position);
    // Draw the text
    this->_fonts[DEFAULT_FONT]->draw(txt, position, txtColor);
}

void    indie::Gfx::draw_component_text(const IComponent &cmp) {

    const wchar_t *txt = helper::Helper::get().getWC(cmp.getText().c_str());

    irr::core::dimension2d<irr::u32> area = this->_fonts[DEFAULT_FONT]->getDimension(txt);
    irr::core::dimension2d<irr::u32> cmp_pos(this->get_real_posX(cmp.getX()), this->get_real_posY(cmp.getY()));
    irr::core::rect<irr::s32> position = {
        cmp_pos.Width,
        cmp_pos.Height,
        cmp_pos.Width + area.Width,
        cmp_pos.Height + area.Height
    };

    // Draw the background
    this->_driver->draw2DRectangle(this->getSColor(cmp.getBackgroundColor()), position);
    // Draw the text
    this->_fonts[DEFAULT_FONT]->draw(txt, position, this->getSColor(cmp.getTextColor()));
}

void    indie::Gfx::draw_component_sprite(const IComponent &cmp) {

    irr::core::position2d<irr::s32> position(this->get_real_posX(cmp.getX()),
                                             this->get_real_posY(cmp.getY()));
    irr::core::rect<irr::s32>   sprite_area(0,0,
                                            this->get_real_posX(cmp.getWidth()),
                                            this->get_real_posY(cmp.getHeight()));
    irr::video::SColor  color = this->getSColor(cmp.getBackgroundColor());

    this->_driver->draw2DImage(this->_sprites[cmp.getBackgroundId()][cmp.getBackgroundPos()],
                               position,
                               sprite_area,
                               0,
                               color,
                               true);
}

void    indie::Gfx::updateGUI(IGUI &gui) {

    for (std::size_t i = 0, count = gui.size(); i < count; ++i) {

        if (gui.at(i).hasSprite())
            this->draw_component_sprite(gui.at(i));
        else
            this->draw_component_text(gui.at(i));

    }

}

// Disable warning in this file
#if defined(__clang__)
    #pragma clang diagnostic pop
#elif defined(__GNUC__) || defined(__GNUG__)
    #pragma GCC diagnostic pop
#elif defined( _MSC_VER )
    #pragma warning( pop )
#endif