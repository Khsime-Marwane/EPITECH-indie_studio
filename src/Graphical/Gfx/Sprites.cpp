//
// Author: Marwane Khsime 
// Date: 2017-05-22 19:17:21 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-22 19:17:21
//

#include "Graphical/Gfx.hpp"

void    indie::Gfx::loadSprites(std::vector<std::unique_ptr<ISprite> > &&sprt_to_load) {

    for (std::size_t i = 0; i < sprt_to_load.size(); ++i) {

        for (std::size_t x = 0, count = sprt_to_load.at(i)->SpritesCount(); x < count; ++x) {

            irr::video::ITexture    *img = this->_driver->getTexture(sprt_to_load.at(i)->getGraphicPath(x).c_str());

            if (img) {
                this->_sprites[i].push_back(img);
            } else {
                // Throw ?
                std::cerr << _INDIE_GFX_SPRITE_FAILED << sprt_to_load.at(i)->getGraphicPath(x) << std::endl;
            }

        }
    }
 }