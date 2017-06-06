//
// Author: Marwane Khsime 
// Date: 2017-05-22 17:50:23 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-22 17:50:23
//

#ifndef ITILE_HPP_
# define ITILE_HPP_

#include <cstddef>
#include <string>
#include <utility>
#include "Color.hpp"

namespace indie
{

    ///
    /// \enum TileTypeEvolution
    /// \brief Type of map tile
    ///
    enum TileTypeEvolution
    {
        //! Empty tile
        EMPTY = 0,
        
        //! Block tile
        BLOCK,
        
        //! Obstacle tile
        OBSTACLE,
        
        //! Enemy tile
        ENEMY,
        
        //! Enemy shot tile
        SHOT_ENEMY,
        
        //! Player shot tile
        SHOT_PLAYER,
        
        //! Powerup tile
        POWERUP,
        
        //! Player tile
        PLAYER,
        
        //! Food tile
        FOOD,
    };

	///
	/// \enum ELookAT
	///	\brief Indicate the direction where the model is looking at.
	///
	enum ELookAt
	{
		UNKNOWN = 0,
		NORTH,
		EAST,
		SOUTH,
		WEST
	};

	///
	/// \class ITile
	/// \brief Interface representing a tile
	///
	/// A tile is a "block" of the map. It can be a wall, a empty block,
	/// a player, etc. It can be described with a type, a color and/or
	/// a Model.
	///
	class ITile
	{
	public:
		///
		/// \fn virtual ~ITile()
		/// \brief Virtual destructor of the interface
		///
		virtual ~ITile() {};

		///
		/// \fn virtual Color getColor() const = 0
		/// \brief Get the color of the tile
		///
		virtual Color getColor() const = 0;
		///
		/// \fn virtual bool hasModel() const = 0
		/// \brief Returns true if the Tile has a Model affected, if not, use getColor()
		///
		virtual bool hasModel() const = 0;
		///
		/// \fn virtual size_t getModelId() const = 0
		/// \brief Get the Mesh ID linked with the model
		///
		virtual size_t getMeshId() const = 0;
		///
		/// \fn virtual size_t getModelId() const = 0
		/// \brief Get the Model ID
		///
		virtual size_t getModelId() const = 0;
		///
		/// \fn virtual ELookAt getModelRotation() const = 0
		/// \brief Get the direction towards which the character is directed
		///
		virtual ELookAt getModelRotation() const = 0;
		///
		/// \fn virtual std::string getModelTexture() const = 0
		/// \brief Get the Model texture
		///
		virtual std::string getModelTexture() const = 0;
		///
		/// \fn virtual bool doesAnimationChanged() const = 0
		/// \brief Returns true if the animation of the model has been changed
		///
		virtual bool doesAnimationChanged() const = 0;
		///
		/// \fn virtual std::pair<size_t, size_t> getModelFrameLoop() const = 0
		/// \brief Get the new frame loop of the model.
		///
		virtual std::pair<size_t, size_t> getModelFrameLoop() const = 0;
		///
		/// \fn virtual double getShiftX() const = 0
		/// \brief Get the tile position shift on x
		///
		virtual double getShiftX() const = 0;
			///
		/// \fn virtual size_t getShiftY() const = 0
		/// \brief Get the tile position shift on y
		///
		virtual double getShiftY() const = 0;
	};
}

#endif // !ITILE_HPP_
