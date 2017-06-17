#include "Common/GUI.hpp"

indie::GUI::GUI(indie::Settings& settings) : _compId(0), _settings(settings), _sprites(), _components(), _loadComps(), _compActions() {

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

void indie::GUI::loadComponents(indie::GameState state) {
    if (_loadComps.find(state) != _loadComps.end())
        _components = _loadComps[state]();
}

std::vector<std::shared_ptr<indie::IComponent>> indie::GUI::loadMenu() {
    std::vector<std::shared_ptr<indie::IComponent>> res;

    _compId = 1;
    ///Load menu components
    res.push_back(createComponent(0, 0.1f, 0.1f, 0.75f, 0.15f, indie::Color::White, indie::Color::Red,
                                   "Bomberman", "Sprites/bombTitle.png"));
    res.push_back(createComponent(1, 0.4f, 0.4f, 0.16f, 0.15f, indie::Color::White, indie::Color::White,
                                  "Play", "Sprites/playButton.png", "Sprites/playButton2.png"));
    res.push_back(createComponent(2, 0.33f, 0.6f, 0.3f, 0.1f, indie::Color::White, indie::Color::White,
                                  "Settings", "Sprites/SettingsButton.png", "Sprites/SettingsButton2.png"));
    res.push_back(createComponent(3, 0.4f, 0.8f, 0.15f, 0.1f, indie::Color::White, indie::Color::White,
                                  "Exit", "Sprites/exitButton.png", "Sprites/exitButton2.png"));

    if (!_compActions.empty())
        _compActions.clear();

    _compActions[indie::KeyboardKey::KB_ARROW_DOWN] = [this](){mainMenuKeyDown();};
    _compActions[indie::KeyboardKey::KB_ARROW_UP] = [this](){mainMenuKeyUp();};
    _compActions[indie::KeyboardKey::KB_ARROW_RIGHT] = [this](){mainMenuKeyRight();};
    _compActions[indie::KeyboardKey::KB_ENTER] = [this](){mainMenuKeyEnter();};

    return (res);
}

void indie::GUI::notifyEvent(const indie::Event &event) {
    if (event.type == indie::EventType::ET_KEYBOARD)
        if (_compActions.find(event.kb_key) != _compActions.end())
            _compActions[event.kb_key]();
}

std::vector<std::shared_ptr<indie::IComponent>> indie::GUI::loadSettings() {
    std::vector<std::shared_ptr<indie::IComponent>> res;

    ///Load Settings components

    return (res);
}

std::vector<std::shared_ptr<indie::IComponent>> indie::GUI::loadScore() {
    std::vector<std::shared_ptr<indie::IComponent>> res;

    ///Load Score components

    return (res);
}

std::vector<std::shared_ptr<indie::IComponent>> indie::GUI::loadRoom() {
    std::vector<std::shared_ptr<indie::IComponent>> res;

    ///Load Room Components

    return (res);
}

std::vector<std::shared_ptr<indie::ISprite> > indie::GUI::getSprites() {
    return (_sprites);
}

void indie::GUI::mainMenuKeyDown() {
    if (_compId + 1 < _components.size())
    {
        for (size_t i = 1; i < _components.size(); ++i)
        {
            if (i == _compId + 1)
                _components.at(i)->setBackgroundPos(1);
            else
                _components.at(i)->setBackgroundPos(0);
        }
        _compId++;
    }
}

void indie::GUI::mainMenuKeyUp() {
    if (_compId - 1 > 1)
    {
        for (size_t i = 1; i < _components.size(); ++i)
        {
            if (i == _compId - 1)
                _components.at(i)->setBackgroundPos(1);
            else
                _components.at(i)->setBackgroundPos(0);
        }
        _compId--;
    }
}

void indie::GUI::mainMenuKeyRight() {
    if (_compId == 1)
        loadComponents(indie::GameState::ROOM);
    if (_compId == 2)
        loadComponents(indie::GameState::SETTINGS);
}

void indie::GUI::mainMenuKeyEnter() {
    if (_compId == 1)
        loadComponents(indie::GameState::ROOM);
    if (_compId == 2)
        loadComponents(indie::GameState::SETTINGS);
}
