#include "../incl/Point.hpp"

Point::Point() : x(0), y(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Default destructor called" << std::endl;
}

Point::Point(float x, float y) : x(x), y(y)
{
	std::cout << "Parameter constructor called" << std::endl;
}

Point::Point(const Point &other) : x(other.x), y(other.y) {
	std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &p)
{
	(void)p;
	return (*this);
}

const Fixed Point::get_x()
{
	return this->x;
}

const Fixed Point::get_y()
{
	return this->y;
}

bool Point::operator==(const Point &b) const
{
	if (this->x == b.x && this->y == b.y)
		return (true);
	else
		return (false);
}