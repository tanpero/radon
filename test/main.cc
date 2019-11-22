#include <radon.h>

int main(int argc, char* argv[])
{
	Radon r1(100, 200);
	Radon r2(53, 179);
	std::cout << "r1 = " << r1 << ", r2 = " << r2 << std::endl;
	return 0;
}
