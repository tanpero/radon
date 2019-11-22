#include <radon.h>

int main(int argc, char* argv[])
{
	Radon r1(100, 200);
	std::cout << r1.toString() << std::endl;
	return 0;
}
