#ifndef GUI_HPP
#define GUI_HPP

#include <map>
#include <vector>
#include <functional>
#include "Common/Sprite.hpp"
#include "Common/Component.hpp"
#include "Interfaces/GameState.hpp"
#include "Interfaces/IGUI.hpp"
#include "Interfaces/Event.hpp"
# include "Game/Settings.hpp"

namespace indie
{
    class GUI : public IGUI
    {
    private:
        typedef std::function<std::vector<std::unique_ptr<indie::IComponent>> ()> _loadCompfunc;
        typedef std::function<void()>                                            _compActionsfunc;

        size_t                                                _posBackground;
        indie::Settings&                                       _settings;
        indie::GameState&                                      _gameState;
        std::vector<std::unique_ptr<indie::IComponent>>       _components;
        std::map<indie::GameState, _loadCompfunc>             _loadComps;
        std::map<indie::KeyboardKey, _compActionsfunc>        _compActions;

        ///Load Components Functions
        std::vector<std::unique_ptr<indie::IComponent>>    loadMenu();
        std::vector<std::unique_ptr<indie::IComponent>>    loadSettings();
        std::vector<std::unique_ptr<indie::IComponent>>    loadScore();
        std::vector<std::unique_ptr<indie::IComponent>>    loadRoom(); ///Selection players etc..

        ///Events loaded with Components
        ///---Main Menu Events---
        void    mainMenuKeyDown();
        void    mainMenuKeyUp();
        void    mainMenuKeyAccess();

        ///---Settings Menu Events---
        void   settMenuKeyDown();
        void   settMenuKeyUp();
        void   settMenuKeyRight();
        void   settMenuKeyLeft();
        void   settMenuKeyEnter();

        ///---Room Menu Events---
        void  roomMenuKeyDown();
        void  roomMenuKeyUp();
        void  roomMenuKeyRight();
        void  roomMenuKeyLeft();
        void  roomMenuKeyEnter();

        ///---Score Menu Events---
        void    scoreMenuKeyEnter();
        void    getTabNumber(std::vector<std::unique_ptr<indie::IComponent>> &, std::string, double, double, double, double);
        void    getTabDates(std::vector<std::unique_ptr<indie::IComponent>> &, std::string, double, double, double, double);


        ///CreteComponent (*component params* + all paths to sprites)
        template <typename ... args>
        std::unique_ptr<indie::IComponent>   createComponent(size_t back_id, double x, double y,
                                                             double width, double height, indie::Color backColor,
                                                             indie::Color textColor, bool hasSprite = true,
                                                             std::string text = "") {
            std::unique_ptr<indie::IComponent> res;

            res = std::make_unique<indie::Component>(hasSprite, back_id, x, y, width, height, backColor, textColor, text);
            return (res);
        }

    public:
        GUI(indie::Settings&, indie::GameState&);
        virtual ~GUI(){}

        virtual std::size_t  size() const;
        virtual IComponent &at(std::size_t n) const;
        virtual void loadComponents(indie::GameState&);
        virtual std::unique_ptr<std::vector<std::unique_ptr<indie::ISprite> > > getSprites() const;
        virtual void notifyEvent(const indie::Event &);
        
    };
}

#endif
