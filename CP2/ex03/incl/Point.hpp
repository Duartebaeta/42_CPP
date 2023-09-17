#ifndef POINT_HPP
#define POINT_HPP

#include "./Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(float x, float y);
		Point(const Point &p);
		Point & operator=(const Point &p);
		~Point();
		const Fixed get_x();
		const Fixed get_y();
		bool operator==(const Point &b) const;
};

#endif