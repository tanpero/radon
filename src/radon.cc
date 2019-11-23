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

Radon Radon::operator*(Radon rhs)
{
	return Radon(numerator * rhs.numerator, denominator * rhs.denominator);
}

Radon Radon::operator/(Radon rhs)
{
	if (rhs == 0)
	{
		throw new RadonException("Denominator cannot be zero");
	}
	return *this * rhs.getReciprocal();
}

Radon Radon::operator%(Radon rhs)
{
	Bigint newDenominator = denominator * rhs.denominator;
	Bigint leftNumerator = numerator * rhs.denominator;
	Bigint rightNumerator = rhs.numerator * denominator;
	Bigint mod = leftNumerator % rightNumerator;
	return Radon(mod, newDenominator);
}

Radon Radon::operator+=(Radon rhs)
{
	*this = *this + rhs;
	return *this;
}

Radon Radon::operator-=(Radon rhs)
{
	*this = *this - rhs;
	return *this;
}

Radon Radon::operator*=(Radon rhs)
{
	*this = *this * rhs;
	return *this;
}

Radon Radon::operator/=(Radon rhs)
{
	*this = *this / rhs;
	return *this;
}

Radon Radon::operator%=(Radon rhs)
{
	*this = *this % rhs;
	return *this;
}

Radon& Radon::simplify()
{
	Bigint _gcd = gcd(numerator, denominator);
	numerator /= _gcd;
	denominator /= _gcd;
	return *this;
}

Radon & Radon::getReciprocal()
{
	return Radon(denominator, numerator);
}

Radon & Radon::toReciprocal()
{
	*this = getReciprocal();
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

