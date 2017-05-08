//
// Author: Marwane Khsime 
// Date: 2017-05-05 04:58:44 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-05 04:58:44
//

#ifndef IGUI_H
#define IGUI_H

#include <string>
#include <memory>
#include <vector>

#include "IComponent.hpp"

namespace arcade
{
  ///
  /// \class IGUI
  /// \brief Interface representing a GUI
  ///
  class IGUI
  {
    public:
        ///
        /// \fn virtual ~IGUI()
        /// \brief Virtual destructor of the interface
        ///
        virtual ~IGUI() {};

        // Number of IComponent
        ///
        /// \fn virtual std::size_t size() const = 0
        /// \brief Return the number of components
        ///
        virtual std::size_t size() const = 0;
        ///
        /// \fn virtual IComponent &at(std::size_t n) = 0
        /// \brief Access to the n element
        ///
        virtual IComponent &at(std::size_t n) = 0;
  };
}

#endif // !IGUI_H
