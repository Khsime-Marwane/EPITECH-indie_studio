//
// Author: Marwane Khsime
// Date: 2017-06-04 05:36:00
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-06-04 05:36:00
//

#ifndef TILE_HPP
# define TILE_HPP

# include "Interfaces/ITile.hpp"
# include "Game/ModelsId.hpp"
# include <vector>
# include <map>
# include <algorithm>
# include <functional>

namespace indie
{

    class Tile : public indie::ITile {

        public:

            Tile();

            virtual ~Tile() { }

            virtual std::size_t                     getTileSize() const;
            virtual bool                            hasModel(size_t at) const;
            virtual indie::MODELS_ID                getModelId(size_t at) const;
            virtual std::size_t                     getObjectId(size_t at) const;
            virtual ELookAt                         getObjectRotation(size_t at) const;
            virtual std::string                     getObjectTexture(size_t at) const;
            virtual bool                            doesAnimationChanged(size_t at) const;
            virtual std::pair<size_t, size_t>       getObjectFrameLoop(size_t at) const;
            virtual double                          getShiftX(size_t at) const;
            virtual double                          getShiftY(size_t at) const;
            virtual OBJECTS_ID                      getType(size_t at) const;

            void                    setHasModel(size_t at, bool value);
            void                    setModelId(size_t at, indie::MODELS_ID);
            void                    setObjectId(size_t at, std::size_t id);
            void                    setObjectRotation(size_t at, ELookAt lookat);
            void                    setObjectTexture(size_t at, const std::string &texture);
            void                    setDoesAnimationChanged(std::size_t at, bool value);
            void                    setObjectFrameLoop(size_t at, const std::pair<std::size_t, std::size_t> &fl);
            void                    setShiftX(size_t at, double x);
            void                    setShiftY(size_t at, double y);
            void                    setType(size_t at, OBJECTS_ID);

            Tile        &operator=(const Tile &);
            void        reset();
            void        deleteElement(size_t);
            bool        isTangible(size_t) const;
            void        newElem(size_t);
            void        setElem(size_t at, size_t id,
                                indie::OBJECTS_ID type = indie::OBJECTS_ID::EMPTY,
                                bool hasModel = false, indie::MODELS_ID modelId = indie::MODELS_ID::UNKNOWN,
                                bool doesAnimationChanged = true,
                                std::pair<size_t, size_t> frames = {0, 0},
                                std::string texture = "",
                                indie::ELookAt rotation = indie::ELookAt::SOUTH,
                                double shitX = 0.0, double shiftY = 0.0);

        private:

            std::vector<bool>                                     _hasModel;
            std::vector<indie::MODELS_ID>                         _modelId;
            std::vector<std::size_t>                              _objectId;
            std::vector<ELookAt>                                  _objectRotation;
            std::vector<std::string>                              _objectTexture;
            std::vector<bool>                                     _doesAnimationChanged;
            std::vector<std::pair<std::size_t, std::size_t> >      _objectFrameLoop;
            std::vector<double>                                   _shiftX;
            std::vector<double>                                   _shiftY;
            std::vector<OBJECTS_ID>                               _type;
    };
}

#endif // TILE_HPP
