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
            Scene(const std::vector<std::pair<std::string, std::string> > &parts);
            Scene(Scene &&) = delete;
            Scene(const Scene &) = delete;
            Scene &operator=(Scene &&) = delete;
            Scene &operator=(const Scene &) = delete;
            virtual ~Scene();

            virtual std::size_t getNumberParts() const;
            virtual std::pair<std::string, std::string> getPartAtPos(std::size_t part) const;

        private:
            std::vector<std::pair<std::string, std::string> >   _sceneParts;
    };
    
}

#endif // SCENE_HPP
