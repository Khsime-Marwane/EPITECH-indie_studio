//
// Author: Marwane Khsime 
// Date: 2017-06-04 05:36:00 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-04 05:36:00
//

#ifndef TILE_HPP
# define TILE_HPP

#include "Interfaces/ITile.hpp"

namespace indie
{
    class Tile : public indie::ITile {

        public:

            Tile(const Color &color,
                 bool hasModel,
                 std::size_t meshId,
                 std::size_t modelId,
                 ELookAt rotation,
                 const std::string &texture,
                 bool animationChanged,
                 std::pair<size_t, size_t> frameLoop,
                 double shiftX,
                 double shiftY);

            Tile(Tile &&) = default;
            Tile(const Tile &) = default;
            Tile &operator=(Tile &&) = default;
            Tile &operator=(const Tile &) = default;

            virtual ~Tile() { }


            virtual Color                           getColor() const;
            virtual bool                            hasModel() const;
            virtual std::size_t                     getMeshId() const;
            virtual std::size_t                     getModelId() const;
            virtual ELookAt                         getModelRotation() const;
            virtual std::string                     getModelTexture() const;
            virtual bool                            doesAnimationChanged() const;
            virtual std::pair<size_t, size_t>       getModelFrameLoop() const;
            virtual double                          getShiftX() const;
            virtual double                          getShiftY() const;

            void                    setColor(const Color &);
            void                    setHasModel(bool);
            void                    setMeshId(std::size_t);
            void                    setModelId(std::size_t);
            void                    setModelRotation(ELookAt);
            void                    setModelTexture(const std::string &);
            void                    setDoesAnimationChanged(bool);
            void                    setModelFrameLoop(const std::pair<std::size_t, std::size_t> &);
            void                    setShiftX(double);
            void                    setShiftY(double);

        private:

            Color                                   _color;
            bool                                    _hasModel;
            std::size_t                             _meshId;
            std::size_t                             _modelId;
            ELookAt                                 _modelRotation;
            std::string                             _modelTexture;
            bool                                    _doesAnimationChanged;
            std::pair<std::size_t, std::size_t>     _modelFrameLoop;
            double                                  _shiftX;
            double                                  _shiftY;

    };
}

#endif // TILE_HPP
