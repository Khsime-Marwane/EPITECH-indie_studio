#include "Common/GUI.hpp"

std::vector<std::unique_ptr<indie::IComponent>> indie::GUI::loadGuiGame() {
    std::vector<std::unique_ptr<indie::IComponent>> res;

    _posBackground = 0;
    size_t  nb_players = 1;

//bleu, rouge, jaune, vert
    while (nb_players <= _settings.nPlayers + _settings.nAIs)
    {
        switch (nb_players)
        {
            case 1: {
                res.push_back(createComponent(SpriteId::PLAYER_ICON, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
                break;
            }
            case 2: {
                res.push_back(createComponent(SpriteId::PLAYER_ICON, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
                res.at(res.size() - 1)->setBackgroundPos(2);
                break;
            }
            case 3: {
                res.push_back(createComponent(SpriteId::PLAYER_ICON, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
                res.at(res.size() - 1)->setBackgroundPos(4);
                break;
            }
            case 4: {
                res.push_back(createComponent(SpriteId::PLAYER_ICON, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
                res.at(res.size() - 1)->setBackgroundPos(6);
                break;
            }
            default:
                break;
        }
        ++nb_players;
    }

    for (int i = 0; i < 4; ++i)
    {
        res.push_back(createComponent(SpriteId::BONUS_PLAYER,0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
        res.at(res.size() - 1)->setBackgroundPos(8);
    }

    res.push_back(createComponent(SpriteId::WHITE_NUMBERS, 0.36f, 0.01f, 0.42f, 0.07f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::WHITE_NUMBERS, 0.41f, 0.01f, 0.47f, 0.07f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::WHITE_NUMBERS, 0.47f, 0.0f, 0.5f, 0.07f, indie::Color::White, indie::Color::White));
    res.at(res.size() - 1)->setBackgroundPos(10);
    res.push_back(createComponent(SpriteId::WHITE_NUMBERS, 0.5f, 0.01f, 0.56f, 0.07f, indie::Color::White, indie::Color::White));
    res.push_back(createComponent(SpriteId::WHITE_NUMBERS, 0.55f, 0.01f, 0.61f, 0.07f, indie::Color::White, indie::Color::White));

    if (!_compActions.empty())
        _compActions.clear();

    _compActions[indie::KeyboardKey::KB_P] = [this](){loadComponents((_gameState = indie::GameState::PAUSE_GAME));};
    _compActions[indie::KeyboardKey::KB_ESCAPE] = [this](){loadComponents((_gameState = indie::GameState::PAUSE_GAME));};
    return (res);
}

std::vector<std::unique_ptr<indie::IComponent>> indie::GUI::loadEndGame() {
    std::vector<std::unique_ptr<indie::IComponent>> res;
    std::unique_ptr<indie::Score> score = std::make_unique<indie::Score>();

    ///Load end game Components
    int _winner = 0;
    int _score  = 0;

    for (std::vector<std::unique_ptr<indie::Player>>::const_iterator i = _settings.players.begin(); i != _settings.players.end(); ++i)
    {
        if ((*i)->isAlive())
        {
            _score = (*i)->getScore();
            break;
        }
        _winner++;
    }


    res.push_back(createComponent(SpriteId::INGAME_MENU1, 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
    switch (_winner)
    {
        case 0: {
            res.push_back(createComponent(SpriteId::ENDGAME_MENU, 0.3f, 0.07f, 0.7f, 0.95f, indie::Color::White, indie::Color::White));
            res.at(0)->setBackgroundPos(0);
            break;
        }
        case 1: {
            res.push_back(createComponent(SpriteId::ENDGAME_MENU, 0.3f, 0.07f, 0.7f, 0.95f, indie::Color::White, indie::Color::White));
            res.at(res.size() - 1)->setBackgroundPos(1);
            break;
        }
        case 2: {
            res.push_back(createComponent(SpriteId::ENDGAME_MENU, 0.3f, 0.07f, 0.7f, 0.95f, indie::Color::White, indie::Color::White));
            res.at(res.size() - 1)->setBackgroundPos(2);
            break;
        }
        case 3: {
            res.push_back(createComponent(SpriteId::ENDGAME_MENU, 0.3f, 0.07f, 0.7f, 0.95f, indie::Color::White, indie::Color::White));
            res.at(res.size() - 1)->setBackgroundPos(3);
            break;
        }
        default:
            break;
    }
    getTabNumber(res, std::to_string(_score), 0.45f, 0.68f, 0.5f, 0.72f, 0.05f);
    score->add_score(_score);

    if (!_compActions.empty())
        _compActions.clear();

    _compActions[indie::KeyboardKey::KB_ENTER] = [this](){endGameMenuKeyEnter();};

    return (res);
}

void    indie::GUI::updatePlayersStat()
{
    for (size_t i = 0; i < _settings.players.size(); ++i)
    {
        if (_settings.players.at(i)->isAlive())
            _components.at(i)->setBackgroundPos(i * 2);
        else
            _components.at(i)->setBackgroundPos(i * 2 + 1);

        if (_settings.players.at(i)->getBombType() == indie::OBJECTS_ID::TENTACLEBOMB)
            _components.at(i + _settings.players.size())->setBackgroundPos(i * 2 + 1);
        else if (_settings.players.at(i)->getBombType() == indie::OBJECTS_ID::SQUAREBOMB)
            _components.at(i + _settings.players.size())->setBackgroundPos(i * 2);
        else
            _components.at(i + _settings.players.size())->setBackgroundPos(8);
    }
    int sec = static_cast<int>((_settings.timer.Elapsed().count()/1000) % 60);
    int min = static_cast<int>((_settings.timer.Elapsed().count()/60000) % 60);
    updateTimer(sec, static_cast<int>(_settings.players.size() + 8));
    updateTimer(min, static_cast<int>(_settings.players.size() + 5));
}

void    indie::GUI::endGameMenuKeyEnter()
{
    _sounds.push_back(indie::Sound(_settings.music.id, indie::SoundAction::STOP));
    _sounds.push_back(indie::Sound(indie::SoundId::SOUND_MENU));
    _settings.music = Sound(indie::Sound(indie::SoundId::SOUND_MENU));
    _gameState = indie::GameState::MAIN_MENU;
    loadComponents(_gameState);
}