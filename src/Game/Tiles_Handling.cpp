#include "Game/Game.hpp"

void  indie::Game::spreadBombAnimationCol(const std::size_t &x,
                                          const std::size_t &y,
                                          const std::size_t &spreadSize) {
                                            (void)x;
  for (std::size_t n = 0; n < spreadSize; n++) {
    if ((y - n) > 0) { /* set Animation (2, x, y - n) */ }
    if (n != 0 && (y + n) < _map.getHeight()) { /* set Animation (2, x, y + n) */ }
  }
}

void  indie::Game::spreadBombAnimationLine(const std::size_t &x,
                                            const std::size_t &y,
                                            const std::size_t &spreadSize) {
                                              (void)y;
  for (std::size_t n = 0; n < spreadSize; n++) {
    if ((x - n) > 0) { /* set Animation (2, x - n, y) */}
    if (n != 0 && (x + n) < _map.getWidth()) { /* set Animation (2, x + n, y) */ }
  }
}

void indie::Game::spreadBombAnimation(const std::size_t &x,
                                      const std::size_t &y,
                                      const std::size_t &spreadSize,
                                      const std::size_t &spreadWidth) {
  for (std::size_t n = 0; n < spreadWidth; n++) {
    spreadBombAnimationCol(x - n, y, spreadSize);
    spreadBombAnimationLine(x, y - n, spreadSize);
    if (n != 0) {
      spreadBombAnimationCol(x + n, y, spreadSize);
      spreadBombAnimationLine(x, y + n, spreadSize);
     }
  }
}

void  indie::Game::handleBomb(const std::size_t &x,
                              const std::size_t &y) {
  indie::Tile currentTile;
  std::size_t spreadWidth = 0;
  std::size_t spreadSize = 1;

  currentTile = _map.at(1, x, y);
  switch (currentTile.getType(0)) {
    case indie::OBJECTS_ID::SQUAREBOMB:
      spreadWidth = 1;
      spreadSize = 2;
      break;
    case indie::OBJECTS_ID::PIKESBOMB:
      spreadSize = 3;
      break;
    case indie::OBJECTS_ID::TENTACLEBOMB:
      spreadSize = -1;
      break;
    case indie::OBJECTS_ID::UNKNOWN:
    case indie::OBJECTS_ID::EMPTY:
    case indie::OBJECTS_ID::PLAYER_ONE:
    case indie::OBJECTS_ID::PLAYER_TWO:
    case indie::OBJECTS_ID::PLAYER_THREE:
    case indie::OBJECTS_ID::PLAYER_FOURTH:
    case indie::OBJECTS_ID::BOX:
    case indie::OBJECTS_ID::WALL:
    default:
      break;
  }
  spreadBombAnimation(x, y, spreadSize, spreadWidth);
}

void indie::Game::handlePlayer(const std::size_t &x,
                                const std::size_t &y,
                                int playerId) {
  (void)x;
  (void)y;
  (void)playerId;
}
