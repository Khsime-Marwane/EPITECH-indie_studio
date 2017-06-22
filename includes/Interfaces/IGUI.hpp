//
// Author: Marwane Khsime
// Date: 2017-05-22 17:49:57
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-05-22 17:49:57
//

#ifndef IGUI_HPP_
#define IGUI_HPP_

#include <string>
#include <memory>
#include <vector>
#include "IComponent.hpp"
# include "Interfaces/Event.hpp"
# include "Game/Settings.hpp"
#include "Sound.hpp"

namespace indie
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
    /// \brief Return the number of elements
    ///
    virtual std::size_t size() const = 0;
    ///
    /// \fn virtual IComponent &at(std::size_t n) = 0
    /// \brief Access to the n element
    ///
    virtual IComponent &at(std::size_t n) const = 0;
    ///
    /// \fn virtual loadComponents(indie::GameState &) = 0
    /// \brief loadComponents
    ///
    virtual void loadComponents(indie::GameState&) = 0;
    ///
    /// \fn virtual std::unique_ptr<std::vector<std::unique_ptr<indie::ISprite> > > getSprites() const = 0;
    /// \brief Get Sprites of this component
    ///
    virtual std::unique_ptr<std::vector<std::unique_ptr<indie::ISprite> > > getSprites() const = 0;
    ///
    /// \fn virtual void notifyEvent(const indie::Event &) = 0
    /// \brief Notify the GUI with an Event input
    ///
    virtual void notifyEvent(const indie::Event &) = 0;
    ///
    /// \fn virtual const std::vector<indie::Sound> &getSounds() const = 0;
    /// \brief GetSounds to play for this GUI
    ///
    virtual std::vector<indie::Sound> &getSounds() = 0;
    ///
    /// \fn virtual const std::vector<std::string> &getTransitPaths() const =0;
    /// \brief Access to the n element
    ///
    virtual const std::vector<std::string> &getTransitPaths() const = 0;
    ///
    /// \fn virtual void flushGUI() = 0;
    /// \brief Flush the GUI Properties.
    ///
    virtual void flushGUI() = 0;

  };
}

#endif // !IGUI_HPP_
