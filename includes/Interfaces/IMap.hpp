//
// Author: Marwane Khsime
// Date: 2017-05-22 17:50:02
//
// Last Modified by:   Marwane Khsime
// Last Modified time: 2017-05-22 17:50:02
//

#ifndef IMAP_HPP_
#define IMAP_HPP_

#include <cstddef>
#include <vector>
#include "ITile.hpp"

namespace indie
{

	///
	/// \enum ECAMERA_VIEW
	/// \brief Indicate the point of view of the camera.
	///
	enum class ECAMERA_VIEW : int {
		UNDEFINED = -1,
		DEFAULT = 0,
		INCLINED = 1
	};

	///
	/// \class IMap
	/// \brief Interface representing a Map
	///
	/// A map is composed of layers, which contain tiles.
    /// Your Map must support them from its own
	/// If you want to access to the tile x:3 y:8 of the layer 2
	/// you have to use the at method like IMap::at(2, 3, 8);
	///
  class IMap
  {
	public:
		///
		/// \fn virtual ~IMap()
		/// \brief Virtual destructor of the interface
		///
		virtual ~IMap(){};

		///
		/// \fn virtual size_t getLayerNb() const = 0
		/// \brief Get the number of layers
		///
		virtual std::size_t getLayerNb() const = 0;
		///
		/// \fn virtual size_t getWidth() const = 0
		/// \brief Get the width of the map
		///
		virtual std::size_t getWidth() const = 0;
		///
		/// \fn virtual size_t getHeight() const = 0
		/// \brief Get the height of the map
		///
		virtual std::size_t getHeight() const = 0;
		///
		/// \fn virtual ITile const &at(size_t layer, size_t x, size_t y) const = 0
		/// \brief Get a specific ITile of the map
		///
		virtual ITile const &at(std::size_t layer, std::size_t x, std::size_t y) const = 0;
		///
		/// \fn virtual size_t getPOV() const = 0
		/// \brief Get the point of view of the scene.
		///
		virtual ECAMERA_VIEW getPOV() const = 0;
		///
		/// \fn virtual size_t getHeight() const = 0
		/// \brief Get the id of the scene of this map
		///
		virtual std::size_t getSceneId() const = 0;
		///
		/// \fn virtual const std::vector<std::size_t> &getObjectsId() const = 0
		/// \brief Get the id's of the objects in this map.
		///
		virtual const std::vector<std::size_t> &getObjectsId() const = 0;

  };
}

#endif // !IMAP_HPP_
