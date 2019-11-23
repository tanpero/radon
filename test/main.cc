#include <radon.h>

int main(int argc, char* argv[])
{
	Radon r1(70, 350);
	Radon r2(53, 179);
	r1.toString();
	std::cout << std::boolalpha
		<< "r1 = " << r1 << ", r2 = " << r2
		<< "\nr1 гл r2 = " << (r1 + r2)
		<< "\nr1 гн r2 = " << (r1 - r2)
		<< "\nr1 б┴ r2 = " << (r1 * r2)
		//<< "\nr1 б┬ r2 = " << (r1 / r2)
		<< "\nr1 mod r2 = " << (r1 % r2)
		<< "\nr1 == r2: " << (r1 == r2)
		<< "\nr1 != r2: " << (r1 != r2) 
		<< std::endl;
	return 0;
}
