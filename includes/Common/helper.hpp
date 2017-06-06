//
// Author: Marwane Khsime 
// Date: 2017-05-03 15:28:57 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-03 15:28:57
//

#ifndef HELPER_HPP
# define HELPER_HPP

#include <string>
#include <cstring>
#include <sstream>
#include <vector>

namespace helper {


    ///
    /// \class Helper
    /// \brief A set of "tool" methods.
    /// 
    /// This class is of singleton type. Use the static method to retrieve the Helper instance.
    ///
    class Helper
    {

        private:
            ///
            /// \fn Helper()
            /// \brief  Private constructor
            ///
            Helper() {}

        public:
            ///
            /// \fn Helper(const Helper &) = delete
            /// \fn void operator=(const Helper &) = delete
            /// \brief  The use of the constructor and/or the equal operator is not allowed.
            ///
            Helper(const Helper &)  = delete;
            void operator=(const Helper &)  = delete;
            ///
            /// \fn     static Helper & get() noexcept
            /// \brief  Retrieves the reference to the instance.
            ///
            static Helper&  get() noexcept {
                static Helper    helper_instance;

                return helper_instance;
            }
            ///
            /// \fn     std::string getEvenVariable(const std::string &key) noexcept
            /// \brief  Retrieves the value of an environment variable. If the variable does not exist, an empty string is returned.
            /// \param  The name of the variable to get.
            ///
            std::string     getEnvVariable(const std::string &variable_name) const noexcept {
                char * val = getenv( variable_name.c_str() );
                return val == NULL ? std::string("") : std::string(val);
            }

            const wchar_t *getWC(const char *c) noexcept {

                const size_t cSize = std::strlen(c)+1;
                wchar_t* wc = new wchar_t[cSize];
                mbstowcs (wc, c, cSize);

                return wc;
            }

    };

}
 
# endif // HELPER_HPP
