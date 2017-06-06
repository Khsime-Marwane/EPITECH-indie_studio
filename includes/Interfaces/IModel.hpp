//
// Author: Marwane Khsime 
// Date: 2017-05-29 15:37:34 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-29 15:37:34
//

#ifndef IMODEL_HPP_
# define IMODEL_HPP_

# include <string>
# include <vector>
# include <utility>

namespace indie
{
    ///
    /// \class IModel
    /// \brief Interface to use in order to generate the Models loading list
    ///
    class   IModel
    {

        public:
            ///
            /// \fn virtual ~IModel()
            /// \brief virtual destructor
            ///
            virtual ~IModel() {};
            ///
            /// \fn virtual std::string getMeshPath() const = 0
            /// \brief generates on-the-fly the path to the Mesh to load
            ///
            virtual std::string getMeshPath() const = 0;
            ///
            /// \fn virtual std::vector<std::pair<size_t, size_t> > getAnimationsFrames const = 0
            /// \brief Returns the animation intervals.
            ///
            virtual std::vector<std::pair<size_t, size_t> > getAnimationsFrames() const = 0;

    };

}

#endif // IMODEL_HPP_