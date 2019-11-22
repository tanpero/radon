#include <radon.h>

Radon Radon::operator+(Radon rhs)
{
	Bigint newDenominator = denominator * rhs.denominator;
	Bigint newNumerator = numerator * rhs.denominator + denominator * rhs.numerator;
	return Radon(newDenominator, newNumerator);
}

Radon Radon::operator-(Radon rhs)
{
	Bigint newDenominator = denominator * rhs.denominator;
	Bigint newNumerator = numerator * rhs.denominator - denominator * rhs.numerator;
	return Radon(newDenominator, newNumerator);
}

Radon& Radon::simplify()
{
	Bigint _gcd = gcd(numerator, denominator);
	numerator /= _gcd;
	denominator /= _gcd;
	return *this;
}

std::string Radon::toString()
{
	return numerator.toString() + "/" + denominator.toString();
}

std::ostream& operator<<(std::ostream& os, Radon& radon)
{
	return os << radon.toString();
}

