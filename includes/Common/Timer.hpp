//
// Author: Marwane Khsime 
// Date: 2017-06-18 11:57:34 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-18 11:57:34
//

#ifndef TIMER_HPP
# define TIMER_HPP

#include <thread>
#include <chrono>
#include <ostream>

namespace indie
{
    class   Timer {

        typedef std::chrono::high_resolution_clock  hight_resolution_clock;
        typedef std::chrono::milliseconds           milliseconds;

        public:

            explicit Timer() : _start() {
                this->Reset();
            }

            void Reset() {
                this->_start = hight_resolution_clock::now();
            }

            milliseconds Elapsed() const {
                return std::chrono::duration_cast<milliseconds>(hight_resolution_clock::now() - this->_start);
            }

        private:
            hight_resolution_clock::time_point   _start;
    };
}


#endif // TIMER_HPP