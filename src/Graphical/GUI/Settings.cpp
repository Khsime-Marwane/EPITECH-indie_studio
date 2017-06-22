#include "Common/GUI.hpp"


std::vector<std::unique_ptr<indie::IComponent>> indie::GUI::loadSettings() {
    std::vector<std::unique_ptr<indie::IComponent>> res;

    ///Load Settings components
    _posBackground = 0;

    res.push_back(createComponent(SpriteId::SETTINGS_MENU, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::ARROW, 0.57f, 0.3f, 0.61f, 0.37f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::SETTINGS_SOUND, 0.525f, 0.39f, 0.76f, 0.47f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::SETTINGS_LVL, 0.54f, 0.58f, 0.76f, 0.75f, indie::Color::White, indie::Color::White));

    ///Load Settings Values
    res.at(2)->setBackgroundPos(static_cast<size_t>(_settings.volume / 10));
    res.at(3)->setBackgroundPos(static_cast<size_t >(_settings.difficulty));

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

void indie::GUI::settMenuKeyDown() {
    switch (_posBackground)
    {
        case 0: _components.at(1)->setPos(0.57f, 0.47f, 0.61f, 0.53f);
            break;
        case 1: {
            _components.at(1)->setPos(0.53f, 0.77f, 0.57f, 0.82f);
            _components.at(1)->setBackgroundPos(2);
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
            _components.at(1)->setPos(0.57f, 0.3f, 0.61f, 0.37f);
            _components.at(1)->setBackgroundPos(0);
            break;
        }
        case 2: {
            _components.at(1)->setPos(0.57f, 0.47f, 0.61f, 0.53f);
            _components.at(1)->setBackgroundPos(0);
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
                _components.at(2)->setBackgroundPos(static_cast<size_t >(_settings.volume / 10));
            }
            break;
        }
        case 1:{
            if (_settings.difficulty == indie::IA_LEVEL::IA_MEDIUM) {
                _settings.difficulty = indie::IA_LEVEL::IA_HARD;
                _components.at(3)->setBackgroundPos(static_cast<size_t >(_settings.difficulty));
            }
            break;
        }
        case 2: {
            _hasTransition = true;
            _rev = true;
            _indexPaths = 1;
            _sounds.push_back(indie::Sound(indie::SoundId::SOUND_TURN_PAGE));
            loadComponents((_gameState = indie::GameState::MAIN_MENU));
            break;
        }
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
                _components.at(2)->setBackgroundPos(static_cast<size_t >(_settings.volume / 10));
            }
            break;
        }
        case 1: {
            if (_settings.difficulty == indie::IA_LEVEL::IA_HARD) {
                _settings.difficulty = indie::IA_LEVEL::IA_MEDIUM;
                _components.at(3)->setBackgroundPos(static_cast<size_t >(_settings.difficulty));
            }
            break;
        }
        case 2: {
            _hasTransition = true;
            _rev = true;
            _indexPaths = 1;
            _sounds.push_back(indie::Sound(indie::SoundId::SOUND_TURN_PAGE));
            loadComponents((_gameState = indie::GameState::MAIN_MENU));
        }
        default:
            break;
    }
}

void indie::GUI::settMenuKeyEnter() {
    if (_posBackground == 2)
    {
        _hasTransition = true;
        _rev = true;
        _indexPaths = 1;
        _sounds.push_back(indie::Sound(indie::SoundId::SOUND_TURN_PAGE));
        loadComponents((_gameState = indie::GameState::MAIN_MENU));
    }
}