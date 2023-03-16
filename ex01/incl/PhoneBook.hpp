#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <array>

class PhoneBook {
	public:
		void Add(void);
		void Search(void);
		void Exit(void);
		PhoneBook(void);
	private:
		std::array<Contact, 8>	list;
		int		cycle;
		int		contacts;
};

#endif