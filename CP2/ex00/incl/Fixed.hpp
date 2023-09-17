#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

typedef std::string str;

class Fixed {
	private:
		int _value;
		static const int width = 8;
	public:
		Fixed();
		Fixed(const Fixed &f);
		~Fixed();
		Fixed & operator = (const Fixed &f);
		int getRawBits(void) const;
		void setRawBits( int const raw );
};

#endif