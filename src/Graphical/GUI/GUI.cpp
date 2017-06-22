#include "Common/GUI.hpp"

indie::GUI::GUI(indie::Settings& settings, indie::GameState& state) : _posBackground(0), _nbPlayersH(0),
                                                                      _nbPlayersAI(0), _indexPaths(0),
                                                                      _hasTransition(false), _rev(false),
                                                                      _settings(settings), _gameState(state), _components(),
                                                                      _loadComps(), _compActions(),
                                                                      _sounds(), _transitPaths(),
                                                                      _reversePaths(), _blankVector() {

    _loadComps[indie::GameState::MAIN_MENU] = [this](){return loadMenu();};
    _loadComps[indie::GameState::SETTINGS] = [this](){return loadSettings();};
    _loadComps[indie::GameState::SCOREBOARD] = [this](){return loadScore();};
    _loadComps[indie::GameState::ROOM] = [this](){return loadRoom();};
    _loadComps[indie::GameState::INGAME] = [this](){return loadGuiGame();};
    _loadComps[indie::GameState::ENDGAME] = [this](){return loadEndGame();};
    _loadComps[indie::GameState::PAUSE_GAME] = [this](){return loadPause();};

    _transitPaths = {
                        {    "Menu_final/Transitions/Main_to_HighScores/0002.png",
                             "Menu_final/Transitions/Main_to_HighScores/0003.png",
                             "Menu_final/Transitions/Main_to_HighScores/0004.png",
                             "Menu_final/Transitions/Main_to_HighScores/0005.png",
                             "Menu_final/Transitions/Main_to_HighScores/0006.png",
                             "Menu_final/Transitions/Main_to_HighScores/0007.png",
                             "Menu_final/Transitions/Main_to_HighScores/0008.png",
                             "Menu_final/Transitions/Main_to_HighScores/0009.png",
                             "Menu_final/Transitions/Main_to_HighScores/0010.png",
                             "Menu_final/Transitions/Main_to_HighScores/0011.png",
                             "Menu_final/Transitions/Main_to_HighScores/0012.png",
                             "Menu_final/Transitions/Main_to_HighScores/0013.png",
                             "Menu_final/Transitions/Main_to_HighScores/0014.png",
                             "Menu_final/Transitions/Main_to_HighScores/0015.png",
                             "Menu_final/Transitions/Main_to_HighScores/0016.png",
                             "Menu_final/Transitions/Main_to_HighScores/0017.png",
                             "Menu_final/Transitions/Main_to_HighScores/0018.png",
                             "Menu_final/Transitions/Main_to_HighScores/0019.png",
                             "Menu_final/Transitions/Main_to_HighScores/0020.png",
                             "Menu_final/Transitions/Main_to_HighScores/0021.png",
                             "Menu_final/Transitions/Main_to_HighScores/0022.png",
                             "Menu_final/Transitions/Main_to_HighScores/0023.png",
                             "Menu_final/Transitions/Main_to_HighScores/0024.png",
                             "Menu_final/Transitions/Main_to_HighScores/0025.png",
                             "Menu_final/Transitions/Main_to_HighScores/0026.png",
                             "Menu_final/Transitions/Main_to_HighScores/0027.png",
                             "Menu_final/Transitions/Main_to_HighScores/0028.png",
                             "Menu_final/Transitions/Main_to_HighScores/0029.png",
                             "Menu_final/Transitions/Main_to_HighScores/0030.png",
                             "Menu_final/Transitions/Main_to_HighScores/0031.png",
                             "Menu_final/Transitions/Main_to_HighScores/0032.png",
                             "Menu_final/Transitions/Main_to_HighScores/0033.png",
                             "Menu_final/Transitions/Main_to_HighScores/0034.png",
                             "Menu_final/Transitions/Main_to_HighScores/0035.png",
                             "Menu_final/Transitions/Main_to_HighScores/0036.png",
                             "Menu_final/Transitions/Main_to_HighScores/0037.png",
                             "Menu_final/Transitions/Main_to_HighScores/0038.png",
                             "Menu_final/Transitions/Main_to_HighScores/0039.png",
                             "Menu_final/Transitions/Main_to_HighScores/0040.png"},

                     {
                             "Menu_final/Transitions/Main_to_Settings/0002.png",
                             "Menu_final/Transitions/Main_to_Settings/0003.png",
                             "Menu_final/Transitions/Main_to_Settings/0004.png",
                             "Menu_final/Transitions/Main_to_Settings/0005.png",
                             "Menu_final/Transitions/Main_to_Settings/0006.png",
                             "Menu_final/Transitions/Main_to_Settings/0007.png",
                             "Menu_final/Transitions/Main_to_Settings/0008.png",
                             "Menu_final/Transitions/Main_to_Settings/0009.png",
                             "Menu_final/Transitions/Main_to_Settings/0010.png",
                             "Menu_final/Transitions/Main_to_Settings/0011.png",
                             "Menu_final/Transitions/Main_to_Settings/0012.png",
                             "Menu_final/Transitions/Main_to_Settings/0013.png",
                             "Menu_final/Transitions/Main_to_Settings/0014.png",
                             "Menu_final/Transitions/Main_to_Settings/0015.png",
                             "Menu_final/Transitions/Main_to_Settings/0016.png",
                             "Menu_final/Transitions/Main_to_Settings/0017.png",
                             "Menu_final/Transitions/Main_to_Settings/0018.png",
                             "Menu_final/Transitions/Main_to_Settings/0019.png",
                             "Menu_final/Transitions/Main_to_Settings/0020.png",
                             "Menu_final/Transitions/Main_to_Settings/0021.png",
                             "Menu_final/Transitions/Main_to_Settings/0022.png",
                             "Menu_final/Transitions/Main_to_Settings/0023.png",
                             "Menu_final/Transitions/Main_to_Settings/0024.png",
                             "Menu_final/Transitions/Main_to_Settings/0025.png",
                             "Menu_final/Transitions/Main_to_Settings/0026.png",
                             "Menu_final/Transitions/Main_to_Settings/0027.png",
                             "Menu_final/Transitions/Main_to_Settings/0028.png",
                             "Menu_final/Transitions/Main_to_Settings/0029.png",
                             "Menu_final/Transitions/Main_to_Settings/0030.png",
                             "Menu_final/Transitions/Main_to_Settings/0031.png",
                             "Menu_final/Transitions/Main_to_Settings/0032.png",
                             "Menu_final/Transitions/Main_to_Settings/0033.png",
                             "Menu_final/Transitions/Main_to_Settings/0034.png",
                             "Menu_final/Transitions/Main_to_Settings/0035.png",
                             "Menu_final/Transitions/Main_to_Settings/0036.png",
                             "Menu_final/Transitions/Main_to_Settings/0037.png",
                             "Menu_final/Transitions/Main_to_Settings/0038.png",
                             "Menu_final/Transitions/Main_to_Settings/0039.png",
                             "Menu_final/Transitions/Main_to_Settings/0040.png"},

                     {
                             "Menu_final/Transitions/Main_to_Room/0002.png",
                             "Menu_final/Transitions/Main_to_Room/0003.png",
                             "Menu_final/Transitions/Main_to_Room/0004.png",
                             "Menu_final/Transitions/Main_to_Room/0005.png",
                             "Menu_final/Transitions/Main_to_Room/0006.png",
                             "Menu_final/Transitions/Main_to_Room/0007.png",
                             "Menu_final/Transitions/Main_to_Room/0008.png",
                             "Menu_final/Transitions/Main_to_Room/0009.png",
                             "Menu_final/Transitions/Main_to_Room/0010.png",
                             "Menu_final/Transitions/Main_to_Room/0011.png",
                             "Menu_final/Transitions/Main_to_Room/0012.png",
                             "Menu_final/Transitions/Main_to_Room/0013.png",
                             "Menu_final/Transitions/Main_to_Room/0014.png",
                             "Menu_final/Transitions/Main_to_Room/0015.png",
                             "Menu_final/Transitions/Main_to_Room/0016.png",
                             "Menu_final/Transitions/Main_to_Room/0017.png",
                             "Menu_final/Transitions/Main_to_Room/0018.png",
                             "Menu_final/Transitions/Main_to_Room/0019.png",
                             "Menu_final/Transitions/Main_to_Room/0020.png",
                             "Menu_final/Transitions/Main_to_Room/0021.png",
                             "Menu_final/Transitions/Main_to_Room/0022.png",
                             "Menu_final/Transitions/Main_to_Room/0023.png",
                             "Menu_final/Transitions/Main_to_Room/0024.png",
                             "Menu_final/Transitions/Main_to_Room/0025.png",
                             "Menu_final/Transitions/Main_to_Room/0026.png",
                             "Menu_final/Transitions/Main_to_Room/0027.png",
                             "Menu_final/Transitions/Main_to_Room/0028.png",
                             "Menu_final/Transitions/Main_to_Room/0029.png",
                             "Menu_final/Transitions/Main_to_Room/0030.png",
                             "Menu_final/Transitions/Main_to_Room/0031.png",
                             "Menu_final/Transitions/Main_to_Room/0032.png",
                             "Menu_final/Transitions/Main_to_Room/0033.png",
                             "Menu_final/Transitions/Main_to_Room/0034.png",
                             "Menu_final/Transitions/Main_to_Room/0035.png",
                             "Menu_final/Transitions/Main_to_Room/0036.png",
                             "Menu_final/Transitions/Main_to_Room/0037.png",
                             "Menu_final/Transitions/Main_to_Room/0038.png",
                             "Menu_final/Transitions/Main_to_Room/0039.png",
                             "Menu_final/Transitions/Main_to_Room/0040.png"
                        }
    };

    _sounds.push_back(indie::Sound(indie::SoundId::SOUND_MENU));
    _settings.music = Sound(indie::SoundId::SOUND_MENU);
    revPaths();
}

