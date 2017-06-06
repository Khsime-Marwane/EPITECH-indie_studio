//
// Author: Marwane Khsime 
// Date: 2017-05-29 17:10:14 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-29 17:10:14
//

#ifndef MODEL_HPP
# define MODEL_HPP

#include "Interfaces/IModel.hpp"

namespace indie
{
    class Model : public indie::IModel {

        public:
            Model(const std::string &meshPath,
                  std::vector<std::pair<size_t, size_t> > frameSequences);
            virtual ~Model() {};

            virtual std::string getMeshPath() const;
            virtual std::vector<std::pair<size_t, size_t> > getAnimationsFrames() const;

        private:
            const std::string                       _meshPath;
            std::vector<std::pair<size_t, size_t> > _frameSequences;
    };
}


# endif // MODEL_HPP