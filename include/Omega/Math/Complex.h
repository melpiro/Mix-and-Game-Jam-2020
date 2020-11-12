#pragma once

#include <math.h>
#include <iostream>
#include <SFML/System/Vector2.hpp>
namespace O{
namespace math{
class Complex
{
public:
    Complex();
    Complex(const double& r, const double& i);

    double module() const;
    double argument() const;

    double r;
    double i;
    

};

Complex operator+(Complex c1,Complex c2);
Complex operator-(Complex c1,Complex c2);
Complex operator*(Complex c1,Complex c2);
Complex operator/(Complex c1,double c2);
Complex operator/(double c1,Complex c2);
Complex operator/(Complex c1,Complex c2);
std::ostream& operator<<(std::ostream& os,Complex c);


sf::Vector2f convertToVector(Complex c);

}}
