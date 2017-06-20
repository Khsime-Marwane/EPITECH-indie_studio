#include <Game/Score.hpp>
#include <Interfaces/Sound.hpp>
#include "Common/GUI.hpp"

indie::GUI::GUI(indie::Settings& settings, indie::GameState& state) : _posBackground(0), _settings(settings), _gameState(state), _components(), _loadComps(), _compActions() {

    _loadComps[indie::GameState::MAIN_MENU] = [this](){return loadMenu();};
    _loadComps[indie::GameState::SETTINGS] = [this](){return loadSettings();};
    _loadComps[indie::GameState::SCOREBOARD] = [this](){return loadScore();};
    _loadComps[indie::GameState::ROOM] = [this](){return loadRoom();};

}

std::size_t indie::GUI::size() const {
    return (_components.size());
}

indie::IComponent & indie::GUI::at(std::size_t n) const {
    return (*_components.at(n));
}

void indie::GUI::loadComponents(indie::GameState& state) {
    if (!_components.empty())
        _components.clear();
    if (_loadComps.find(state) != _loadComps.end())
        _components = _loadComps[state]();
}

std::unique_ptr<std::vector<std::unique_ptr<indie::ISprite> > > indie::GUI::getSprites() const {
    std::unique_ptr<std::vector<std::unique_ptr<indie::ISprite> > > sprites;

    sprites = std::make_unique<std::vector<std::unique_ptr<indie::ISprite> > >();
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/main/main_select_play.png",
                                                         "Menu/main/main_select_settings.png",
                                                         "Menu/main/main_select_highscores.png",
                                                         "Menu/main/main_select_exit.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/settings/settings_base.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/settings/settings_sound_0.png",
                                                         "Menu/settings/settings_sound_1.png",
                                                         "Menu/settings/settings_sound_2.png",
                                                         "Menu/settings/settings_sound_3.png",
                                                         "Menu/settings/settings_sound_4.png",
                                                         "Menu/settings/settings_sound_5.png",
                                                         "Menu/settings/settings_sound_6.png",
                                                         "Menu/settings/settings_sound_7.png",
                                                         "Menu/settings/settings_sound_8.png",
                                                         "Menu/settings/settings_sound_9.png",
                                                         "Menu/settings/settings_sound_10.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/settings/settings_ai_normal.png", "Menu/settings/settings_ai_hard.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/arrow.png", "Menu/arrow-rev.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/room_base.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Sprites/score.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/0.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/1.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/2.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/3.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/4.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/5.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/6.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/7.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/8.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/9.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu/room/dot.png"));
    return (std::move(sprites));
}
void indie::GUI::notifyEvent(const indie::Event &event) {
    if (event.type == indie::EventType::ET_KEYBOARD)
    {
        if (_compActions.find(event.kb_key) != _compActions.end())
            _compActions[event.kb_key]();
    }
}

std::vector<std::unique_ptr<indie::IComponent>> indie::GUI::loadMenu() {
    std::vector<std::unique_ptr<indie::IComponent>> res;

    _posBackground = 0;
    ///Load menu components
     res.push_back(createComponent(0, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));

    ///Load Menu Events
    if (!_compActions.empty())
        _compActions.clear();

    _compActions[indie::KeyboardKey::KB_ARROW_DOWN] = [this](){mainMenuKeyDown();};
    _compActions[indie::KeyboardKey::KB_ARROW_UP] = [this](){mainMenuKeyUp();};
    _compActions[indie::KeyboardKey::KB_ARROW_RIGHT] = [this](){mainMenuKeyAccess();};
    _compActions[indie::KeyboardKey::KB_ENTER] = [this](){mainMenuKeyAccess();};

    return (res);
}