std::unique_ptr<std::vector<std::unique_ptr<indie::ISprite> > > indie::GUI::getSprites() const {
    std::unique_ptr<std::vector<std::unique_ptr<indie::ISprite> > > sprites;

    sprites = std::make_unique<std::vector<std::unique_ptr<indie::ISprite> > >();
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/MAIN/base.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/arrow.png", "Menu_final/arrow-rev.png",
                                                         "Menu_final/arrow-down.png", "Menu_final/arrow-upleft.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/SETTINGS/base.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/SETTINGS/sound_0.png",
                                                         "Menu_final/SETTINGS/sound_1.png",
                                                         "Menu_final/SETTINGS/sound_2.png",
                                                         "Menu_final/SETTINGS/sound_3.png",
                                                         "Menu_final/SETTINGS/sound_4.png",
                                                         "Menu_final/SETTINGS/sound_5.png",
                                                         "Menu_final/SETTINGS/sound_6.png",
                                                         "Menu_final/SETTINGS/sound_7.png",
                                                         "Menu_final/SETTINGS/sound_8.png",
                                                         "Menu_final/SETTINGS/sound_9.png",
                                                         "Menu_final/SETTINGS/sound_10.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/SETTINGS/AI_normal.png",
                                                         "Menu_final/SETTINGS/AI_hard.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/ROOM/room_base.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/HIGHSCORES/base.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/NUMBERS/0_black.png",
                                                         "Menu_final/NUMBERS/1_black.png",
                                                         "Menu_final/NUMBERS/2_black.png",
                                                         "Menu_final/NUMBERS/3_black.png",
                                                         "Menu_final/NUMBERS/4_black.png",
                                                         "Menu_final/NUMBERS/5_black.png",
                                                         "Menu_final/NUMBERS/6_black.png",
                                                         "Menu_final/NUMBERS/7_black.png",
                                                         "Menu_final/NUMBERS/8_black.png",
                                                         "Menu_final/NUMBERS/9_black.png",
                                                         "Menu_final/NUMBERS/dot_black.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Gui/blue_alive.png",
                                                         "Gui/blue_dead.png",
                                                         "Gui/red_alive.png",
                                                         "Gui/red_dead.png",
                                                         "Gui/yellow_alive.png",
                                                         "Gui/yellow_dead.png",
                                                         "Gui/green_alive.png",
                                                         "Gui/green_dead.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/VICTORY_SCREEN/blue.png",
                                                         "Menu_final/VICTORY_SCREEN/red.png",
                                                         "Menu_final/VICTORY_SCREEN/yellow.png",
                                                         "Menu_final/VICTORY_SCREEN/green.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/INGAME/background.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/INGAME/pause.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Explosions/1/Square_Explosion.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Explosions/2/Pikes_1.png",
                                                         "Explosions/2/Pikes_2.png",
                                                         "Explosions/2/Pikes_3.png",
                                                         "Explosions/2/Pikes_4.png",
                                                         "Explosions/2/Pikes_Center.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Explosions/3/Portal.png", "Explosions/3/Tentacle.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("PowerUps/Grimoire.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("PowerUps/Grimoire_tex.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("PowerUps/Statuette.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("PowerUps/Statuette_tex.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Textures/SkeletonMage/Blue.png",
                                                         "Textures/SkeletonMage/Green.png",
                                                         "Textures/SkeletonMage/Red.png",
                                                         "Textures/SkeletonMage/Yellow.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/SETTINGS/transp_sound_0.png",
                                                         "Menu_final/SETTINGS/transp_sound_1.png",
                                                         "Menu_final/SETTINGS/transp_sound_2.png",
                                                         "Menu_final/SETTINGS/transp_sound_3.png",
                                                         "Menu_final/SETTINGS/transp_sound_4.png",
                                                         "Menu_final/SETTINGS/transp_sound_5.png",
                                                         "Menu_final/SETTINGS/transp_sound_6.png",
                                                         "Menu_final/SETTINGS/transp_sound_7.png",
                                                         "Menu_final/SETTINGS/transp_sound_8.png",
                                                         "Menu_final/SETTINGS/transp_sound_9.png",
                                                         "Menu_final/SETTINGS/transp_sound_10.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>( "Gui/grimoire_blue.png",
                                                          "Gui/statuette_blue.png",
                                                          "Gui/grimoire_red.png",
                                                          "Gui/statuette_red.png",
                                                          "Gui/grimoire_yellow.png",
                                                          "Gui/statuette_yellow.png",
                                                          "Gui/grimoire_green.png",
                                                          "Gui/statuette_green.png",
                                                          "Gui/blank.png"));
    (*sprites).push_back(std::make_unique<indie::Sprite>("Menu_final/NUMBERS/0_white.png",
                                                         "Menu_final/NUMBERS/1_white.png",
                                                         "Menu_final/NUMBERS/2_white.png",
                                                         "Menu_final/NUMBERS/3_white.png",
                                                         "Menu_final/NUMBERS/4_white.png",
                                                         "Menu_final/NUMBERS/5_white.png",
                                                         "Menu_final/NUMBERS/6_white.png",
                                                         "Menu_final/NUMBERS/7_white.png",
                                                         "Menu_final/NUMBERS/8_white.png",
                                                         "Menu_final/NUMBERS/9_white.png",
                                                         "Menu_final/NUMBERS/ddot_white.png"));

    return (std::move(sprites));
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

void indie::GUI::notifyEvent(const indie::Event &event) {
    if (event.type == indie::EventType::ET_KEYBOARD)
    {
        if (_compActions.find(event.kb_key) != _compActions.end())
            _compActions[event.kb_key]();
    }
}

std::vector<indie::Sound> &indie::GUI::getSounds() {
    return (_sounds);
}

const std::vector<std::string> &indie::GUI::getTransitPaths() const {
    if (_hasTransition)
    {
        if (_rev)
            return (_reversePaths.at(_indexPaths));
        else
            return (_transitPaths.at(_indexPaths));
    }
    return (_blankVector);
}

void indie::GUI::revPaths() {
    std::vector<std::string> tmp;
    for (size_t i = 0; i < _transitPaths.size(); ++i)
    {
        tmp = _transitPaths.at(i);
        std::reverse(tmp.begin(), tmp.end());
        _reversePaths.push_back(tmp);
    }
}

void indie::GUI::flushGUI() {
    if (_gameState == indie::GameState::INGAME)
        updatePlayersStat();
    _hasTransition = false;
}

void indie::GUI::updateTimer(int time, int i) {
    int nb = time;
    int j = i - 2;
    while (nb > 0)
    {
        _components.at(i)->setBackgroundPos(nb%10);
        nb /= 10;
        i--;
    }
    if (i != j && nb == 0)
        _components.at(i)->setBackgroundPos(nb);
}