#include "Game/Tile.hpp"

std::pair<size_t, size_t>   indie::Tile::getNextFrameSquareBomb(std::pair<size_t, size_t> current_frame) {
  static std::vector<std::pair<size_t, size_t > > frames = {
    {0, 0}, {1, 66}, {67, 82}, {83, 84}, {85, 90}
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

std::pair<size_t, size_t>   indie::Tile::getNextFramePikesBomb(std::pair<size_t, size_t> current_frame) {
  static std::vector<std::pair<size_t, size_t > > frames = {
    {0, 0}, {1, 48}, {49, 65}
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

std::pair<size_t, size_t>   indie::Tile::getNextFrameTentacleBomb(std::pair<size_t, size_t> current_frame) {
  static std::vector<std::pair<size_t, size_t > > frames = {
    {0, 0}, {1, 51}, {52, 68}, {69, 79}, {80, 85}
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

std::pair<size_t, size_t>   indie::Tile::getSkeletonFrame(std::string state) {
  static std::map<std::string, std::pair<size_t, size_t > > frames = {
    { "CAST", {1, 36} },
    { "DIE", {38, 68} },
    { "IDLE", {70, 150} },
    { "RUN", {152, 175} },
    { "SPAWN", {177, 250} }
  };
  std::map<std::string, std::pair<size_t, size_t> >::const_iterator frame_it;

  if ((frame_it = frames.find(state)) == frames.end()) { return std::pair<size_t, size_t>({0, 0}); }
  return (*frame_it).second;
}

std::pair<size_t, size_t>   indie::Tile::getNextFrame(indie::OBJECTS_ID type,
                                                      std::pair<size_t, size_t> frame) {
  static std::map<indie::OBJECTS_ID, FrameSeeker> seekers = {
    { indie::OBJECTS_ID::SQUAREBOMB, [&frame]()->std::pair<size_t, size_t> { return indie::Tile::getNextFrameSquareBomb(frame); } },
    { indie::OBJECTS_ID::PIKESBOMB, [&frame]()->std::pair<size_t, size_t> { return indie::Tile::getNextFramePikesBomb(frame); } },
    { indie::OBJECTS_ID::TENTACLEBOMB, [&frame]()->std::pair<size_t, size_t> { return indie::Tile::getNextFrameTentacleBomb(frame); } }
  };

  if (seekers.find(type) != seekers.end()) { return seekers[type](); }
  return std::pair<size_t, size_t>(0, 0);
}

std::pair<size_t, size_t>   indie::Tile::getLethalFrame(indie::OBJECTS_ID bombType) {
  static std::map<indie::OBJECTS_ID, std::pair<size_t, size_t> > frames = {
    { indie::OBJECTS_ID::SQUAREBOMB, { 67, 82 } },
    { indie::OBJECTS_ID::PIKESBOMB, { 49, 65 } },
    { indie::OBJECTS_ID::TENTACLEBOMB, { 52, 68 } }
  };

    std::map<indie::OBJECTS_ID, std::pair<size_t, size_t> >::const_iterator frame_it;

    if ((frame_it = frames.find(bombType)) == frames.end()) { return std::pair<size_t, size_t>({0, 0}); }
  return (*frame_it).second;
}

bool  indie::Tile::isFrameLethal(indie::OBJECTS_ID type,
                                  std::pair<size_t, size_t> frame) {
  static std::map<indie::OBJECTS_ID, std::vector<std::pair<size_t, size_t> > > frames = {
    { indie::OBJECTS_ID::SQUAREBOMB, { {67, 82} }},
    { indie::OBJECTS_ID::PIKESBOMB, { {49, 65} } },
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

bool  indie::Tile::isDeathFrame(indie::MODELS_ID type,
                                std::pair<size_t, size_t> frame) {
  static std::map<indie::MODELS_ID, std::pair<size_t, size_t>  > frames = {
    { indie::MODELS_ID::SKELETON_MODEL, {38, 68} },
    { indie::MODELS_ID::BOX_MODEL, {1, 25} }
  };
  return frames.find(type) != frames.end() && frames[type] == frame;
}