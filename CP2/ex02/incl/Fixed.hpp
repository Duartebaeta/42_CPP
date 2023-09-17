#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

typedef std::string str;

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
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

};
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif