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
#include <iostream>

#include "errors_messages.hpp"

namespace indie
{
        ///\class IndieError
        ///\brief Class inheriting from std exception.
        ///
        class IndieError : public std::exception {
            
            protected:
                std::string _message;   ///< Brief Contains the IndieError message
            
            public:
                ///
                /// \fn IndieError(const std::string &message) noexcept
                /// \brief Constructor to create IndieError instance from message.
                ///
                IndieError(const std::string &message) noexcept : _message(message) {};
                ///
                /// \fn IndieError() noexcept
                /// \brief Constructor to create IndieError instance with empty message.
                ///
                IndieError() noexcept : _message("") {};
                ///
                /// \fn IndieError(const IndieError &err) noexcept
                /// \brief Constructor to create IndieError instance with empty message.
                ///
                IndieError(const IndieError &err) noexcept
                    : _message(err.what()) {
                };
                ///
                /// \fn IndieError &operator=(const IndieError &err) noexcept
                /// \brief Constructor to create IndieError instance with empty message.
                ///
                IndieError  &operator=(const IndieError &err) noexcept {
                    if (&err == this)
                        return *this;
                    this->_message = err.what();
                    return *this;
                };
                ///
                /// \fn ~IndieError() noexcept
                /// \brief Destructor.
                ///
                virtual ~IndieError() noexcept {};
                ///
                /// \fn virtual const char *what() const noexcept
                /// \brief  Return the value of the IndieError message.
                ///
                virtual const char *what() const noexcept { return this->_message.c_str(); };

        };
}

# endif // EXCEPTION_HPP
