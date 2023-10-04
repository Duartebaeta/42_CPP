#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int	_size;
	public:
		T *array;

		Array() : _size(0), array(new T())
		{
			std::cout << "[Array] Default constructor called" << std::endl;
		}
		Array(unsigned int n) : _size(n), array(new T[n])
		{
			std::cout << "[Array] Parameter constructor called" << std::endl;
		}
		Array(const Array& copy)
		{
			std::cout << "[Array] Copy constructor called" << std::endl;
			this->array = new T[copy.size()];
			*this = copy;
		}
		Array &operator=(const Array& copy)
		{
				*this->array = *copy.array;
				this->_size = copy.size();
				std::cout << "[Array] Copy assignment operator called" << std::endl;
				return *this;
		}
		~Array()
		{
				std::cout << "[Array] Destructor called" << std::endl;
				delete[] array;
		}
		unsigned int	size() const
		{
			return this->_size;
		}
		T& operator[](unsigned int index)
		{
			if (index < this->_size) {
				return array[index];
			}
			throw std::out_of_range("Index out of bounds");
		}
		const T& operator[](unsigned int index) const
		{
			if (index < this->_size) {
				return array[index];
			}
			throw std::out_of_range("Index out of bounds");
		}
};