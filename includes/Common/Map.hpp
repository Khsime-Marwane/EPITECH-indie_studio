//
// Author: Marwane Khsime 
// Date: 2017-06-04 06:10:56 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-04 06:10:56
//

#ifndef MAP_HPP
# define MAP_HPP

#include <vector>
#include <memory>
#include "Interfaces/IMap.hpp"
#include "Common/Tile.hpp"

namespace indie
{
    class Map
    {
        public:
            Map(std::size_t width,
                std::size_t height,
                std::size_t layerNb);
            Map(Map &&) = default;
            Map(const Map &) = default;
            Map &operator=(Map &&) = default;
            Map &operator=(const Map &) = default;
            virtual ~Map();

            virtual std::size_t getLayerNb() const;
            virtual std::size_t getWidth() const;
            virtual std::size_t getHeight() const;
            virtual ITile const &at(std::size_t layer,
                                    std::size_t x,
                                    std::size_t y) const;

        private:
            void    createLayer(std::size_t layer);


            size_t  _width;
            size_t  _height;
            size_t  _layersNb;
            std::vector<std::vector<std::vector< std::unique_ptr< Tile > > > > _layers;
            std::vector<std::vector< bool > > _level;
    };
   
}


#endif // MAP_HPP