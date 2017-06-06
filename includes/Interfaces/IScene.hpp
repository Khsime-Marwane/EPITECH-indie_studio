//
// Author: Marwane Khsime 
// Date: 2017-06-05 07:05:42 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-05 07:05:42
//

#ifndef ISCENE_HPP
# define ISCENE_HPP

#include <string>
#include <utility>

namespace indie
{
    ///
    /// \class IScene
    /// \brief Interface to use in order to generate the scene (decor) in the gfx
    ///
    class   IScene {

        public:

            ///
            /// \fn virtual ~IScene()
            /// \brief virtual destructor
            ///
            virtual ~IScene() {};
            ///
            /// \fn virtual std::size_t getNumberParts() const = 0;
            /// \brief returns the number of parts of the scene
            ///
            virtual std::size_t getNumberParts() const = 0;
            ///
            /// \fn virtual std::pair<std::string, std::string> getPartAtPos(std::size_t) const = 0
            /// \brief takes as parameter the index of the part and 
            ///        returns as a pair of strings the mesh and the texture associated with the mesh.
            ///
            ///
            virtual std::pair<std::string, std::string> getPartAtPos(std::size_t) const = 0;
    };
}

#endif // ISCENE_HPP