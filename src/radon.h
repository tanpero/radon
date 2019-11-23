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

class RadonException : public std::exception
{
	const char* _info;
public:
	RadonException(std::string info)
	{
		_info = info.c_str();
	}
	const char* what()
	{
		return _info;
	}
};

class Radon
{
	Bigint numerator;
	Bigint denominator;

	enum
	{
		POSITIVE, NEGATIVE
	} sign;

public:
	Radon() {}
	~Radon() {}

	template<typename N, typename D,
		typename = std::enable_if_t<(std::is_arithmetic<N>::value || std::is_same<N, Bigint>::value)
		&& (std::is_arithmetic<D>::value || std::is_same<D, Bigint>::value)>>
		Radon(N n, D d)
	{
		// 默认符号为正，若分子取绝对值不等于分子，则分子是负数，符号被设为负。
		// 若分母取绝对值不等于分母，则分母是负数，若分子是正数，则符号设为负，否则设为正。
		bool _sign = true;
		Bigint _n = abs(n);
		Bigint _d = abs(d);
		_sign = _n == n;
		_sign = _d == d;
		sign = sign ? POSITIVE : NEGATIVE;

		numerator = _n;
		denominator = _d;
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

	Radon operator+();
	Radon operator-();
	bool operator!();

public:
	template <typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	bool operator==(R rhs);
	bool operator==(Radon& rhs);

	template <typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	bool operator!=(R rhs);
	bool operator!=(Radon& rhs);

	template <typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	bool operator>=(R rhs);
	bool operator>=(Radon& rhs);

	template <typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	bool operator<=(R rhs);
	bool operator<=(Radon& rhs);

	template <typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	bool operator>(R rhs);
	bool operator>(Radon& rhs);

	template <typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
	bool operator<(R rhs);
	bool operator<(Radon& rhs);


public:
	Radon& reduce();
	Radon getIrreducible();
	Radon getReciprocal();
	Radon& toReciprocal();

public:
	std::string toString();
	double toDouble();
	float toFloat();
	long double toLongDouble();
	std::pair<Bigint, Bigint> toArbitrary();

};

std::ostream& operator<<(std::ostream& os, Radon& radon);

//std::ostream &operator<<(std::ostream &os, Radon &&radon);

template<typename R, typename T>
inline Radon Radon::operator+(R rhs)
{
	return Radon();
}

template<typename R, typename T>
inline Radon Radon::operator-(R rhs)
{
	return Radon();
}

template<typename R, typename T>
inline Radon Radon::operator*(R rhs)
{
	return Radon();
}

template<typename R, typename T>
inline Radon Radon::operator/(R rhs)
{
	return Radon();
}

template<typename R, typename T>
inline Radon Radon::operator%(R rhs)
{
	return Radon();
}

/*template<typename R, typename = std::enable_if_t<std::is_arithmetic<R>::value>>
inline Radon Radon::operator+=(R rhs)
{
return Radon();
}*/

template<typename R, typename T>
inline Radon Radon::operator-=(R rhs)
{
	return Radon();
}

template<typename R, typename T>
inline Radon Radon::operator*=(R rhs)
{
	return Radon();
}

template<typename R, typename T>
inline Radon Radon::operator/=(R rhs)
{
	return Radon();
}

template<typename R, typename T>
inline Radon Radon::operator%=(R rhs)
{
	return Radon();
}

template<typename R, typename T>
inline bool Radon::operator==(R rhs)
{
	return false;
}

template<typename R, typename T>
inline bool Radon::operator!=(R rhs)
{
	return false;
}

template<typename R, typename T>
inline bool Radon::operator>=(R rhs)
{
	return false;
}

template<typename R, typename T>
inline bool Radon::operator<=(R rhs)
{
	return false;
}

template<typename R, typename T>
inline bool Radon::operator>(R rhs)
{
	return false;
}

template<typename R, typename T>
inline bool Radon::operator<(R rhs)
{
	return false;
}


#endif // !_RADON_H_
