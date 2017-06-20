//
// Author: Marwane Khsime 
// Date: 2017-06-19 07:57:16 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-19 07:57:16
//

#include "Graphical/Gfx.hpp"
#include "Common/Timer.hpp"

void    indie::Gfx::launchIntro() {

    static std::array<std::string, 300> frames = {
        "Splash/0001.png","Splash/0002.png","Splash/0003.png","Splash/0004.png",
        "Splash/0005.png","Splash/0006.png","Splash/0007.png","Splash/0008.png",
        "Splash/0009.png","Splash/0010.png","Splash/0011.png","Splash/0012.png",
        "Splash/0013.png","Splash/0014.png","Splash/0015.png","Splash/0016.png",
        "Splash/0017.png","Splash/0018.png","Splash/0019.png","Splash/0020.png",
        "Splash/0021.png","Splash/0022.png","Splash/0023.png","Splash/0024.png",
        "Splash/0025.png","Splash/0026.png","Splash/0027.png","Splash/0028.png",
        "Splash/0029.png","Splash/0030.png","Splash/0031.png","Splash/0032.png",
        "Splash/0033.png","Splash/0034.png","Splash/0035.png","Splash/0036.png",
        "Splash/0037.png","Splash/0038.png","Splash/0039.png","Splash/0040.png",
        "Splash/0041.png","Splash/0042.png","Splash/0043.png","Splash/0044.png",
        "Splash/0045.png","Splash/0046.png","Splash/0047.png","Splash/0048.png",
        "Splash/0049.png","Splash/0050.png","Splash/0051.png","Splash/0052.png",
        "Splash/0053.png","Splash/0054.png","Splash/0055.png","Splash/0056.png",
        "Splash/0057.png","Splash/0058.png","Splash/0059.png","Splash/0060.png",
        "Splash/0061.png","Splash/0062.png","Splash/0063.png","Splash/0064.png",
        "Splash/0065.png","Splash/0066.png","Splash/0067.png","Splash/0068.png",
        "Splash/0069.png","Splash/0070.png","Splash/0071.png","Splash/0072.png",
        "Splash/0073.png","Splash/0074.png","Splash/0075.png","Splash/0076.png",
        "Splash/0077.png","Splash/0078.png","Splash/0079.png","Splash/0080.png",
        "Splash/0081.png","Splash/0082.png","Splash/0083.png","Splash/0084.png",
        "Splash/0085.png","Splash/0086.png","Splash/0087.png","Splash/0088.png",
        "Splash/0089.png","Splash/0090.png","Splash/0091.png","Splash/0092.png",
        "Splash/0093.png","Splash/0094.png","Splash/0095.png","Splash/0096.png",
        "Splash/0097.png","Splash/0098.png","Splash/0099.png","Splash/0100.png",
        "Splash/0101.png","Splash/0102.png","Splash/0103.png","Splash/0104.png",
        "Splash/0105.png","Splash/0106.png","Splash/0107.png","Splash/0108.png",
        "Splash/0109.png","Splash/0110.png","Splash/0111.png","Splash/0112.png",
        "Splash/0113.png","Splash/0114.png","Splash/0115.png","Splash/0116.png",
        "Splash/0117.png","Splash/0118.png","Splash/0119.png","Splash/0120.png",
        "Splash/0121.png","Splash/0122.png","Splash/0123.png","Splash/0124.png",
        "Splash/0125.png","Splash/0126.png","Splash/0127.png","Splash/0128.png",
        "Splash/0129.png","Splash/0130.png","Splash/0131.png","Splash/0132.png",
        "Splash/0133.png","Splash/0134.png","Splash/0135.png","Splash/0136.png",
        "Splash/0137.png","Splash/0138.png","Splash/0139.png","Splash/0140.png",
        "Splash/0141.png","Splash/0142.png","Splash/0143.png","Splash/0144.png",
        "Splash/0145.png","Splash/0146.png","Splash/0147.png","Splash/0148.png",
        "Splash/0149.png","Splash/0150.png","Splash/0151.png","Splash/0152.png",
        "Splash/0153.png","Splash/0154.png","Splash/0155.png","Splash/0156.png",
        "Splash/0157.png","Splash/0158.png","Splash/0159.png","Splash/0160.png",
        "Splash/0161.png","Splash/0162.png","Splash/0163.png","Splash/0164.png",
        "Splash/0165.png","Splash/0166.png","Splash/0167.png","Splash/0168.png",
        "Splash/0169.png","Splash/0170.png","Splash/0171.png","Splash/0172.png",
        "Splash/0173.png","Splash/0174.png","Splash/0175.png","Splash/0176.png",
        "Splash/0177.png","Splash/0178.png","Splash/0179.png","Splash/0180.png",
        "Splash/0181.png","Splash/0182.png","Splash/0183.png","Splash/0184.png",
        "Splash/0185.png","Splash/0186.png","Splash/0187.png","Splash/0188.png",
        "Splash/0189.png","Splash/0190.png","Splash/0191.png","Splash/0192.png",
        "Splash/0193.png","Splash/0194.png","Splash/0195.png","Splash/0196.png",
        "Splash/0197.png","Splash/0198.png","Splash/0199.png","Splash/0200.png",
        "Splash/0201.png","Splash/0202.png","Splash/0203.png","Splash/0204.png",
        "Splash/0205.png","Splash/0206.png","Splash/0207.png","Splash/0208.png",
        "Splash/0209.png","Splash/0210.png","Splash/0211.png","Splash/0212.png",
        "Splash/0213.png","Splash/0214.png","Splash/0215.png","Splash/0216.png",
        "Splash/0217.png","Splash/0218.png","Splash/0219.png","Splash/0220.png",
        "Splash/0221.png","Splash/0222.png","Splash/0223.png","Splash/0224.png",
        "Splash/0225.png","Splash/0226.png","Splash/0227.png","Splash/0228.png",
        "Splash/0229.png","Splash/0230.png","Splash/0231.png","Splash/0232.png",
        "Splash/0233.png","Splash/0234.png","Splash/0235.png","Splash/0236.png",
        "Splash/0237.png","Splash/0238.png","Splash/0239.png","Splash/0240.png",
        "Splash/0241.png","Splash/0242.png","Splash/0243.png","Splash/0244.png",
        "Splash/0245.png","Splash/0246.png","Splash/0247.png","Splash/0248.png",
        "Splash/0249.png","Splash/0250.png","Splash/0251.png","Splash/0252.png",
        "Splash/0253.png","Splash/0254.png","Splash/0255.png","Splash/0256.png",
        "Splash/0257.png","Splash/0258.png","Splash/0259.png","Splash/0260.png",
        "Splash/0261.png","Splash/0262.png","Splash/0263.png","Splash/0264.png",
        "Splash/0265.png","Splash/0266.png","Splash/0267.png","Splash/0268.png",
        "Splash/0269.png","Splash/0270.png","Splash/0271.png","Splash/0272.png",
        "Splash/0273.png","Splash/0274.png","Splash/0275.png","Splash/0276.png",
        "Splash/0277.png","Splash/0278.png","Splash/0279.png","Splash/0280.png",
        "Splash/0281.png","Splash/0282.png","Splash/0283.png","Splash/0284.png",
        "Splash/0285.png","Splash/0286.png","Splash/0287.png","Splash/0288.png",
        "Splash/0289.png","Splash/0290.png","Splash/0291.png","Splash/0292.png",
        "Splash/0293.png","Splash/0294.png","Splash/0295.png","Splash/0296.png",
        "Splash/0297.png","Splash/0298.png","Splash/0299.png","Splash/0300.png",
    };

    this->_introFinished = false;

    irr::video::ITexture    *load_icon;
    indie::Timer            timer;
    int                     icon_x = 1;
    int                     icon_y = 1;

    load_icon = this->_driver->getTexture("Sprites/loading_icon.png");

    for (std::size_t i = 0; i < 300; ++i) {

        irr::video::ITexture *image;

        image = this->_driver->getTexture(frames[i].c_str());

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

        if (load_icon) {

            irr::core::rect<irr::s32>   position(static_cast<irr::s32>(this->get_real_posX(0.80)),
                                                 static_cast<irr::s32>(this->get_real_posY(0.80)),
                                                 static_cast<irr::s32>(this->get_real_posX(0.95)),
                                                 static_cast<irr::s32>(this->get_real_posY(0.95))
                                                );
            irr::core::rect<irr::s32>   sprite_area(icon_x,
                                                    icon_y,
                                                    icon_x + 161,
                                                    icon_y + 161);
            this->_driver->draw2DImage( load_icon,
                                        position,
                                        sprite_area,
                                        0,
                                        NULL,
                                        true);

        } // End Loading Icon

        while (timer.Elapsed() < static_cast<std::chrono::milliseconds>(60));
        timer.Reset();

        this->display();

        if (icon_x + 161 >= 965) {
            icon_x = 1;
            icon_y = icon_y + 161 > 640 ? 1 : icon_y + 161;
        } else {
            icon_x = icon_x + 161;
        }

    } // END Splash Screen

    if (load_icon)
        this->_driver->removeTexture(load_icon);

    this->_introFinished = true;

 }