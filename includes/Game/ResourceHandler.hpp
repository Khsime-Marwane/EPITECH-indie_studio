#ifndef RESOURCE_HANDLER_HPP
# define RESOURCE_HANDLER_HPP

# include <string>
# include <vector>
# include <map>
# include <algorithm>
# include <functional>
# include "Game/ModelsId.hpp"

namespace indie {
  typedef std::function<std::pair<size_t, size_t>(std::pair<size_t, size_t> &)> FrameSeeker;

  class ResourceHandler {
    public:
      ResourceHandler() {};
      ~ResourceHandler() {};

    public:
      static std::string getTexture(indie::MODELS_ID);

    public:
      static std::pair<size_t, size_t> getSkeletonFrame(std::string);
      static std::pair<size_t, size_t> getLethalFrame(OBJECTS_ID);
      static bool                      isFrameLethal(OBJECTS_ID,
                                                      std::pair<size_t, size_t>);
      static std::pair<size_t, size_t> getNextFrameSquareBomb(std::pair<size_t, size_t>);
      static std::pair<size_t, size_t> getNextFramePikesBomb(std::pair<size_t, size_t>);
      static std::pair<size_t, size_t> getNextFrameTentacleBomb(std::pair<size_t, size_t>);
      static std::pair<size_t, size_t> getNextFrameFallingPillar(std::pair<size_t, size_t>);
      static std::pair<size_t, size_t> getNextFrame(OBJECTS_ID,
                                                    std::pair<size_t, size_t>);
      static bool                      isDeathFrame(MODELS_ID, std::pair<size_t, size_t>);
  };
};

#endif // RESOURCE_HANDLER_HPP
