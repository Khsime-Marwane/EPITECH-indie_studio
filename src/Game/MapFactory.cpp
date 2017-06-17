//
// Author: Marwane Khsime
// Date: 2017-06-08 00:50:54
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-06-08 00:50:54
//

#include "Game/Map.hpp"

void    indie::Map::generate_little_map() {
    this->_rawMap = std::vector<std::vector< int > >
      ({
        std::vector< int >({ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }),
        std::vector< int >({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 })
      });

    this->_width = 11;
    this->_height = 13;
    this->_nbLayers = 3;
    this->_sceneId = 0;
    this->create_layer(0);
    this->create_layer(1);
    this->create_layer(2);
    initTiles();
}
