#ifndef _RADON_H_
#define _RADON_H_

#include <cmath>
#include <ratio>
#include <exception>
#include <string>
#include <iostream>
#include <type_traits>


template<typename N, typename D,
	typename = std::enable_if_t<std::is_arithmetic<N>::value
	&& std::is_arithmetic<D>::value>>
class Radon
{
	N numerator;
	D denominator;
public:
	
	Radon(N n, D d)
	{
		numerator = n;
		denominator = d;
	}

	Radon(const char* source)
	{

	}


	~Radon();

public:

};

#endif // !_RADON_H_
