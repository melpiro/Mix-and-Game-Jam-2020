#include "Math/Complex.h"

namespace O{
namespace math{

Complex::Complex()
{

}


Complex::Complex(const double& r, const double& i)
{
    this->r = r;
    this->i = i;
}

double Complex::module() const
{
    return std::pow(r, 2 ) + std::pow(i, 2 );
}


double Complex::argument() const
{
    return std::atan2(i, r);
}

Complex operator+(Complex c1,Complex c2)
{
    return Complex(c1.r + c2.r, c1.i + c2.i);
}
Complex operator-(Complex c1,Complex c2)
{
    return Complex(c1.r - c2.r, c1.i - c2.i);
}
Complex operator*(Complex c1,Complex c2)
{
    return Complex(c1.r * c2.r - c1.i * c2.i, c1.r * c2.i + c1.i * c2.r);
}


Complex operator/(Complex c1,double c2)
{
    return Complex(c1.r/c2, c1.i/c2);
}
Complex operator/(double c1,Complex c2)
{
    return Complex(c1*c2.r, - c1*c2.i) / (std::pow(c2.r,2) + std::pow(c2.i,2));
}
Complex operator/(Complex c1,Complex c2)
{
    return Complex(c1.r*c2.r+c1.i*c2.i, c1.i*c2.r - c1.r*c2.i) / (std::pow(c2.r,2) + std::pow(c2.i,2));
}

std::ostream& operator<<(std::ostream& os,Complex c)
{
    os << c.r <<" + "<<c.i<<"i"; 
    return os;
}

sf::Vector2f convertToVector(Complex c)
{
    return sf::Vector2f(c.r, c.i);
}
}}