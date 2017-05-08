//
// Author: Marwane Khsime 
// Date: 2017-05-03 00:59:29 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-03 00:59:29
//

#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

#include <string>
#include <exception>


namespace indie
{
    namespace exception
    {
        ///\class Error
        ///\brief Class inheriting from std exception.
        ///
        class Error : public std::exception {
            
            protected:
                std::string _message;   ///< Brief Contains the error message
            
            public:
                ///
                /// \fn Error(const std::string &message) noexcept
                /// \brief Constructor to create Error instance from message.
                ///
                Error(const std::string &message) noexcept : _message(message) {};     
                ///
                /// \fn Error() noexcept
                /// \brief Constructor to create Error instance with empty message.
                ///
                Error() noexcept : _message("") {};
                ///
                /// \fn virtual ~Error() noexcept
                /// \brief Virtual destructor of the class.
                ///
                virtual ~Error() noexcept {};     
                ///
                /// \fn virtual const char *what() const noexcept
                /// \brief  Return the value of the error message.
                ///
                virtual const char *what() const noexcept { return this->_message.c_str(); };

        };
    }
}

# endif // EXCEPTION_HPP
