#include "../incl/Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) : _value(f._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	this->_value = i << this->width;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	this->_value = roundf(f * (1 << width));
	std::cout << "Float constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &f)
{
	_value = f._value;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

int	Fixed::toInt() const
{
	return this->_value >> this->width;
}

float Fixed::toFloat() const
{
	return ((float)_value / (1 << this->width));
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->_value < other._value;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->_value > other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->_value <= other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result = this->toFloat() + other.toFloat();
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result = this->toFloat() - other.toFloat();
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result = this->toFloat() * other.toFloat();
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;
	result = this->toFloat() / other.toFloat();
	return result;
}

Fixed &Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value++;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}