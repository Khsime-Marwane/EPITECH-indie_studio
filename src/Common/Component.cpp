//
// Author: Marwane Khsime 
// Date: 2017-06-04 05:33:17 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-04 05:33:17
//

#include "Common/Component.hpp"

indie::Component::Component(indie::Sprite &sprite,
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
        _sprite(&sprite) {
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
          _sprite(other._sprite) {
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
    _sprite = other._sprite;
    return (*this);
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
    if (_sprite->SpritesCount() > 0)
        return (true);
    return (false);
}

size_t indie::Component::getBackgroundPos() const {
    return (_backgroundPos);
}

indie::Component::~Component() {
    delete _sprite;
}

void indie::Component::setBackgroundPos(size_t newPos) {
    _backgroundPos = newPos;
}

indie::Sprite* indie::Component::getSprite() {
    return (_sprite);
}
