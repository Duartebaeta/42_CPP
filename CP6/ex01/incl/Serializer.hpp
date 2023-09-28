#pragma once

#include <iostream>
#include <stdint.h>
#include "./Data.hpp"

typedef std::string str;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		~Serializer();
		Serializer &operator=(const Serializer& copy);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};