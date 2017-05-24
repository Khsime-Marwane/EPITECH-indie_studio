//
// Author: Marwane Khsime 
// Date: 2017-05-03 01:50:31 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-03 01:50:31
//

#include <iostream>
#include <chrono>
#include <thread>

#include "Graphical/Gfx.hpp"

#ifdef _MSC_VER

    #define _CRT_SECURE_NO_WARNINGS

    #pragma comment(lib, "Irrlicht.lib")

    #pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

#endif


int main() {

    #if defined __linux__
        if (helper::Helper::get().getEnvVariable("DISPLAY") != ":0")
            std::cerr << "The DISPLAY environment variable is not set correctly." << std::endl;
    #endif

    // Testing Gfx
    std::unique_ptr<indie::Gfx> gfx = std::make_unique<indie::Gfx>();

    gfx->_device->setWindowCaption(L"BOMBTLET");
    for (std::size_t i = 0; i < 2; ++i) {
        gfx->display();
        gfx->clear();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return EXIT_SUCCESS;
}
