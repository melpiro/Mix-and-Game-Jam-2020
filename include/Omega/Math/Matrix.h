#pragma once
#include <vector>
#include <iostream>
#include "MathFunctions.h"

namespace O{
namespace math{
    

template <class T>
class Matrix
{

public:
    Matrix();
    Matrix(const size_t& nb_line, const size_t& nb_collumn, const T& value = T());

    void setValue(const size_t& line_index, const size_t& collumn_index, T value);
    T getValue(const size_t& line_index, const size_t& collumn_index) const { return m_matrix[line_index][collumn_index];}
    size_t getNbCollumn() const { return nb_col; }
    size_t getNbLine() const  { return nb_line; }

    bool isEmpty() const {return (nb_line == 0 || nb_line == 0);}

    void createCollumnFrom(const std::vector<T>& vector);
    void createLineFrom(const std::vector<T>& vector);

    Matrix<T> getInvLineAndCollumnMatrix() const;
    
    std::vector<T>& operator[] (int);

    template <typename U>
    Matrix<U> operator()(Matrix<U> const& m )
    {
        if (m.getNbLine() == this->getNbLine() && m.getNbCollumn() == this->getNbCollumn())
        {
            Matrix<U> res(m.getNbLine(), m.getNbCollumn());
            for (size_t i = 0; i < m.getNbLine(); i++)
            {
                for (size_t j = 0; j < m.getNbCollumn(); j++)
                {
                    res.setValue(i, j, this->getValue(i,j)(m.getValue(i,j)));
                }
                
            }
            return res;
        }
        return Matrix<U>();

    }
    
private:
    std::vector<std::vector<T>> m_matrix;
    size_t nb_line = 0;
    size_t nb_col = 0;
};



template <typename T>
Matrix<T> operator+(Matrix<T> const& a, Matrix<T> const& b);
template <typename T>
Matrix<T> operator-(Matrix<T> const& a, Matrix<T> const& b);
template <typename T>
Matrix<T> operator*(Matrix<T> const& a, Matrix<T> const& b);
template <typename T>
Matrix<T> operator*(Matrix<T> const& a, T const& b);
template <typename T>
std::ostream& operator<<( std::ostream &flux, Matrix<T> const& m );



Matrix<double> create2DRotationMatrixDeg(double const& angle);
Matrix<double> create2DRotationMatrixRad(double const& angle);

Matrix<float> create2DRotationMatrixDegf(float const& angle);
Matrix<float> create2DRotationMatrixRadf(float const& angle);

sf::Vector2f rotatePointDeg(sf::Vector2f const& point, float const& angle);
sf::Vector2f rotatePointRad(sf::Vector2f const& point, float const& angle);


Matrix<double> create3DRotationMatrixAroundXDeg(double const& angle);
Matrix<double> create3DRotationMatrixAroundYDeg(double const& angle);
Matrix<double> create3DRotationMatrixAroundZDeg(double const& angle);
Matrix<double> create3DRotationMatrixAroundXRad(double const& angle);
Matrix<double> create3DRotationMatrixAroundYRad(double const& angle);
Matrix<double> create3DRotationMatrixAroundZRad(double const& angle);

Matrix<float> create3DRotationMatrixAroundXDegf(float const& angle);
Matrix<float> create3DRotationMatrixAroundYDegf(float const& angle);
Matrix<float> create3DRotationMatrixAroundZDegf(float const& angle);
Matrix<float> create3DRotationMatrixAroundXRadf(float const& angle);
Matrix<float> create3DRotationMatrixAroundYRadf(float const& angle);
Matrix<float> create3DRotationMatrixAroundZRadf(float const& angle);

template <typename T>
Matrix<T> convertToLineMatrix(sf::Vector2<T> const& vector);
template <typename T>
Matrix<T> convertToColMatrix(sf::Vector2<T> const& vector);

template <typename T>
sf::Vector2<T> convertToVector2(Matrix<T> const& mat);

template <typename T>
Matrix<T> convertToLineMatrix(sf::Vector3<T> const& vector);
template <typename T>
Matrix<T> convertToColMatrix(sf::Vector3<T> const& vector);

template <typename T>
sf::Vector3<T> convertToVector3(Matrix<T> const& mat);



}
}


#include "Matrix.ipp"