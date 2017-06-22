#include "Game/Game.hpp"


std::unique_ptr<std::vector<std::unique_ptr<indie::ISprite> > > indie::Game::getSpritesToLoad() const {
  return (std::move(_gui.getSprites()));
}

std::unique_ptr<std::vector<std::unique_ptr<indie::IModel> > > indie::Game::getModelsToLoad() const {
  std::unique_ptr<std::vector<std::unique_ptr<indie::IModel> > > modelsToLoad;

  modelsToLoad = std::make_unique<std::vector<std::unique_ptr<indie::IModel> > >();
  modelsToLoad->push_back(std::make_unique<indie::Model>("Models/SkeletonMage/SkeletonMage.b3d", std::vector<std::pair<size_t, size_t> >({{1, 36}, {38, 68}, {70, 150}, {152, 175}, {177, 252}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Map/Box.md3", std::vector<std::pair<size_t, size_t> >({{0, 0}, {1, 25}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/1/Square_Explosion.md3", std::vector<std::pair<size_t, size_t> >({{1, 66}, {67, 82}, {83, 84}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/2/Pikes_1.md3", std::vector<std::pair<size_t, size_t> >({{1, 48}, {49, 64}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/2/Pikes_2.md3", std::vector<std::pair<size_t, size_t> >({{1, 48}, {49, 64}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/2/Pikes_3.md3", std::vector<std::pair<size_t, size_t> >({{1, 48}, {49, 64}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/2/Pikes_4.md3", std::vector<std::pair<size_t, size_t> >({{1, 48}, {49, 64}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/2/Pikes_Center.md3", std::vector<std::pair<size_t, size_t> >({{1, 48}, {49, 64}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/3/Tentacle_1.md3", std::vector<std::pair<size_t, size_t> >({{1, 51}, {52, 68}, {69, 85}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/3/Tentacle_2.md3", std::vector<std::pair<size_t, size_t> >({{1, 51}, {52, 68}, {69, 85}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/3/Tentacle_3.md3", std::vector<std::pair<size_t, size_t> >({{1, 51}, {52, 68}, {69, 85}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/3/Tentacle_4.md3", std::vector<std::pair<size_t, size_t> >({{1, 51}, {52, 68}, {69, 85}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/3/Tentacle_5.md3", std::vector<std::pair<size_t, size_t> >({{1, 51}, {52, 68}, {69, 85}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/3/Tentacle_6.md3", std::vector<std::pair<size_t, size_t> >({{1, 51}, {52, 68}, {69, 85}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Explosions/3/Portal.md3", std::vector<std::pair<size_t, size_t> >({{1, 51}, {52, 68}, {69, 79}, {80, 85}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("Map/falling_stone.md3", std::vector<std::pair<size_t, size_t> >({{1, 18}, {19, 47}, {47, 47}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("PowerUps/Grimoire.obj", std::vector<std::pair<size_t, size_t> >({{0, 0}})));
  modelsToLoad->push_back(std::make_unique<indie::Model>("PowerUps/Statuette.obj", std::vector<std::pair<size_t, size_t> >({{0, 0}})));
  return std::move(modelsToLoad);
}

std::unique_ptr<std::vector<std::pair<std::string, indie::SoundType> > > indie::Game::getSoundsToLoad() const {
  std::unique_ptr<std::vector<std::pair<std::string, indie::SoundType> > > soundsToLoad;

  soundsToLoad = std::make_unique<std::vector<std::pair<std::string, indie::SoundType> > >();
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/Music/Beyond_retrieval_-_Menu.flac", indie::SoundType::MUSIC));
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/Music/Drowning_-_Game.flac", indie::SoundType::MUSIC));
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/Music/Innocence_Mangled_-_Game.flac", indie::SoundType::MUSIC));
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/Music/Tandava_-_Game.flac", indie::SoundType::MUSIC));
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/SFX/Explosion_1.flac", indie::SoundType::SOUND));
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/SFX/Explosion_2.flac", indie::SoundType::SOUND));
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/SFX/Explosion_3.flac", indie::SoundType::SOUND));
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/SFX/Stones.flac", indie::SoundType::SOUND));
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/SFX/Skeleton_Spawn.flac", indie::SoundType::SOUND));
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/SFX/Skeleton_Die.flac", indie::SoundType::SOUND));
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/SFX/Evil_laugh.flac", indie::SoundType::SOUND));
  soundsToLoad->push_back(std::make_pair<std::string, indie::SoundType>("Sounds/SFX/Turn_page.flac", indie::SoundType::SOUND));
  return std::move(soundsToLoad);
}

std::unique_ptr<std::vector<std::unique_ptr<indie::IScene> > > indie::Game::getScenesToLoad() const {
  std::unique_ptr<std::vector<std::unique_ptr<indie::IScene> > > scenesToLoad;

  scenesToLoad = std::make_unique<std::vector<std::unique_ptr<indie::IScene> > >();
  scenesToLoad->push_back(std::make_unique<indie::Scene>(
    std::vector<std::pair<std::string, std::string > > ({ std::make_pair("Map/bot_right.obj", "Map/bot_right.png"),
                                                          std::make_pair("Map/bot_left.obj", "Map/bot_left.png"),
                                                          std::make_pair("Map/top_left.obj", "Map/top_left.png"),
                                                          std::make_pair("Map/top_right.obj", "Map/top_right.png"),
                                                          std::make_pair("Map/ground.obj", "Map/ground.png"),
                                                          std::make_pair("Map/pillars.obj", "Map/pillars.png")
                                                        }), std::string("Gui/background.png"), -12.5f, 0.0f, 13.5f));
  return std::move(scenesToLoad);
}
