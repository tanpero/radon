#ifndef _RADON_H_
#define _RADON_H_

#include <cmath>
#include <ratio>
#include <exception>
#include <string>
#include <iostream>
#include <type_traits>
#include <bigint.h>


class Radon
{
	Bigint numerator;
	Bigint denominator;

public:
	template<typename N, typename D,
		typename = std::enable_if_t<std::is_arithmetic<N>::value
		&& std::is_arithmetic<D>::value>>
	Radon(N n, D d)
	{
		numerator = n;
		denominator = d;
	}

	Radon(std::string source);

public:
	RadonValue operator+(RadonValue rhs);
	RadonValue operator-(RadonValue rhs);
	RadonValue operator*(RadonValue rhs);
	RadonValue operator/(RadonValue rhs);
	RadonValue operator%(RadonValue rhs);
	RadonValue operator++(int);
	RadonValue operator--(int);
	RadonValue operator++();
	RadonValue operator--();

public:
	std::string toString();

};

#endif // !_RADON_H_
