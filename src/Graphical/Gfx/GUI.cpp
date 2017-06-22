//
// Author: Marwane Khsime
// Date: 2017-05-22 19:17:21
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-05-22 19:17:21
//

#include "Graphical/Gfx.hpp"
#include "Common/Timer.hpp"

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

    if (txt) {
        irr::core::dimension2d<irr::u32> area = this->_fonts[DEFAULT_FONT]->getDimension(txt);
        irr::core::dimension2d<irr::s32> cmp_pos(this->get_real_posX(x), this->get_real_posY(y));
        irr::core::rect<irr::s32> position = {
            cmp_pos.Width,
            cmp_pos.Height,
            cmp_pos.Width + static_cast<irr::s32>(area.Width),
            cmp_pos.Height + static_cast<irr::s32>(area.Height)
        };

        // Draw the background
        this->_driver->draw2DRectangle(bgColor, position);
        // Draw the text
        this->_fonts[DEFAULT_FONT]->draw(txt, position, txtColor);
    }
}

void    indie::Gfx::draw_component_text(const IComponent &cmp) {

    const wchar_t *txt = helper::Helper::get().getWC(cmp.getText().c_str());

    if (txt) {
        irr::core::dimension2d<irr::u32> area = this->_fonts[DEFAULT_FONT]->getDimension(txt);
        irr::core::dimension2d<irr::s32> cmp_pos(this->get_real_posX(cmp.getX()), this->get_real_posY(cmp.getY()));
        irr::core::rect<irr::s32> position = {
            cmp_pos.Width,
            cmp_pos.Height,
            cmp_pos.Width + static_cast<irr::s32>(area.Width),
            cmp_pos.Height + static_cast<irr::s32>(area.Height)
        };

        // Draw the background
        this->_driver->draw2DRectangle(this->getSColor(cmp.getBackgroundColor()), position);
        // Draw the text
        this->_fonts[DEFAULT_FONT]->draw(txt, position, this->getSColor(cmp.getTextColor()));
    }
}

void    indie::Gfx::draw_component_sprite(const IComponent &cmp) {

    irr::core::rect<irr::s32>   position(this->get_real_posX(cmp.getX()),
                                         this->get_real_posY(cmp.getY()),
                                         this->get_real_posX(cmp.getWidth()),
                                         this->get_real_posY(cmp.getHeight())
                                         );
    irr::core::rect<irr::s32>   sprite_area(0,
                                            0,
                                            this->_sprites[cmp.getBackgroundId()][cmp.getBackgroundPos()]->getSize().Width,
                                            this->_sprites[cmp.getBackgroundId()][cmp.getBackgroundPos()]->getSize().Height
                                            );

    this->_driver->draw2DImage(this->_sprites[cmp.getBackgroundId()][cmp.getBackgroundPos()],
                               position,
                               sprite_area,
                               0,
                               NULL,
                               true);
}

void    indie::Gfx::play_animation(const std::vector<std::string> &frames) {

    indie::Timer   timer;

    for (std::size_t i = 0; i < frames.size(); ++i) {

        irr::video::ITexture *image;

        image = this->_driver->getTexture(frames.at(i).c_str());

        if (image) {

            irr::core::rect<irr::s32>   position(0,
                                                 0,
                                                 static_cast<irr::s32>(this->get_real_posX(1.0)),
                                                 static_cast<irr::s32>(this->get_real_posY(1.0))
                                                );
            irr::core::rect<irr::s32>   sprite_area(0,
                                                    0,
                                                    image->getSize().Width,
                                                    image->getSize().Height
                                                    );
            this->_driver->draw2DImage( image,
                                        position,
                                        sprite_area,
                                        0,
                                        NULL,
                                        true);
            this->_driver->removeTexture(image);

        } // End Drawing Frame

        while (timer.Elapsed() < static_cast<std::chrono::milliseconds>(60));
        timer.Reset();

        this->display();

    }

}

void    indie::Gfx::updateGUI(const IGUI &gui) {

    const std::vector<std::string>    animation = gui.getTransitPaths();

    if (!animation.empty()) {
        this->play_animation(animation);
    } else {

        for (std::size_t i = 0; i < gui.size(); i++) {
            if (gui.at(i).hasSprite())
                this->draw_component_sprite(gui.at(i));
            else
                this->draw_component_text(gui.at(i));
        }

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
