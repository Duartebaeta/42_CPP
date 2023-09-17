#include "../incl/bsp.hpp"

int main( void ) {
	Point A(1.0f, 0.0f);
	Point B(4.0f, 4.0f); 
	Point C(0.0f, 3.0f);

	Point TesteY(1.0f, 0.0f);
	Point TesteX(2.0f, 2.0f);
	Point TesteZ(5.0f, 5.0f);

	std::cout << bsp(A,B,C,TesteY) << std::endl;
	std::cout << bsp(A,B,C,TesteX) << std::endl;
	std::cout << bsp(A,B,C,TesteZ) << std::endl;
}