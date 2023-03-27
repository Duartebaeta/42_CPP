#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
typedef std::string str;

class Weapon
{
private:
	str	_type;
public:
	Weapon(str type);
	~Weapon(void);
	const str& getType(void);
	void setType(str newType);
};


#endif