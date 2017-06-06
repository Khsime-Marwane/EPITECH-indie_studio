//
// Author: Marwane Khsime 
// Date: 2017-06-04 06:45:22 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-04 06:45:22
//

#include <memory>
#include "Common/Map.hpp"

indie::Map::Map(size_t width, size_t height, size_t lnb)
    : _width(width), _height(height), _layersNb(lnb), _layers(), _level()
{

//   if (level == 0)
//     this->_level = std::vector<std::vector<bool>>
//       ({
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//         std::vector<bool>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}),
//      });

//   for (size_t i = 0; i < lnb; i++)
//     this->createLayer(i);
}

indie::Map::~Map()
{
}

indie::ITile const &indie::Map::at(size_t layer, size_t x, size_t y) const
{
  return *this->_layers[layer][y][x];
}

std::size_t  indie::Map::getLayerNb() const { return this->_layersNb; }

std::size_t  indie::Map::getWidth() const { return this->_width; }

std::size_t  indie::Map::getHeight() const { return this->_height; }

void         indie::Map::createLayer(std::size_t layer) {
    (void)layer;
}

// void         indie::Map::createLayer(std::size_t layer)
// {
//   std::size_t i = 0;

//   this->_layers.push_back(std::vector<std::vector<std::unique_ptr<Tile> > >());

//   for (size_t y = 0; y < this->_height; y++)
//     {
//       this->_layers[layer].push_back(std::vector<std::unique_ptr<indie::Tile>>());
//       for (size_t x = 0; x < this->_width; x++)
//         {
//           if (layer == 1 && this->_level[y][x] == 1)
//             this->_layers[layer][y].push_back(std::make_unique<indie::Tile>(indie::TileType::EMPTY,
//                                                                             indie::TileTypeEvolution::FOOD,
//                                                                             indie::Color::White,
//                                                                             true,
//                                                                             0,
//                                                                             0,
//                                                                             0.0,
//                                                                              0.0));
//           else if (layer > 0)
//             this->_layers[layer][y].push_back(std::make_unique<indie::Tile>(indie::TileType::EMPTY,
//                                                                              indie::TileTypeEvolution::EMPTY,
//                                                                              indie::Color::Transparent,
//                                                                              false,
//                                                                              0,
//                                                                              0,
//                                                                              0.0,
//                                                                              0.0));
//           else if (x > 2 && y > 2 && x + 3 < this->_width && y + 3 < this->_height)
//             this->_layers[layer][y].push_back(std::make_unique<indie::Tile>(indie::TileType::EMPTY,
//                                                                              indie::TileTypeEvolution::EMPTY,
//                                                                              indie::Color::Black,
//                                                                              true,
//                                                                              4,
//                                                                              i,
//                                                                              0.0,
//                                                                              0.0));
//           else
//             this->_layers[layer][y].push_back(std::make_unique<indie::Tile>(indie::TileType::BLOCK,
//                                                                              indie::TileTypeEvolution::BLOCK,
//                                                                              indie::Color::Black,
//                                                                              true,
//                                                                              4,
//                                                                              i,
//                                                                              0.0,
//                                                                              0.0));
//           i++;
//         }
//     }
// }
