#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

typedef std::string str;

class Contact {
	public:
		void	AddFirstName(str firstname);
		void	AddLastName(str lastname);
		void	AddNickName(str nickname);
		void	AddPhoneNumber(str phone);
		void	AddDarkestSecret(str ds);
		void	print_info(void);
	private:
		str		firstname;
		str		lastname;
		str		nickname;
		str		phone;
		str		ds;
};

#endif