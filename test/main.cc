#include <radon.h>

int main(int argc, char* argv[])
{
	Radon r1(70, 350);
	Radon r2(53, 179);
	std::cout << std::boolalpha
		<< "r1 = " << r1 << ", r2 = " << r2
		<< "\n    equivalent to: r1 = " << r1.getIrreducible() << ", r2 = " << r2.getIrreducible()
		<< "\nr1 ＋ r2 = " << (r1 + r2)
		<< "\nr1 － r2 = " << (r1 - r2)
		<< "\nr1 × r2 = " << (r1 * r2)
		<< "\nr1 ÷ r2 = " << (r1 / r2)
		<< "\nr1 mod r2 = " << (r1 % r2)
		<< "\nr1 == r2: " << (r1 == r2)
		<< "\nr1 != r2: " << (r1 != r2)
		<< "\nr1 > r2: " << (r1 > r2) << ", r1 >= r2: " << (r1 >= r2)
		<< "\nr1 < r2: " << (r1 < r2) << ", r1 <= r2: " << (r1 <= r2)
		<< std::endl;
	return 0;
}
