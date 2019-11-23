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

Radon& Radon::reduce()
{
	Bigint _gcd = gcd(numerator, denominator);
	numerator /= _gcd;
	denominator /= _gcd;
	return *this;
}

Radon & Radon::getIrreducible()
{
	Radon radon = *this;
	Bigint _gcd = gcd(radon.numerator, radon.denominator);
	radon.numerator /= _gcd;
	radon.denominator /= _gcd;
	return radon;
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

double Radon::toDouble()
{
	return 0.0;
}

float Radon::toFloat()
{
	return 0.0f;
}

long double Radon::toLongDouble()
{
	return 0;
}

std::pair<Bigint, Bigint> Radon::toArbitrary()
{
	return std::pair<Bigint, Bigint>();
}

std::ostream& operator<<(std::ostream& os, Radon& radon)
{
	return os << radon.toString();
}

Radon Radon::operator+()
{
	return Radon();
}

Radon Radon::operator-()
{
	return Radon();
}

bool Radon::operator!()
{
	return false;
}

bool Radon::operator==(Radon & rhs)
{
	Radon r1 = this->getIrreducible();
	Radon r2 = rhs.getIrreducible();
	return r1.numerator == r2.numerator && r1.denominator == r2.denominator;
}

bool Radon::operator!=(Radon & rhs)
{
	return !(*this == rhs);
}

bool Radon::operator>=(Radon & rhs)
{
	return false;
}

bool Radon::operator<=(Radon & rhs)
{
	return false;
}

bool Radon::operator>(Radon & rhs)
{
	return false;
}

bool Radon::operator<(Radon & rhs)
{
	return false;
}
