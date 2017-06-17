//
// Author: Marwane Khsime 
// Date: 2017-06-05 07:01:56 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-05 07:01:56
//

#ifndef SCENE_HPP
# define SCENE_HPP

#include <string>
#include <vector>

#include "Interfaces/IScene.hpp"

namespace indie
{
    class Scene : public IScene
    {
        public:
            Scene(const std::vector<std::pair<std::string, std::string> > &parts,
                  const std::string &dome,
                  float x,
                  float y,
                  float z);
            virtual ~Scene();

            virtual float getStartX() const;
            virtual float getStartY() const;
            virtual float getStartZ() const;
            virtual const std::string &getDome() const;
            virtual std::size_t getNumberParts() const;
            virtual std::pair<std::string, std::string> getScenePartAtPos(std::size_t part) const;

        private:
            std::vector<std::pair<std::string, std::string> >   _sceneParts;
            std::string _dome;
            float _x;
            float _y;
            float _z;
    };
    
}

#endif // SCENE_HPP
