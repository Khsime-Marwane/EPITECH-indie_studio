#include "Common/GUI.hpp"


std::vector<std::unique_ptr<indie::IComponent>> indie::GUI::loadPause() {
    std::vector<std::unique_ptr<indie::IComponent>> res;

    _posBackground = 0;
    ///Load Room Components
    res.push_back(createComponent(SpriteId::INGAME_MENU1, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::INGAME_MENU2, 0.29f, 0.1f, 0.7f, 0.9f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::TRANSP_SOUND, 0.34f, 0.6f, 0.65f, 0.65f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::ARROW, 0.42f, 0.53f, 0.46f, 0.58f, indie::Color::White, indie::Color::White));

    res.at(2)->setBackgroundPos(static_cast<size_t>(_settings.volume / 10));

    if (!_compActions.empty())
        _compActions.clear();

    _compActions[indie::KeyboardKey::KB_ARROW_DOWN] = [this](){pauseMenuKeyDown();};
    _compActions[indie::KeyboardKey::KB_ARROW_UP] = [this](){pauseMenuKeyUp();};
    _compActions[indie::KeyboardKey::KB_ARROW_RIGHT] = [this](){pauseMenukeyRight();};
    _compActions[indie::KeyboardKey::KB_ARROW_LEFT] = [this](){pauseMenuKeyLeft();};
    _compActions[indie::KeyboardKey::KB_ENTER] = [this](){pauseMenuKeyEnter();};

    return (res);
}

void indie::GUI::pauseMenuKeyDown() {
    switch (_posBackground)
    {
        case 0:  _components.at(3)->setPos(0.42f, 0.67f, 0.46f, 0.72f);
            break;
        case 1: _components.at(3)->setPos(0.39f, 0.755f, 0.43f, 0.805f);
            break;
        default:
            break;
    }
    if (_posBackground + 1 < 3)
        ++_posBackground;
}

void indie::GUI::pauseMenuKeyUp() {
    switch (_posBackground)
    {
        case 1: _components.at(3)->setPos(0.42f, 0.53f, 0.46f, 0.58f);
            break;
        case 2: _components.at(3)->setPos(0.42f, 0.67f, 0.46f, 0.72f);
            break;
        default:
            break;
    }
    if (_posBackground > 0)
        --_posBackground;
}

void indie::GUI::pauseMenukeyRight() {
    if ((_posBackground == 0) && (_settings.volume + 10 <= 100))
    {
        _settings.volume += 10;
        _components.at(2)->setBackgroundPos(static_cast<size_t >(_settings.volume / 10));
    }
}

void indie::GUI::pauseMenuKeyLeft() {
    if ((_posBackground == 0) && (_settings.volume - 10 >= 0))
    {
        _settings.volume -= 10;
        _components.at(2)->setBackgroundPos(static_cast<size_t >(_settings.volume / 10));
    }
}

void indie::GUI::pauseMenuKeyEnter() {
    if (_posBackground == 1)
        loadComponents((_gameState = indie::GameState::INGAME));
    if (_posBackground == 2)
    {
        _sounds.push_back(indie::Sound(_settings.music.id, indie::SoundAction::STOP));
        _sounds.push_back(indie::Sound(indie::SoundId::SOUND_MENU));
        _settings.music = Sound(indie::Sound(indie::SoundId::SOUND_MENU));
        loadComponents((_gameState = indie::GameState::MAIN_MENU));
    }
}