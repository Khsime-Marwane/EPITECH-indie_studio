//
// Author: Marwane Khsime 
// Date: 2017-06-10 01:57:56 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-10 01:57:56
//

#include "Graphical/Gfx.hpp"

void    indie::Gfx::set_camera_pov(const IMap &map) {

    if (map.getPOV() != this->_infos._camera_view_point)
    {
        this->_infos._camera_view_point = map.getPOV();
    } else {
        // No need to refresh the positions
        return ;
    }

    switch (this->_infos._camera_view_point)
    {
        case ECAMERA_VIEW::DEFAULT:

            this->_camera->setPosition(
                irr::core::vector3df( {

                    // x
                    -1.0f * (static_cast< float >(map.getWidth()) + 3.5f) / 2.0f,
                    
                    // y
                    sqrt( static_cast< float >(pow( static_cast< float >(map.getWidth()) - 2.0f, 2))
                        + static_cast< float >(pow( static_cast< float >(map.getHeight()) - 2.0f, 2))
                        ),
                    
                    // z
                    static_cast< float >(map.getHeight()) / 2.0f

                })
            );

            this->_camera->setTarget(
                irr::core::vector3df( {
                    -7.4f,
                    -1080.0f,
                    90.0f
                })
            );

            this->_camera->bindTargetAndRotation(true);

            break;

        case ECAMERA_VIEW::INCLINED:

            this->_camera->setPosition(
                irr::core::vector3df( {
                    -1 * (static_cast< float >(map.getWidth()) + 3.5f) / 2.0f,
                        sqrt(static_cast< float >(pow( static_cast< float >(map.getWidth()) - 2.0f, 2))
                        + static_cast< float >(pow ( static_cast< float >(map.getHeight()) - 2.0f, 2))) / 2.0f,
                    0.0f
                })
            );

            this->_camera->setTarget(
                irr::core::vector3df( {
                    -7.4f,
                    -90.0f,
                    90.0f
                })
            );

            this->_camera->bindTargetAndRotation(true);

            break;

        case ECAMERA_VIEW::UNDEFINED:
        default:
            std::cerr << _INDIE_GFX_INVALID_CAMERA_POV << std::endl;

            this->_camera->setPosition(
                irr::core::vector3df( {

                    // x
                    -1.0f * (static_cast< float >(map.getWidth()) + 3.5f) / 2.0f,
                    
                    // y
                    sqrt( static_cast< float >(pow( static_cast< float >(map.getWidth()) - 2.0f, 2))
                        + static_cast< float >(pow( static_cast< float >(map.getHeight()) - 2.0f, 2))
                        ),
                    
                    // z
                    static_cast< float >(map.getHeight()) / 2.0f

                })
            );

            this->_camera->setTarget(
                irr::core::vector3df( {
                    -7.4f,
                    -1080.0f,
                    90.0f
                })
            );

            this->_camera->bindTargetAndRotation(true);

            break;
    }

}