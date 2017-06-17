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
        typedef std::function<std::vector<std::shared_ptr<indie::IComponent>> ()> _loadCompfunc;
        typedef std::function<void()>                                            _compActionsfunc;

        size_t                                                _compId;
        indie::Settings&                                       _settings;
        std::vector<std::shared_ptr<indie::ISprite>>          _sprites;
        std::vector<std::shared_ptr<indie::IComponent>>       _components;
        std::map<indie::GameState, _loadCompfunc>             _loadComps;
        std::map<indie::KeyboardKey, _compActionsfunc>        _compActions;

        ///Load Components Functions
        std::vector<std::shared_ptr<indie::IComponent>>    loadMenu();
        std::vector<std::shared_ptr<indie::IComponent>>    loadSettings();
        std::vector<std::shared_ptr<indie::IComponent>>    loadScore();
        std::vector<std::shared_ptr<indie::IComponent>>    loadRoom(); ///Selection players etc..

        ///Events load with Components
        ///---Main Menu Events---
        void    mainMenuKeyDown();
        void    mainMenuKeyUp();
        void    mainMenuKeyRight();
        void    mainMenuKeyEnter();

        ///CreteComponent (*component params* + all paths to sprites)
        template <typename ... args>
        std::shared_ptr<indie::IComponent>   createComponent(size_t back_id, double x, double y,
                                                             double width, double height, indie::Color backColor,
                                                             indie::Color textColor, std::string text,
                                                             args... paths) {
            std::shared_ptr<indie::IComponent> res;
            std::shared_ptr<indie::Sprite> tmp;
            tmp = std::make_shared<indie::Sprite>(paths...);

            res = std::make_shared<indie::Component>(*tmp, back_id, x, y, width, height, backColor, textColor, text);
            _sprites.push_back(tmp);
            return (res);
        }

    public:
        GUI(indie::Settings&);
        virtual ~GUI(){}

        virtual std::size_t  size() const;
        virtual IComponent &at(std::size_t n) const;
        virtual void loadComponents(indie::GameState);
        virtual std::vector<std::shared_ptr<indie::ISprite> > getSprites();
        virtual void notifyEvent(const indie::Event &);
    };
}

#endif
