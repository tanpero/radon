#include <radon.h>

std::string Radon::toString()
{
	return numerator.toString() + "/" + denominator.toString();
}
