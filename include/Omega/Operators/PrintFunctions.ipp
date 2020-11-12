#include "Operators/PrintFunctions.h"


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	os << "\n[";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)
			os << ", ";
	}
	os << "]";
	return os;
}



template<typename T>
inline std::ostream& operator<<(std::ostream& os, const sf::Vector2<T>& v)
{
	os << '(';
	os << v.x;
	os << ',';
	os << v.y;
	os << ')';
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const sf::Vector3<T>& v)
{
	os << '(';
	os << v.x;
	os << ',';
	os << v.y;
	os << ',';
	os << v.z;
	os << ')';
	return os;
}

template<typename T, typename J>
inline std::ostream& operator<<(std::ostream& os, const std::pair<T, J>& v)
{
	os << '(';
	os << v.first;
	os << ',';
	os << v.second;
	os << ')';
	return os;
}

template<typename T, typename J, typename K>
inline std::ostream& operator<<(std::ostream& os, const std::tuple<T, J, K>& v)
{
	T a;
	J b;
	K c;
	std::tie(a, b, c) = v;
	os << '(';
	os << a;
	os << ',';
	os << b;
	os << ',';
	os << c;
	os << ')';

	return os;
}

template<typename T, typename J, typename K>
inline std::ostream& operator<<(std::ostream& os, const O::data::triplet<T, J, K>& v)
{
	os << '(';
	os << v.first;
	os << ',';
	os << v.second;
	os << ',';
	os << v.third;
	os << ')';

	return os;
}


