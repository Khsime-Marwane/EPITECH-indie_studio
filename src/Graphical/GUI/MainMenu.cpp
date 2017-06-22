#include "Common/GUI.hpp"


std::vector<std::unique_ptr<indie::IComponent>> indie::GUI::loadMenu() {
    std::vector<std::unique_ptr<indie::IComponent>> res;

    _posBackground = 0;
    ///Load menu components
    res.push_back(createComponent(SpriteId::MAIN_MENU_GUI, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::ARROW, 0.31f, 0.35f, 0.36f, 0.417f, indie::Color::White, indie::Color::White));

    ///Load Menu Events
    if (!_compActions.empty())
        _compActions.clear();

    _compActions[indie::KeyboardKey::KB_ARROW_DOWN] = [this](){mainMenuKeyDown();};
    _compActions[indie::KeyboardKey::KB_ARROW_UP] = [this](){mainMenuKeyUp();};
    _compActions[indie::KeyboardKey::KB_ARROW_RIGHT] = [this](){mainMenuKeyAccess();};
    _compActions[indie::KeyboardKey::KB_ENTER] = [this](){mainMenuKeyAccess();};

    return (res);
}


void indie::GUI::mainMenuKeyDown() {
    switch (_posBackground)
    {
        case 0: _components.at(1)->setPos(0.29f, 0.435f, 0.34f, 0.505f);
            break;
        case 1: _components.at(1)->setPos(0.27f, 0.515f, 0.32f, 0.58f);
            break;
        case 2: _components.at(1)->setPos(0.31f, 0.6f, 0.36f, 0.67f);
            break;
        default:
            break;
    }
    if (_posBackground + 1 < 4)
        ++_posBackground;
}

void indie::GUI::mainMenuKeyUp() {
    switch (_posBackground)
    {
        case 1: _components.at(1)->setPos(0.31f, 0.35f, 0.36f, 0.417f);
            break;
        case 2: _components.at(1)->setPos(0.29f, 0.435f, 0.34f, 0.505f);
            break;
        case 3: _components.at(1)->setPos(0.27f, 0.515f, 0.32f, 0.58f);
            break;
        default:
            break;
    }
    if (_posBackground > 0)
        --_posBackground;
}

void indie::GUI::mainMenuKeyAccess(){
    switch (_posBackground)

    {
        case 0: {
            _sounds.push_back(indie::Sound(indie::SoundId::SOUND_TURN_PAGE));
            loadComponents((_gameState = indie::GameState::ROOM));
            _indexPaths = 2;
            _rev = false;
            _hasTransition = true;
            break;
        }

        case 1: {
            _sounds.push_back(indie::Sound(indie::SoundId::SOUND_TURN_PAGE));
            loadComponents((_gameState = indie::GameState::SETTINGS));
            _indexPaths = 1;
            _rev  = false;
            _hasTransition = true;
            break;
        }

        case 2: {
            _sounds.push_back(indie::Sound(indie::SoundId::SOUND_TURN_PAGE));
            loadComponents((_gameState = indie::GameState::SCOREBOARD));
            _indexPaths = 0;
            _rev = false;
            _hasTransition = true;
            break;
        }

        case 3: loadComponents((_gameState = indie::GameState::QUIT));
            break;

        default:
            break;
    }
}
