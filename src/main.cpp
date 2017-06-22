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

//#include "irrKlang/irrKlang.h"
#include "Core/Core.hpp"

#ifdef _MSC_VER

    #define _CRT_SECURE_NO_WARNINGS

    #pragma comment(lib, "Irrlicht.lib")
    #pragma comment(lib, "irrKlang.lib")

    #pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")

#endif


int main() {

    #if defined __linux__
        if (helper::Helper::get().getEnvVariable("DISPLAY") != ":0")
            std::cerr << "The DISPLAY environment variable is not set correctly." << std::endl;
    #endif

    // Testing Gfx
    try {

      std::unique_ptr<indie::Core> core = std::make_unique<indie::Core>();

      if (!core)
        return std::cerr << _INDIE_LAUNCHING_FAILED << std::endl, EXIT_FAILURE;

      core->runCoreLoop();

    }

    catch (const std::exception &err) {
        std::cerr << err.what() << std::endl;
        std::cerr << _INDIE_LAUNCHING_FAILED << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
