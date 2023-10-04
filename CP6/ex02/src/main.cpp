#include "../incl/Base.hpp"
#include "../incl/A.hpp"
#include "../incl/B.hpp"
#include "../incl/C.hpp"

Base*	generate(void)
{
	Base *ret;
	
	switch(std::rand() % 3)
	{
		case 0:
			ret = new A();
			break;
		case 1:
			ret = new B();
			break;
		case 2:
			ret = new C();
			break;
	}
	return (ret);
}

void	identify(Base* p)
{
	if (p == NULL)
		std::cout << "Invalid pointer" << std::endl;
	else if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Invalid type pointer" << std::endl;
}

void	identify(Base& p)
{
	try {
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception &e) {

	}
	try {
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception &e) {
		
	}
	try {
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception &e) {
		
	}
}

int	main()
{
	srand(time(NULL));
	{
		Base *p;
		
		p = generate();
		identify(p);
		delete p;
	}
	{
		Base *p;
		
		p = generate();
		identify(p);
		delete p;
	}
	{
		Base *p;
		
		p = generate();
		identify(p);
		delete p;
	}
	{
		Base *p;
		
		p = generate();
		identify(p);
		delete p;
	}
	{
		Base *p;
		
		p = generate();
		identify(p);
		delete p;
	}
}