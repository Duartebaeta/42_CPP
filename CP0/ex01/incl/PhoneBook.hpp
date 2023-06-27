#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

class PhoneBook {
	public:
		void Add(void);
		void Search(void);
		void Exit(void);
		PhoneBook(void);
	private:
		Contact	list[8];
		int		cycle;
		int		contacts;
};

#endif