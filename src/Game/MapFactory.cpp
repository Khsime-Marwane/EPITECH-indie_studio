
#include "Game/Map.hpp"

void    indie::Map::generate_little_map(size_t nPlayers) {
    this->_rawMap = std::vector<std::vector< int > >
      ({
        std::vector< int >({ nPlayers >= 1 ? 1 : 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, nPlayers >= 2 ? 2 : 0 }),
        std::vector< int >({ 0, 6, 5, 6, 5, 6, 5, 6, 5, 6, 0 }),
        std::vector< int >({ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 }),
        std::vector< int >({ 5, 6, 5, 6, 5, 6, 5, 6, 5, 6, 5 }),
        std::vector< int >({ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 }),
        std::vector< int >({ 5, 6, 5, 6, 5, 6, 5, 6, 5, 6, 5 }),
        std::vector< int >({ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 }),
        std::vector< int >({ 5, 6, 5, 6, 5, 6, 5, 6, 5, 6, 5 }),
        std::vector< int >({ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 }),
        std::vector< int >({ 5, 6, 5, 6, 5, 6, 5, 6, 5, 6, 5 }),
        std::vector< int >({ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 }),
        std::vector< int >({ 0, 6, 5, 6, 5, 6, 5, 6, 5, 6, 0 }),
        std::vector< int >({ nPlayers == 4 ? 4 : 0, 0, 5, 5, 5, 5, 5, 5, 5, 0, nPlayers >= 3 ? 3 : 0 })
      });

    this->_width = 11;
    this->_height = 13;
    this->_nbLayers = 2;
    this->_sceneId = 0;
    this->create_layer(0);
    this->create_layer(1);
    initTiles();
}
