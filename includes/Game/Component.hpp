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
#include <memory>
#include "Common/Sprite.hpp"
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
        indie::Sprite*  _sprite;

    public:

        Component(indie::Sprite* sprite,
                  size_t backId,
                  double x,
                  double y,
                  double width,
                  double height,
                  indie::Color backColor,
                  indie::Color textColor,
                  std::string text = "");
        Component(const indie::Component &other);
        virtual ~Component();

        ///Setters Methods
        // Setters Methods
        virtual void                setX(double);
        virtual void                setY(double);
        virtual void                setWidth(double);
        virtual void                setHeight(double);
        virtual void                setBackgroundId(std::size_t);
        virtual void                setBackgorundColor(const Color &);
        virtual void                setTextColor(const Color &);
        virtual void                setText(const std::string &);

        // Getters Methods
        virtual double              getX() const;
        virtual double              getY() const;
        virtual double              getWidth() const;
        virtual double              getHeight() const;
        virtual size_t              getBackgroundId() const;
        virtual Color               getBackgroundColor() const;
        virtual Color               getTextColor() const;
        virtual std::string const & getText() const;
        virtual bool                hasSprite() const;
        virtual size_t              getBackgroundPos() const;
        indie::Component             &operator=(const indie::Component &other);

        virtual indie::Sprite*      &getSprite();
    };
}


#endif