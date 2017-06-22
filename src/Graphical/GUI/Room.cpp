#include "Common/GUI.hpp"

std::vector<std::unique_ptr<indie::IComponent>> indie::GUI::loadRoom() {
    std::vector<std::unique_ptr<indie::IComponent>> res;

    ///Load Room Components

    _nbPlayersH = 1;
    _nbPlayersAI = 1;
    _settings.nPlayers = _nbPlayersH;
    _settings.nAIs = _nbPlayersAI;

    res.push_back(createComponent(SpriteId::ROOM_MENU, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::ARROW, 0.53f, 0.35f, 0.57f, 0.4f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::NUMBER, 0.63f, 0.36f, 0.66f, 0.39f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::NUMBER, 0.63f, 0.4f, 0.66f, 0.43f, indie::Color::White, indie::Color::White));

    res.at(2)->setBackgroundPos(_nbPlayersH);
    res.at(3)->setBackgroundPos(_nbPlayersAI);

    if (!_compActions.empty())
        _compActions.clear();

    _compActions[indie::KeyboardKey::KB_ARROW_DOWN] = [this](){roomMenuKeyDown();};
    _compActions[indie::KeyboardKey::KB_ARROW_UP] = [this](){roomMenuKeyUp();};
    _compActions[indie::KeyboardKey::KB_ARROW_RIGHT] = [this](){roomMenuKeyRight();};
    _compActions[indie::KeyboardKey::KB_ARROW_LEFT] = [this](){roomMenuKeyLeft();};
    _compActions[indie::KeyboardKey::KB_ENTER] = [this](){roomMenuKeyEnter();};

    return (res);
}

void indie::GUI::roomMenuKeyDown() {
    switch (_posBackground)
    {
        case 0: _components.at(1)->setPos(0.53f, 0.39f, 0.57f, 0.44f);
            break;
        case 1: {
            _components.at(1)->setPos(0.57f, 0.67f, 0.61f, 0.72f);
            _components.at(1)->setBackgroundPos(1);
            break;
        }
        case 2: {
            _components.at(1)->setPos(0.66f, 0.82f, 0.7f, 0.87f);
            _components.at(1)->setBackgroundPos(3);
            break;
        }
        default:
            break;
    }
    if (_posBackground + 1 < 4)
        ++_posBackground;
}

void indie::GUI::roomMenuKeyUp() {
    switch (_posBackground)
    {
        case 1: {
            _components.at(1)->setPos(0.53f, 0.35f, 0.57f, 0.4f);
            _components.at(1)->setBackgroundPos(0);
            break;
        }
        case 2: {
            _components.at(1)->setPos(0.53f, 0.39f, 0.57f, 0.44f);
            _components.at(1)->setBackgroundPos(0);
            break;
        }
        case 3: {
            _components.at(1)->setPos(0.57f, 0.67f, 0.61f, 0.72f);
            _components.at(1)->setBackgroundPos(1);
            break;
        }
        default:
            break;
    }
    if (_posBackground > 0)
        --_posBackground;
}

void indie::GUI::roomMenuKeyRight() {
    switch (_posBackground)
    {
        case 0: {
            if (_nbPlayersH + 1 < 5)
                _components.at(2)->setBackgroundPos(++_nbPlayersH);
            if (_nbPlayersH + _nbPlayersAI > 4)
                _components.at(3)->setBackgroundPos(--_nbPlayersAI);
            break;
        }
        case 1: {
            if (_nbPlayersAI + 1 < 5)
                _components.at(3)->setBackgroundPos(++_nbPlayersAI);
            if (_nbPlayersAI + _nbPlayersH > 4)
                _components.at(2)->setBackgroundPos(--_nbPlayersH);
        }
        default:
            break;
    }
    _settings.nPlayers = _nbPlayersH;
    _settings.nAIs = _nbPlayersAI;
}

void indie::GUI::roomMenuKeyLeft() {
    switch (_posBackground)
    {
        case 0: {
            if (_nbPlayersH > 1)
                _components.at(2)->setBackgroundPos(--_nbPlayersH);
            if (_nbPlayersH && !_nbPlayersAI)
                _components.at(3)->setBackgroundPos(++_nbPlayersAI);
            break;
        }
        case 1: {
            if ((_nbPlayersAI + _nbPlayersH > _nbPlayersH))
                _components.at(3)->setBackgroundPos(--_nbPlayersAI);
            if (_nbPlayersH == 1)
                _components.at(3)->setBackgroundPos((_nbPlayersAI = 1));
            break;
        }
        case 2: {
            _indexPaths = 2;
            _rev = true;
            _hasTransition = true;
            _sounds.push_back(indie::Sound(indie::SoundId::SOUND_TURN_PAGE));
            loadComponents((_gameState = indie::GameState::MAIN_MENU));
        }
        default:
            break;
    }
    _settings.nPlayers = _nbPlayersH;
    _settings.nAIs = _nbPlayersAI;
}

void indie::GUI::roomMenuKeyEnter() {
    if (_posBackground == 2)
    {
        _indexPaths = 2;
        _rev = true;
        _hasTransition = true;
        _sounds.push_back(indie::Sound(indie::SoundId::SOUND_TURN_PAGE));
        loadComponents((_gameState = indie::GameState::MAIN_MENU));
    }
    if (_posBackground == 3)
    {
        _sounds.push_back(indie::Sound(indie::SoundId::SOUND_MENU, indie::SoundAction::STOP));
        _settings.music = Sound(static_cast<indie::SoundId >(rand() % 3));
        _sounds.push_back(_settings.music);
        loadComponents((_gameState = indie::GameState::INGAME));
    }
}
