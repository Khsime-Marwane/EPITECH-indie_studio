#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <iostream>
#include <vector>
#include "Interfaces/ISprite.hpp"

namespace indie
{
    class Sprite : public ISprite
    {
        std::vector<std::string>   _spritesPath;
    public:
        Sprite() : _spritesPath() {}
        template <typename... args>
        Sprite(args... a) : _spritesPath() { _spritesPath = {a...}; }
        virtual ~Sprite(){}

        virtual size_t SpritesCount() const;
        virtual std::string getGraphicPath(size_t pos) const;
        indie::Sprite   &operator=(const indie::Sprite &other);
        virtual void    addPath(std::string path);
    };
}

#endif