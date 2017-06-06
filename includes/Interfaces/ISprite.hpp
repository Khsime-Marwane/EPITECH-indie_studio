//
// Author: Marwane Khsime 
// Date: 2017-05-22 17:50:11 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-22 17:50:11
//

#ifndef ISprite_HPP_
# define ISprite_HPP_

# include <string>

namespace indie
{
  ///
  /// \class ISprite
  /// \brief Interface to use in order to generate the Sprite loading list
  ///
  class ISprite
  {
  public:
    ///
    /// \fn virtual ~ISprite()
    /// \brief virtual destructor
    ///
    virtual ~ISprite() {};

    ///
    /// \fn virtual size_t SpritesCount() const = 0
    /// \brief returns the numbers of Sprites
    ///
    virtual size_t SpritesCount() const = 0;

    ///
    /// \fn virtual std::string getGraphicPath(size_t id) const = 0
    /// \brief generates on-the-fly the path to the Sprite at position pos to load
    ///
    virtual std::string getGraphicPath(size_t pos) const = 0;

    ///
    /// \fn virtual std::string const& getAscii() const = 0
    /// \brief returns the ascii character at position pos from the animation sequence
    ///
    /// virtual char getAscii(size_t pos) const = 0;
  };

}

#endif // !ISprite_HPP_
