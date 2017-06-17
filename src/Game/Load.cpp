#include "Game/Game.hpp"


std::unique_ptr<std::vector<std::unique_ptr<indie::ISprite> > > indie::Game::getSpritesToLoad() const {
  std::unique_ptr<std::vector<std::unique_ptr<indie::ISprite> > >  spritesToLoad;

    spritesToLoad = std::make_unique<std::vector<std::unique_ptr<indie::ISprite> > >();
  /*spritesToLoad[indie::SpriteType::SPRT_BOMBTITLE] =
    std::make_unique<indie::Sprite>(std::vector<std::string>({"Sprites/bombTitle.png"}));
  spritesToLoad[indie::SpriteType::SPRT_EXITBUTTON] =
    std::make_unique<indie::Sprite>(std::vector<std::string>({"Sprites/exitButton.png", "Sprites/exitButton2.png"}));
  spritesToLoad[indie::SpriteType::SPRT_OPTBUTTON] =
  std::make_unique<indie::Sprite>(std::vector<std::string>({"Sprites/optionButton.png", "Sprites/optionButton2.png"}));
  spritesToLoad[indie::SpriteType::SPRT_PLAYBUTTON] =
  std::make_unique<indie::Sprite>(std::vector<std::string>({"Sprites/playButton.png", "Sprites/playButton2.png"}));
  spritesToLoad[indie::SpriteType::SPRT_SETTINGSBUTTON] =
  std::make_unique<indie::Sprite>(std::vector<std::string>({"Sprites/settingsButton.png", "Sprites/settingsButton2.png"}));*/
  return std::move(spritesToLoad);
}

std::unique_ptr<std::vector<std::unique_ptr<indie::IModel> > > indie::Game::getModelsToLoad() const {
  std::unique_ptr<std::vector<std::unique_ptr<indie::IModel> > > modelsToLoad;

  modelsToLoad = std::make_unique<std::vector<std::unique_ptr<indie::IModel> > >();
  (*modelsToLoad).push_back(std::make_unique<indie::Model>("Models/SkeletonMage/SkeletonMage.b3d",
      std::vector<std::pair<size_t, size_t> >(
        {{1, 36}, {38, 68}, {70, 150}, {152, 175}, {177, 252}})
    ));

  (*modelsToLoad).push_back(std::make_unique<indie::Model>("Map/Box.md3",
      std::vector<std::pair<size_t, size_t> >(
        {{0, 0}, {1, 25}})
    ));
  return std::move(modelsToLoad);
}

std::unique_ptr<std::vector<std::pair<std::string, indie::SoundType> > > indie::Game::getSoundsToLoad() const {
  std::unique_ptr<std::vector<std::pair<std::string, indie::SoundType> > > soundsToLoad;

  return std::move(soundsToLoad);
}

std::unique_ptr<std::vector<std::unique_ptr<indie::IScene> > > indie::Game::getScenesToLoad() const {
  std::unique_ptr<std::vector<std::unique_ptr<indie::IScene> > > scenesToLoad;

  scenesToLoad = std::make_unique<std::vector<std::unique_ptr<indie::IScene> > >();
  (*scenesToLoad).push_back(std::make_unique<indie::Scene>(
    std::vector<std::pair<std::string, std::string > > ({ std::make_pair("Map/bot_right.obj", "Map/bot_right.png"),
                                                          std::make_pair("Map/bot_left.obj", "Map/bot_left.png"),
                                                          std::make_pair("Map/top_left.obj", "Map/top_left.png"),
                                                          std::make_pair("Map/top_right.obj", "Map/top_right.png"),
                                                          std::make_pair("Map/ground.obj", "Map/ground.png"),
                                                          std::make_pair("Map/pillars.obj", "Map/pillars.png")
                                                        }), std::string("Textures/Dome/Hole.jpg"), -12.5f, 0.0f, 13.5f));
  return std::move(scenesToLoad);
}
