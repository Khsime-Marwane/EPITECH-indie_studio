//
// Author: Marwane Khsime 
// Date: 2017-05-22 17:49:24 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-05-22 17:49:24
//

#include "Interfaces/Color.hpp"

namespace indie
{
	// Basic constant colors
	const Color Color::Black(0, 0, 0);
	const Color Color::White(255, 255, 255);
	const Color Color::Red(255, 0, 0);
	const Color Color::Green(0, 255, 0);
	const Color Color::Blue(0, 0, 255);
	const Color Color::Yellow(255, 255, 0);
	const Color Color::Magenta(255, 0, 255);
	const Color Color::Cyan(0, 255, 255);
	const Color Color::Transparent(0, 0, 0, 0);

	Color::Color(uint32_t c) :
		full(c)
	{}

	Color::Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) :
	#if IS_LITTLE_ENDIAN
		r(_r), g(_g), b(_b), a(_a)
	#else
		a(_a), b(_b), g(_g), r(_r)
	#endif
	{}

	Color::Color(Color const &c) :
		full(c.full)
	{}

	bool Color::operator==(Color const &c)
	{
	  return full == c.full;
	}

	bool Color::operator!=(Color const &c)
	{
	  return full != c.full;
	}

	bool Color::operator<(Color const &c)
	{
	  return full < c.full;
	}

	bool Color::operator<=(Color const &c)
	{
	  return full <= c.full;
	}

	bool Color::operator>=(Color const &c)
	{
	  return full >= c.full;
	}

	bool Color::operator>(Color const &c)
	{
	  return full > c.full;
	}
}
