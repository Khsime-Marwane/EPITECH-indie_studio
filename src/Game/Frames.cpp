#include "Game/ResourceHandler.hpp"

std::pair<size_t, size_t>   indie::ResourceHandler::getNextFrameSquareBomb(std::pair<size_t, size_t> current_frame) {
  static std::vector<std::pair<size_t, size_t > > frames = {
    {0, 0}, {1, 66}, {67, 82}, {83, 84}
  };
  size_t frameID = 0;

  std::find_if(frames.begin(), frames.end(),
  [&](std::pair<size_t, size_t> &frame) {
    frameID++;
    return frame.first == current_frame.first && frame.second == current_frame.second;
  });
  if (frameID == frames.size()) { return std::pair<size_t, size_t>({0, 0});}
  return frames[frameID];
}

std::pair<size_t, size_t>   indie::ResourceHandler::getNextFramePikesBomb(std::pair<size_t, size_t> current_frame) {
  static std::vector<std::pair<size_t, size_t > > frames = {
    {0, 0}, {1, 48}, {49, 64}
  };
  size_t frameID = 0;

  std::find_if(frames.begin(), frames.end(),
  [&](std::pair<size_t, size_t> &frame) {
    frameID++;
    return frame.first == current_frame.first && frame.second == current_frame.second;
  });
  if (frameID == frames.size()) { return std::pair<size_t, size_t>({0, 0});}
  return frames[frameID];
}

std::pair<size_t, size_t>   indie::ResourceHandler::getNextFrameTentacleBomb(std::pair<size_t, size_t> current_frame) {
  static std::vector<std::pair<size_t, size_t > > frames = {
    {0, 0}, {1, 51}, {52, 68}, {69, 85}
  };
  size_t frameID = 0;

  std::find_if(frames.begin(), frames.end(),
  [&](std::pair<size_t, size_t> &frame) {
    frameID++;
    return frame.first == current_frame.first && frame.second == current_frame.second;
  });
  if (frameID == frames.size()) { return std::pair<size_t, size_t>({0, 0});}
  return frames[frameID];
}

std::pair<size_t, size_t>   indie::ResourceHandler::getSkeletonFrame(std::string state) {
  static std::map<std::string, std::pair<size_t, size_t > > frames = {
    { "CAST", {1, 36} },
    { "DIE", {38, 68} },
    { "IDLE", {70, 140} },
    { "RUN", {152, 175} },
    { "SPAWN", {177, 250} }
  };
  std::map<std::string, std::pair<size_t, size_t> >::const_iterator frame_it;

  if ((frame_it = frames.find(state)) == frames.end()) { return std::pair<size_t, size_t>({0, 0}); }
  return (*frame_it).second;
}

std::pair<size_t, size_t>   indie::ResourceHandler::getNextFrame(indie::OBJECTS_ID type,
                                                      std::pair<size_t, size_t> frame) {
  static std::map<indie::OBJECTS_ID, FrameSeeker> seekers = {
    { indie::OBJECTS_ID::SQUAREBOMB, [](std::pair<size_t, size_t> &f)->std::pair<size_t, size_t> { return indie::ResourceHandler::getNextFrameSquareBomb(f); } },
    { indie::OBJECTS_ID::PIKESBOMB, [](std::pair<size_t, size_t> &f)->std::pair<size_t, size_t> { return indie::ResourceHandler::getNextFramePikesBomb(f); } },
    { indie::OBJECTS_ID::TENTACLEBOMB, [](std::pair<size_t, size_t> &f)->std::pair<size_t, size_t> { return indie::ResourceHandler::getNextFrameTentacleBomb(f); } }
  };

  if (seekers.find(type) != seekers.end()) { return seekers[type](frame); }
  return std::pair<size_t, size_t>(0, 0);
}

std::pair<size_t, size_t>   indie::ResourceHandler::getLethalFrame(indie::OBJECTS_ID bombType) {
  static std::map<indie::OBJECTS_ID, std::pair<size_t, size_t> > frames = {
    { indie::OBJECTS_ID::SQUAREBOMB, { 67, 82 } },
    { indie::OBJECTS_ID::PIKESBOMB, { 49, 64 } },
    { indie::OBJECTS_ID::TENTACLEBOMB, { 52, 68 } },
    { indie::OBJECTS_ID::BOX, { 1, 25 } }
  };

  std::map<indie::OBJECTS_ID, std::pair<size_t, size_t> >::const_iterator frame_it;

  if ((frame_it = frames.find(bombType)) == frames.end()) { return std::pair<size_t, size_t>({0, 0}); }
  return (*frame_it).second;
}

bool  indie::ResourceHandler::isFrameLethal(indie::OBJECTS_ID type,
                                  std::pair<size_t, size_t> frame) {
  static std::map<indie::OBJECTS_ID, std::vector<std::pair<size_t, size_t> > > frames = {
    { indie::OBJECTS_ID::SQUAREBOMB, { {67, 90} }},
    { indie::OBJECTS_ID::PIKESBOMB, { {49, 64} } },
    { indie::OBJECTS_ID::TENTACLEBOMB, { {52, 68} } }
  };
  std::map<indie::OBJECTS_ID, std::vector<std::pair<size_t, size_t> > >::const_iterator frame_it;

  if ((frame_it = frames.find(type)) == frames.end()) { return false; }
  const std::vector<std::pair<size_t, size_t> > &lethalFrames = (*frame_it).second;

  return std::find_if(lethalFrames.begin(), lethalFrames.end(),
          [&frame](const std::pair<size_t, size_t> &lethalFrame) -> bool {
            return frame.first >= lethalFrame.first && frame.second <= lethalFrame.second;
          }) != lethalFrames.end();
}

bool  indie::ResourceHandler::isDeathFrame(indie::MODELS_ID type,
                                std::pair<size_t, size_t> frame) {
  static std::map<indie::MODELS_ID, std::pair<size_t, size_t>  > frames = {
    { indie::MODELS_ID::SKELETON_MODEL, {38, 68} },
    { indie::MODELS_ID::BOX_MODEL, {1, 25} }
  };
  return frames.find(type) != frames.end() && frames[type] == frame;
}
