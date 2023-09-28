#include "./Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "[Serializer] Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
	std::cout << "[Serializer] Copy constructor called" << std::endl;
}

Serializer	&Serializer::operator=(const Serializer& copy)
{
	(void)copy;
	std::cout << "[Serializer] Copy assignment operator called" << std::endl;
	return *this;
}

Serializer::~Serializer()
{
	std::cout << "[Serializer] Destructor called" << std::endl;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t int_point = reinterpret_cast<uintptr_t>(ptr);
	return (int_point);
}

Data*	Serializer::deserialize(uintptr_t ptr)
{
	Data *new_ptr = reinterpret_cast<Data*>(ptr);
	return (new_ptr);
}