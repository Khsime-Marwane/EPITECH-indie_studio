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
#include <algorithm>
#include "Interfaces/IMap.hpp"
#include "Game/Tile.hpp"
#include "Game/ModelsId.hpp"
#include "Exception/exception.hpp"

namespace indie
{
    class Map : public indie::IMap
    {

        enum class GAME_MAP : int {

            LITTLE_MAP = 0

        };

        public:
            Map(std::size_t which_map);
            Map(Map &&) = default;
            Map(const Map &) = default;
            Map &operator=(Map &&) = default;
            Map &operator=(const Map &) = default;
            virtual ~Map();

            virtual std::size_t getLayerNb() const;
            virtual std::size_t getWidth() const;
            virtual std::size_t getHeight() const;
            virtual std::size_t getSceneId() const;
            virtual ECAMERA_VIEW getPOV() const;
            virtual const std::vector<std::size_t> &getObjectsId() const;
            virtual ITile const &at(std::size_t layer,
                                    std::size_t x,
                                    std::size_t y) const;
            Tile        &at(std::size_t layer,
                            std::size_t x,
                            std::size_t y);

            void setSceneId(std::size_t sceneId);
            void setCameraPOV(ECAMERA_VIEW pov);
            void addObjectById(std::size_t add);
            void deleteObjectById(std::size_t del);
            void setObectsId(const std::vector<std::size_t> &ids);

        private:

            // Fill a layer from the index 'layer'
            void    create_layer(std::size_t layer);

            // Push a Tile in the line y
            void    create_tile(std::size_t layer, std::size_t y,
                                bool tile_has_model = false,
                                MODELS_ID model_id = MODELS_ID::UNKNOWN,
                                const std::string &resource_path = "");

            // Init the tiles according to the rawmap
            void    initTiles();

            // Map generators
            void    generate_little_map();

            std::size_t _width;
            std::size_t _height;
            std::size_t _nbLayers;
            std::size_t _sceneId;
            ECAMERA_VIEW    _scenePov;
            std::vector<std::size_t>    _objectsId;
            std::vector<std::vector<std::vector< std::unique_ptr< Tile > > > > _layers;
            std::vector<std::vector< int > >   _rawMap;
    };

}


#endif // MAP_HPP
