#ifndef _RADON_H_
#define _RADON_H_

#include <cmath>
#include <ratio>
#include <exception>
#include <string>
#include <iostream>
#include <type_traits>
#include <bigint.h>
#include <tuple>

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
	Radon operator+(Radon rhs);
	Radon operator-(Radon rhs);
	Radon operator*(Radon rhs);
	Radon operator/(Radon rhs);
	Radon operator%(Radon rhs);
	
	Radon operator+=(Radon rhs);
	Radon operator-=(Radon rhs);
	Radon operator*=(Radon rhs);
	Radon operator/=(Radon rhs);
	Radon operator%=(Radon rhs);


	template<typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	Radon operator+(R rhs);

	template<typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	Radon operator-(R rhs);

	template<typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	Radon operator*(R rhs);

	template<typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	Radon operator/(R rhs);

	template<typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	Radon operator%(R rhs);
	
	
    template<typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	Radon operator+=(R rhs);

	template<typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	Radon operator-=(R rhs);

	template<typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	Radon operator*=(R rhs);

	template<typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	Radon operator/=(R rhs);

	template<typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	Radon operator%=(R rhs);


public:
	std::string toString();

};

std::ostream& operator<<(std::ostream& os, Radon& radon);

#endif // !_RADON_H_
