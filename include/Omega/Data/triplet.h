#pragma once

namespace O{
	namespace data {

		template<typename T, typename U, typename V>
		class triplet;

		template<typename T, typename U, typename V>
		triplet<T, U, V> make_triplet(T first, U second, V third);

		template<typename T, typename U, typename V>
		class triplet
		{
		public:
			triplet() {first = T();second = U();third = V();}
			triplet(T _first, U _second, V _third) {first = _first;second = _second;third = _third;}
		
			T first;
			U second;
			V third;
		};
		
	}

	namespace data {
		template<typename T, typename U, typename V>
		inline triplet<T, U, V> make_triplet(T first, U second, V third)
		{
			triplet<T, U, V> r;
			r.first = first;
			r.second = second;
			r.third = third;

			return r;
		}
	}
}
