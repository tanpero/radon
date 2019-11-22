#include <radon.h>

std::string Radon::toString()
{
	return numerator.toString() + "/" + denominator.toString();
}

/*
Radon Radon::operator+(Radon rhs)
{
	return Radon();
}

Radon Radon::operator-(Radon rhs)
{
	return Radon();
}

Radon Radon::operator*(Radon rhs)
{
	return Radon();
}

Radon Radon::operator/(Radon rhs)
{
	return Radon();
}

Radon Radon::operator%(Radon rhs)
{
	return Radon();
}
*/

std::ostream& operator<<(std::ostream& os, Radon& radon)
{
	return os << radon.toString();
}
