//
// Author: Marwane Khsime 
// Date: 2017-06-04 05:33:17 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-04 05:33:17
//

#include "Common/Component.hpp"

indie::Component::Component(bool hasSprite,
                            size_t backId,
                            double x,
                            double y,
                            double width,
                            double height,
                            indie::Color backColor,
                            indie::Color textColor,
                            std::string text)
        :
        _x(x),
        _y(y),
        _width(width),
        _height(height),
        _backgroundId(backId),
        _backgroundPos(0),
        _backgroundColor(backColor),
        _textColor(textColor),
        _text(text),
        _hasSprite(hasSprite) {
}

indie::Component::Component(const indie::Component &other)
        : _x(other._x),
          _y(other._y),
          _width(other._width),
          _height(other._height),
          _backgroundId(other._backgroundId),
          _backgroundPos(other._backgroundPos),
          _backgroundColor(other._backgroundColor),
          _textColor(other._textColor),
          _text(other._text),
          _hasSprite(other._hasSprite) {
}

indie::Component &indie::Component::operator=(const indie::Component &other) {
    _x = other._x;
    _y = other._y;
    _width = other._width;
    _height = other._height;
    _backgroundId = other._backgroundId;
    _backgroundPos = other._backgroundPos;
    _backgroundColor = other._backgroundColor;
    _textColor = other._textColor;
    _text = other._text;
    _hasSprite = other._hasSprite;
    return (*this);
}

void indie::Component::setBackgroundPos(size_t newPos) { _backgroundPos = newPos; }

void indie::Component::setPos(double x, double y, double width, double height) {
    _x = x;
    _y = y;
    _width = width;
    _height = height;
}

double indie::Component::getX() const {
    return (_x);
}

double indie::Component::getY() const {
    return (_y);
}

double indie::Component::getWidth() const {
    return (_width);
}

double indie::Component::getHeight() const {
    return (_height);
}

size_t indie::Component::getBackgroundId() const {
    return (_backgroundId);
}

indie::Color indie::Component::getBackgroundColor() const {
    return (_backgroundColor);
}

indie::Color indie::Component::getTextColor() const {
    return (_textColor);
}

std::string const& indie::Component::getText() const {
    return (_text);
}

bool indie::Component::hasSprite() const {
    return (_hasSprite);
}

size_t indie::Component::getBackgroundPos() const {
    return (_backgroundPos);
}