//
// Author: Sebastien Jacobin
// Date: 2017-06-04 05:18:11 
//
// Last Modified by:   Sebastien Jacobin
// Last Modified time: 2017-06-04 05:18:11
//

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>
#include <vector>
#include <Interfaces/ISprite.hpp>
#include "Interfaces/IComponent.hpp"

namespace indie
{
    class Component : public IComponent
    {
        double _x;
        double _y;
        double _width;
        double _height;
        size_t _backgroundId;
        size_t _posState;
        Color  _backgroundColor;
        Color  _textColor;
        std::string _text;
        std::vector<indie::ISprite*>  _sprites;

    public:

        Component(std::vector<indie::ISprite*>& sprites,
                  size_t backId,
                  double x,
                  double y,
                  double width,
                  double height,
                  indie::Color backColor,
                  indie::Color textColor,
                  std::string text = "");

        virtual ~Component() {}

        ///Setters Methods
        virtual void   setPosState(size_t);

        ///Getters Methods
        virtual double              getX() const;
        virtual double              getY() const;
        virtual double              getWidth() const;
        virtual double              getHeight() const;
        virtual size_t              getBackgroundId() const;
        virtual Color               getBackgroundColor() const;
        virtual Color               getTextColor() const;
        virtual std::string const & getText() const;
        virtual size_t              getPosState() const;
    };
}

#endif