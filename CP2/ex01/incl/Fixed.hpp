#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed {
	private:
		int _value;
		static const int width = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed & operator = (const Fixed &f);
		int getRawBits(void) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif