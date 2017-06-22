#include "Common/GUI.hpp"

std::vector<std::unique_ptr<indie::IComponent>> indie::GUI::loadScore() {
    std::vector<std::unique_ptr<indie::IComponent>> res;
    std::unique_ptr<indie::Score> score = std::make_unique<indie::Score>();
    double  y;
    double  height;

    _posBackground = 0;

    ///Load Score components


    std::vector<int> scores = score->GetScores();
    std::vector<std::string> dates = score->GetDates();

    res.push_back(createComponent(SpriteId::SCORE_MENU , 0.0f, 0.0f, 1.0f, 1.0f, indie::Color::White, indie::Color::White));
    y = 0.365f;
    height = 0.39f;
    for(std::vector<int>::iterator i = scores.begin(); i != scores.end(); ++i)
    {
        getTabNumber(res, std::to_string(*i), 0.52f, y, 0.55f, height, 0.025f);
        y += 0.1;
        height += 0.1;
    }
    y = 0.365f;
    height = 0.39f;
     for(std::vector<std::string>::iterator i = dates.begin(); i != dates.end();++i)
    {
        getTabDates(res, *i, 0.635f, y, 0.65f, height);
        y += 0.1;
        height += 0.1;
    }

    if (!_compActions.empty())
        _compActions.clear();

    _compActions[indie::KeyboardKey::KB_ENTER] = [this](){scoreMenuKeyEnter();};
    _compActions[indie::KeyboardKey::KB_ARROW_LEFT] = [this](){scoreMenuKeyEnter();};

    return (res);
}


void    indie::GUI::getTabNumber(std::vector<std::unique_ptr<indie::IComponent>> &res, std::string score, double x, double y, double width, double height, double space)
{
    int nb;
    double  pos_x;

    pos_x = x;
    for (int i = 0; score[i] != '\0'; ++i)
    {
        nb = score[i] - 48;
        res.push_back(createComponent(SpriteId::NUMBER , pos_x, y, width, height, indie::Color::White, indie::Color::White));
        res.at(res.size() - 1)->setBackgroundPos(nb);
        pos_x += space;
        width += space;
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
            nb = score[i] - 48;
        else
            nb = 10;
        res.push_back(createComponent(SpriteId::NUMBER, pos_x, y, width, height, indie::Color::White, indie::Color::White));
        res.at(res.size() - 1)->setBackgroundPos(nb);
        pos_x += 0.012;
        width += 0.012;
    }
}

void indie::GUI::scoreMenuKeyEnter() {
    _indexPaths = 0;
    _rev = true;
    _hasTransition = true;
    _sounds.push_back(indie::Sound(indie::SoundId::SOUND_TURN_PAGE));
    _gameState = indie::GameState::MAIN_MENU;
    loadComponents(_gameState);
}