std::vector<std::unique_ptr<indie::IComponent>> indie::GUI::loadSettings() {
    std::vector<std::unique_ptr<indie::IComponent>> res;

    ///Load Settings components
    _posBackground = 0;

    res.push_back(createComponent(1, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(2, 0.22f, 0.37f, 0.77f, 0.45f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(3, 0.28f, 0.57f, 0.68f, 0.77f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(4, 0.28f, 0.25f, 0.38f, 0.35f, indie::Color::White, indie::Color::White));

    ///Load Settings Values
    res.at(1)->setBackgroundPos(static_cast<size_t>(_settings.volume / 10));
    res.at(2)->setBackgroundPos(static_cast<size_t >(_settings.difficulty));

    ///Load Settings Events
    if (!_compActions.empty())
        _compActions.clear();

    _compActions[indie::KeyboardKey::KB_ARROW_DOWN] = [this](){settMenuKeyDown();};
    _compActions[indie::KeyboardKey::KB_ARROW_UP] = [this](){settMenuKeyUp();};
    _compActions[indie::KeyboardKey::KB_ARROW_RIGHT] = [this](){settMenuKeyRight();};
    _compActions[indie::KeyboardKey::KB_ARROW_LEFT] = [this](){settMenuKeyLeft();};
    _compActions[indie::KeyboardKey::KB_ENTER] = [this](){settMenuKeyEnter();};

    return (res);
}

std::vector<std::unique_ptr<indie::IComponent>> indie::GUI::loadRoom() {
    std::vector<std::unique_ptr<indie::IComponent>> res;

    std::cout << "LOAD ROOM\n";
    ///Load Room Components

    res.push_back(createComponent(5, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(4, 0.09f, 0.33f, 0.18f, 0.39f, indie::Color::White, indie::Color::White));

    if (!_compActions.empty())
        _compActions.clear();

    _compActions[indie::KeyboardKey::KB_ARROW_DOWN] = [this](){roomMenuKeyDown();};
    _compActions[indie::KeyboardKey::KB_ARROW_UP] = [this](){roomMenuKeyUp();};
    _compActions[indie::KeyboardKey::KB_ARROW_RIGHT] = [this](){roomMenuKeyRight();};
    _compActions[indie::KeyboardKey::KB_ARROW_LEFT] = [this](){roomMenuKeyLeft();};
    _compActions[indie::KeyboardKey::KB_ENTER] = [this](){roomMenuKeyEnter();};

    return (res);
}

std::vector<std::unique_ptr<indie::IComponent>> indie::GUI::loadScore() {
    std::vector<std::unique_ptr<indie::IComponent>> res;
    std::unique_ptr<indie::Score> score = std::make_unique<indie::Score>();
    double  y;
    double  height;

    _posBackground = 0;

    ///Load Score components


    std::vector<int> scores = score->GetScores();
    std::vector<std::string> dates = score->GetDates();

    res.push_back(createComponent(6, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
    y = 0.35f;
    height = 0.41f;
    for(std::vector<int>::iterator i = scores.begin(); i != scores.end(); ++i)  
    {
        getTabNumber(res, std::to_string(*i), 0.10f, y, 0.16f, height);
        y += 0.1;
        height += 0.1;
    }
    y = 0.35f;
    height = 0.41f;
    for(std::vector<std::string>::iterator i = dates.begin(); i != dates.end();++i)
    {
        getTabDates(res, *i, 0.33f, y, 0.39f, height);
        y += 0.1;
        height += 0.1;
    }

    if (!_compActions.empty())
        _compActions.clear();

    _compActions[indie::KeyboardKey::KB_ENTER] = [this](){scoreMenuKeyEnter();};

    return (res);
}


///     Event Main Menu functions --- Start

void indie::GUI::mainMenuKeyDown() {
    if (_posBackground + 1 < 4)
        _components.at(0)->setBackgroundPos(++_posBackground);
}

void indie::GUI::mainMenuKeyUp() {
    if (_posBackground > 0)
        _components.at(0)->setBackgroundPos(--_posBackground);
}

void indie::GUI::mainMenuKeyAccess(){
    switch (_posBackground)

    {
        case 0: loadComponents((_gameState = indie::GameState::INGAME));
            break;
        case 1: loadComponents((_gameState = indie::GameState::SETTINGS));
            break;
        case 2: loadComponents((_gameState = indie::GameState::SCOREBOARD));
            break;
        case 3: loadComponents((_gameState = indie::GameState::QUIT));
            break;
        default:
            break;
    }
}

///     Event Main Menu functions --- End

///---------------------------------------------------------

///     Event Settings Menu functions --- Start

void indie::GUI::settMenuKeyDown() {
    switch (_posBackground)
    {
        case 0: _components.at(3)->setPos(0.26f, 0.47f, 0.36f, 0.57f);
            break;
        case 1: {
            _components.at(3)->setPos(0.225f, 0.89f, 0.29f, 0.99f);
            _components.at(3)->setBackgroundPos(1);
            break;
        }
        default:
            break;
    }
    if (_posBackground + 1 < 3)
        ++_posBackground;
}

void indie::GUI::settMenuKeyUp() {
    switch (_posBackground)
    {
        case 1: {
            _components.at(3)->setPos(0.28f, 0.25f, 0.38f, 0.35f);
            _components.at(3)->setBackgroundPos(0);
            break;
        }
        case 2: {
            _components.at(3)->setPos(0.26f, 0.47f, 0.36f, 0.57f);
            _components.at(3)->setBackgroundPos(0);
            break;
        }
        default:
            break;
    }
    if (_posBackground > 0)
        --_posBackground;
}

void indie::GUI::settMenuKeyRight() {
    switch (_posBackground) {
        case 0 :{
            if (_settings.volume + 10 <= 100) {
                _settings.volume += 10;
                _components.at(1)->setBackgroundPos(static_cast<size_t >(_settings.volume / 10));
            }
            break;
        }
        case 1:{
            if (_settings.difficulty == indie::IA_LEVEL::IA_MEDIUM) {
                _settings.difficulty = indie::IA_LEVEL::IA_HARD;
                _components.at(2)->setBackgroundPos(static_cast<size_t >(_settings.difficulty));
            }
            break;
        }
        case 2: loadComponents((_gameState = indie::GameState::MAIN_MENU));
            break;
        default:
            break;
    }
}

void indie::GUI::settMenuKeyLeft() {
    switch (_posBackground)
    {
        case 0 : {
            if (_settings.volume - 10 >= 0) {
                _settings.volume -= 10;
                _components.at(1)->setBackgroundPos(static_cast<size_t >(_settings.volume / 10));
            }
            break;
        }
        case 1: {
            if (_settings.difficulty == indie::IA_LEVEL::IA_HARD) {
                _settings.difficulty = indie::IA_LEVEL::IA_MEDIUM;
                _components.at(2)->setBackgroundPos(static_cast<size_t >(_settings.difficulty));
            }
            break;
        }
        default:
            break;
    }
}

void indie::GUI::settMenuKeyEnter() {
    if (_posBackground == 2)
        loadComponents((_gameState = indie::GameState::MAIN_MENU));
}

///     Event Settings Menu functions --- End

///---------------------------------------------------------

///     Event Room Menu functions --- Start

void indie::GUI::roomMenuKeyDown() {
    if (_posBackground < 3)
        ++_posBackground;
//    if (_compId + 1 < _components.size())
//    switch (_posBackground)
//    {
//        case 0: {
//            _components.at(1)->setBackgroundPos(0)
//        }
//
//    }
}

void indie::GUI::roomMenuKeyUp() {
//    if (_compId - 1 > 1)
//    {
//        for (size_t i = 1; i < _components.size(); ++i)
//        {
//            if (i == _compId - 1)
//                _components.at(i)->setBackgroundPos(1);
//            else
//                _components.at(i)->setBackgroundPos(0);
//        }
//        _compId--;
//    }
}

void indie::GUI::roomMenuKeyRight() {
}

void indie::GUI::roomMenuKeyLeft() {
//    switch (_compId) {
//        case 2 : {
//            if (_settings.nplayers - 1 > 2)
//                _settings.nplayers--;
//            break;
//        }
//        case 3: {
//            if (_settings.nplayers - 1 > 2)
//                _settings.nplayers--;
//            break;
//        }
//        case 8: loadComponents(indie::GameState::MAIN_MENU);
//            break;
//        default:
//            break;
//    }
}

void indie::GUI::roomMenuKeyEnter() {
    if (_posBackground != 0)
        _gameState = indie::GameState::INGAME;
}

///     Event Room Menu functions --- End
///---------------------------------------------------------
///     Event Score Menu functions --- Start

void indie::GUI::scoreMenuKeyEnter() {
    _gameState = indie::GameState::MAIN_MENU;
    loadComponents(_gameState);
}

void    indie::GUI::getTabNumber(std::vector<std::unique_ptr<indie::IComponent>> &res, std::string score, double x, double y, double width, double height)
{
    int nb;
    double  pos_x;

    pos_x = x;
    for (int i = 0; score[i] != '\0'; ++i)
    {
        nb = score[i] - 48 + 7;
        res.push_back(createComponent(nb, pos_x, y, width, height, indie::Color::White, indie::Color::White));
        pos_x += 0.06;
        width += 0.06;
    }
}

void    indie::GUI::getTabDates(std::vector<std::unique_ptr<indie::IComponent>> &res, std::string score, double x, double y, double width, double height)
{
    int nb;
    double  pos_x;

    pos_x = x;
    for (int i = 0; score[i] != '\0'; ++i)
    {
        if (score[i] >= '0' && score[i] <= '9')
            nb = score[i] - 48 + 7;             
        else
            nb = 17;
        res.push_back(createComponent(nb, pos_x, y, width, height, indie::Color::White, indie::Color::White));
        pos_x += 0.06;
        width += 0.06;
    }
}

///     Event Score Menu functions --- End
