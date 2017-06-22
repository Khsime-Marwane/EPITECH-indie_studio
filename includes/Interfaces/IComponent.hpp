//
// Author: Marwane Khsime
// Date: 2017-05-22 17:48:54
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-05-22 17:48:54
//

#ifndef ICOMPONENT_HPP
#define ICOMPONENT_HPP

#include <string>
#include "GameState.hpp"
#include "Color.hpp"
#include "../Common/Sprite.hpp"

namespace indie
{
  ///
  /// \class IComponent
  /// \brief Interface used to manage GUI components
  ///
    class IComponent
    {
    public:
      ///
      /// \fn virtual ~IComponent()
      /// \brief Virtual destructor of the interface
      ///
        virtual ~IComponent(){};
      ///
      /// \fn virtual double getX() const = 0
      /// \brief Get the X position (between 0.0 and 1.0)
      ///
      virtual double getX() const = 0;
      ///
      /// \fn virtual double getY() const = 0
      /// \brief Get the Y position (between 0.0 and 1.0)
      ///
      virtual double getY() const = 0;
      ///
      /// \fn virtual double getWidht() const = 0
      /// \brief Get the component's width (between 0.0 and 1.0)
      ///
      virtual double getWidth() const = 0;
      ///
      /// \fn virtual double getHeight() const = 0
      /// \brief Get the component's height (between 0.0 and 1.0)
      ///
      virtual double getHeight() const = 0;
      ///
      /// \fn virtual bool hasSprite() const = 0
      /// \brief Return true if the component has a Sprite
      ///
      virtual bool hasSprite() const = 0;
      ///
      /// \fn virtual size_t getBackgroundId() const = 0
      /// \brief Get the id of the background Sprite
      ///
      virtual size_t getBackgroundId() const = 0;
      ///
      /// \fn virtual size_t getBackgroundPos() const = 0
      /// \brief Get the pos of the background Sprite
      ///
      virtual size_t getBackgroundPos() const = 0;
      ///
      /// \fn virtual Color getBackgroundColor() const = 0
      /// \brief Get the color of the background
      ///
      virtual Color getBackgroundColor() const = 0;
      ///
      /// \fn virtual Color getBackgroundColor() const = 0
      /// \brief Get the color of the background
      ///
      virtual Color getTextColor() const = 0;
      ///
      /// \fn virtual std::string const &getText() const = 0
      /// \brief Get the text value
      ///
      virtual std::string const &getText() const = 0;

      virtual void  setBackgroundPos(size_t newPos) = 0;

      virtual void   setPos(double x, double y, double width, double height) = 0;

    };
}

#endif // ICOMPONENT_HPP
