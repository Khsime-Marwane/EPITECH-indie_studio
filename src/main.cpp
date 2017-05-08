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

#include "Exception/exception.hpp"
#include "Common/common.hpp"
#include "Graphical/Gfx.hpp"

int main() {

    #if defined __linux__
        if (helper::Helper::get().getEnvVariable("DISPLAY") != ":0")
            std::cerr << "The DISPLAY environment variable is not set correctly." << std::endl;
    #endif


    // Testing Gfx
    indie::Gfx  gfx;

    for (std::size_t i = 0; i < 2; ++i) {
        gfx.display();
        gfx.clear();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return EXIT_SUCCESS;
}
