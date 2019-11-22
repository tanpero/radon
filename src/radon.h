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

	enum
	{
		POSITIVE, NEGATIVE
	} sign;

public:
	Radon();
	Radon(Radon&);
	Radon& operator=(Radon&);

	template<typename N, typename D,
		typename = std::enable_if_t<(std::is_arithmetic<N>::value || std::is_same<N, Bigint>::value)
		&& (std::is_arithmetic<D>::value || std::is_same<D, Bigint>::value)>>
	Radon(N n, D d)
	{
		// Ĭ�Ϸ���Ϊ����������ȡ����ֵ�����ڷ��ӣ�������Ǹ��������ű���Ϊ����
		// ����ĸȡ����ֵ�����ڷ�ĸ�����ĸ�Ǹ��������������������������Ϊ����������Ϊ����
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
	Radon& simplify();

public:
	std::string toString();
	double toDouble();
	float toFloat();
	long double toLongDouble();
	std::pair<Bigint, Bigint> toArbitrary();

};

std::ostream& operator<<(std::ostream& os, Radon& radon);

#endif // !_RADON_H_
