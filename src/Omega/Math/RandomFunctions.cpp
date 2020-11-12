#include "Math/RandomFunctions.h"

namespace O{
namespace math {
namespace rdm {

	int randInt(const int& min, const int& max)
	{
		if (max - min == 0) return min;
		return min + (rand() % (max - min));
	}
	BigInt randBigInt(const BigInt& min, const BigInt& max)
	{
		std::string str;
		size_t mis = min.size();
		size_t mas = max.size();
		size_t size = 0;
		if (mis == mas) size = mis;
		else size = math::rdm::randInt(mis, mas);
		for (size_t i = 0; i < size; i++)
		{
			str += randInt('0','9' + 1);
		}
		return BigInt(str);
	}

	double randDouble(const double& a, const double& b) {
		return ((double)rand() / (double)RAND_MAX) * (b - a) + a;
	}

	double randDouble(const double& a, const double& b, const int& nb_digit)
	{
		double mult = std::pow(10, nb_digit);
		return ((double)((int)(randDouble(a,b) * mult))) / mult;
	}

	float randFloat(const float& a, const float& b) {
		return ((float)rand() / (float)RAND_MAX) * (b - a) + a;
	}

	float randFloat(const float& a, const float& b, const int& nb_digit)
	{
		float mult = std::pow(10, nb_digit);
		return ((float)((int)(randDouble(a,b) * mult))) / mult;
	}
}
}
}