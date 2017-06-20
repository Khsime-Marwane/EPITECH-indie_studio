#include "Game/ResourceHandler.hpp"

std::string indie::ResourceHandler::getTexture(indie::MODELS_ID model) {
  static std::map<indie::MODELS_ID, std::string> textures = {
    { indie::MODELS_ID::BOX_MODEL, "Map/Box.png" },
    { indie::MODELS_ID::SQUAREBOMB_MODEL, "Explosions/1/Square_Explosion.png" },
    { indie::MODELS_ID::PIKES_MODEL_1, "Explosions/2/Pikes_1.png" },
    { indie::MODELS_ID::PIKES_MODEL_2, "Explosions/2/Pikes_2.png" },
    { indie::MODELS_ID::PIKES_MODEL_3, "Explosions/2/Pikes_3.png" },
    { indie::MODELS_ID::PIKES_MODEL_4, "Explosions/2/Pikes_4.png" },
    { indie::MODELS_ID::PIKES_MODEL_CENTER, "Explosions/2/Pikes_Center.png" },
    { indie::MODELS_ID::TENTACLE_MODEL_1, "Explosions/3/Tentacle.png" },
    { indie::MODELS_ID::TENTACLE_MODEL_2, "Explosions/3/Tentacle.png" },
    { indie::MODELS_ID::TENTACLE_MODEL_3, "Explosions/3/Tentacle.png" },
    { indie::MODELS_ID::TENTACLE_MODEL_4, "Explosions/3/Tentacle.png" },
    { indie::MODELS_ID::TENTACLE_MODEL_5, "Explosions/3/Tentacle.png" },
    { indie::MODELS_ID::TENTACLE_MODEL_6, "Explosions/3/Tentacle.png" },
    { indie::MODELS_ID::TENTACLE_MODEL_PORTAL, "Explosions/3/Portal.png" },
  };

  if (textures.find(model) != textures.end()) { return textures[model]; }
  return "";
}
