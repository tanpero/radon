#include <radon.h>

int main(int argc, char* argv[])
{
	Radon r1(70, 350);
	Radon r2(53, 179);
	r1.toString();
	//std::cout << "r1 = " << r1 << ", r2 = " << r2
	/*	<< "\nr1 + r2 = " << (r1 + r2)
		<< "\nr1 - r2 = " << (r1 - r2)
		<< "\nr1 ¡Á r2 = " << (r1 * r2)
		<< "\nr1 ¡Â r2 = " << (r1 / r2)
		//<< "\nr1 mod r2 = " << (r1 % r2) *////<< std::endl;
	return 0;
}
