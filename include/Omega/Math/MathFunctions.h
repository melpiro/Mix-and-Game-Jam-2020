#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>
#include "StaticValues.h"
#include <functional>

namespace O{
namespace math {
	template<typename T>
	double getCoefDir(const sf::Vector2<T>& p1, const sf::Vector2<T>& p2);

	template<typename T>
	double getDistance(const sf::Vector2<T>& origine, const sf::Vector2<T>& destination);
	
	template<typename T>
	double getDistance(const sf::Vector2<T>& origine);

	template<typename T>
	double getDistanceCarre(const sf::Vector2<T>& origine, const sf::Vector2<T>& destination);

	template<typename T>
	double getDistance(const T& ax, const T& ay, const T& bx, const T& by);
	
	template<typename T>
	double getDistance(const T& ax, const T& ay);

	template<typename T>
	double getDistanceCarre(const T& ax, const T& ay, const T& bx, const T& by);


	template<typename T>
	double getDirection(const sf::Vector2<T>& A, const sf::Vector2<T>& B);

	template<typename T>
	double getAngle(const sf::Vector2<T>& origine, const sf::Vector2<T>& destination);

	template<typename T>
	bool isAtLeft(const sf::Vector2<T>& p, double myRotation, const sf::Vector2<T>& target);
	template<typename T>
	bool isAtLeft(const sf::Vector2<T>& V1, const sf::Vector2<T>& V2);

	template<typename T>
	double getDirectionDeg(const sf::Vector2<T>& A, const sf::Vector2<T>& B);

	template<typename T>
	double getAngleDeg(const sf::Vector2<T>& origine, const sf::Vector2<T>& destination);

	template<typename T>
	T PGCD(const T& a, const T& b);

	template<typename T,typename J>
	T mod(const T& a, const J& b);

	template<typename T>
	bool isDivisibleBy(const T& num, const T& diviseur);
	template<typename T>
	bool isMultiple(const T& num, const T& multiple);


	double ToDeg(const double& rad);
	double ToRad(const double& deg);

	double round(const double& value, const int& nbChiffre);

	int getNbDigits(const int& nb);

	sf::Vector2f normalise(const sf::Vector2f& vec);
	double dot(const sf::Vector2f& a, const sf::Vector2f& b);

	std::function<double (double)> getDerivative(double (* function)(double));
	
}
}

#include "MathFunction.ipp"