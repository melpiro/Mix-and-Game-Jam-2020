#pragma once


#include <stdlib.h>
#include <ctime>
#include "Math/BigInt.h"
#include "Math/MathFunctions.h"

namespace O{
namespace math {
namespace rdm {

	int randInt(const int & min, const int& max);
	BigInt randBigInt(const BigInt& min, const BigInt& max);
	double randDouble(const double& a, const double& b);
	double randDouble(const double& a, const double& b, const int& nb_digit);
	float randFloat(const float& a, const float& b);
	float randFloat(const float& a, const float& b, const int& nb_digit);
}
}
}