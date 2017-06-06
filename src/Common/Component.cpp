//
// Author: Marwane Khsime 
// Date: 2017-06-04 05:33:17 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-04 05:33:17
//

#include "Common/Component.hpp"

indie::Component::Component(std::vector<indie::ISprite*> &sprites,
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
        _posState(0),
        _backgroundColor(backColor),
        _textColor(textColor),
        _text(text),
        _sprites(sprites) {

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

size_t indie::Component::getPosState() const {
    return (_posState);
}

void indie::Component::setPosState(size_t newPos) {
    if (newPos <= _sprites.size())
        _posState = newPos;
    else
        std::cerr << "posState > _sprites.size()" << std::endl;
}
