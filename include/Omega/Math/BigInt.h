#pragma once

//#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iostream>
#include <sstream>


namespace O
{
namespace math
{
	typedef long long ll;
	const int maxn = 1e2 + 14, lg = 15;

	const int base = 1000000000;
	const int base_digits = 9;

	typedef std::vector<long long> vll;

	class BigInt
	{
	public:

		BigInt();
		BigInt(long long v);
		BigInt(const std::string& s);

		void operator=(const BigInt& v);
		void operator=(long long v);

		BigInt operator+(const BigInt& v) const;

		BigInt operator-(const BigInt& v) const;

		void operator*=(int v);

		BigInt operator*(int v) const;

		void operator*=(long long v);

		BigInt operator*(long long v) const;

		friend std::pair<BigInt, BigInt> divmod(const BigInt& a1, const BigInt& b1);

		static BigInt rand(int n);

		bool isPair();

		BigInt operator/(const BigInt& v) const;

		BigInt operator%(const BigInt& v) const;

		void operator/=(int v);

		BigInt operator/(int v) const;

		int operator%(int v) const;

		void operator+=(const BigInt& v);

		void operator-=(const BigInt& v);

		void operator*=(const BigInt& v);

		void operator/=(const BigInt& v);

		bool operator<(const BigInt& v) const;

		bool operator>(const BigInt& v) const;

		bool operator<=(const BigInt& v) const;

		bool operator>=(const BigInt& v) const;

		bool operator==(const BigInt& v) const;

		bool operator!=(const BigInt& v) const;

		void trim();

		bool isZero() const;
		
		BigInt operator-() const;

		BigInt abs() const;

		long long longValue() const;

		friend BigInt gcd(const BigInt& a, const BigInt& b);

		friend BigInt lcm(const BigInt& a, const BigInt& b);

		void read(const std::string& s);

		friend std::istream& operator>> (std::istream& stream, BigInt& v);

		friend std::ostream& operator<<( std::ostream& stream, const BigInt& v);

		static std::vector<int> convert_base(const std::vector<int>& a, int old_digits, int new_digits);

		static vll karatsubaMultiply(const vll& a, const vll& b);

		BigInt operator*(const BigInt& v) const;

		int size() const;

		BigInt operator^(const BigInt& v);

		std::string to_string();

		int sumof();


	private:
		std::vector<int> a;
		int sign;

	};


}
	
} 
