#include "Math/Matrix.h"

namespace O
{
    namespace math
    {
        Matrix<double> create2DRotationMatrixDeg(double const& angle)
        {
            return create2DRotationMatrixRad(math::ToRad(angle));
        }
        Matrix<double> create2DRotationMatrixRad(double const& angle)
        {
            Matrix<double> matrix(2,2,0);
            matrix[0][0] = std::cos(angle);
            matrix[0][1] = -std::sin(angle);
            matrix[1][0] = std::sin(angle);
            matrix[1][1] = std::cos(angle);

            return matrix;
        }
        Matrix<float> create2DRotationMatrixDegf(float const& angle)
        {
            return create2DRotationMatrixRadf(math::ToRad(angle));
        }
        Matrix<float> create2DRotationMatrixRadf(float const& angle)
        {
            Matrix<float> matrix(2,2,0);
            matrix[0][0] = std::cos(angle);
            matrix[0][1] = -std::sin(angle);
            matrix[1][0] = std::sin(angle);
            matrix[1][1] = std::cos(angle);

            return matrix;
        }

        sf::Vector2f rotatePointDeg(sf::Vector2f const& point, float const& angle)
        {
            return rotatePointRad(point, math::ToRad(angle));
        }
        sf::Vector2f rotatePointRad(sf::Vector2f const& point, float const& angle)
        {
            return sf::Vector2f(
                point.x * cos(angle) - point.y * std::sin(angle),
                point.x * sin(angle) + point.y * std::cos(angle)
            );
        }


        Matrix<double> create3DRotationMatrixAroundXDeg(double const& angle)
        {
            return create3DRotationMatrixAroundXRad(math::ToRad(angle));
        }
        Matrix<double> create3DRotationMatrixAroundYDeg(double const& angle)
        {
            return create3DRotationMatrixAroundYRad(math::ToRad(angle));
        }
        Matrix<double> create3DRotationMatrixAroundZDeg(double const& angle)
        {
            return create3DRotationMatrixAroundZRad(math::ToRad(angle));
        }
        Matrix<double> create3DRotationMatrixAroundXRad(double const& angle)
        {
            Matrix<double> matrix(3,3,0);
            matrix[0][0] = 1;
            matrix[0][1] = 0;
            matrix[0][2] = 0;
            matrix[1][0] = 0;
            matrix[1][1] = cos(angle);
            matrix[1][2] = -sin(angle);
            matrix[2][0] = 0;
            matrix[2][1] = sin(angle);
            matrix[2][2] = cos(angle);

            return matrix;
        }
        Matrix<double> create3DRotationMatrixAroundYRad(double const& angle)
        {
            Matrix<double> matrix(3,3,0);
            matrix[0][0] = cos(angle);
            matrix[0][1] = 0;
            matrix[0][2] = sin(angle);
            matrix[1][0] = 0;
            matrix[1][1] = 1;
            matrix[1][2] = 0;
            matrix[2][0] = -sin(angle);
            matrix[2][1] = 0;
            matrix[2][2] = cos(angle);

            return matrix;
        }
        Matrix<double> create3DRotationMatrixAroundZRad(double const& angle)
        {
            Matrix<double> matrix(3,3,0);
            matrix[0][0] = cos(angle);
            matrix[0][1] = -sin(angle);
            matrix[0][2] = 0;
            matrix[1][0] = sin(angle);
            matrix[1][1] = cos(angle);
            matrix[1][2] = 0;
            matrix[2][0] = 0;
            matrix[2][1] = 0;
            matrix[2][2] = 1;

            return matrix;
        }

        Matrix<float> create3DRotationMatrixAroundXDegf(float const& angle)
        {
            return create3DRotationMatrixAroundXRadf(math::ToRad(angle));
        }
        Matrix<float> create3DRotationMatrixAroundYDegf(float const& angle)
        {
            return create3DRotationMatrixAroundYRadf(math::ToRad(angle));
        }
        Matrix<float> create3DRotationMatrixAroundZDegf(float const& angle)
        {
            return create3DRotationMatrixAroundZRadf(math::ToRad(angle));
        }
        Matrix<float> create3DRotationMatrixAroundXRadf(float const& angle)
        {
            Matrix<float> matrix(3,3,0);
            matrix[0][0] = 1;
            matrix[0][1] = 0;
            matrix[0][2] = 0;
            matrix[1][0] = 0;
            matrix[1][1] = cos(angle);
            matrix[1][2] = -sin(angle);
            matrix[2][0] = 0;
            matrix[2][1] = sin(angle);
            matrix[2][2] = cos(angle);
        }
        Matrix<float> create3DRotationMatrixAroundYRadf(float const& angle)
        {
            Matrix<float> matrix(3,3,0);
            matrix[0][0] = cos(angle);
            matrix[0][1] = 0;
            matrix[0][2] = sin(angle);
            matrix[1][0] = 0;
            matrix[1][1] = 1;
            matrix[1][2] = 0;
            matrix[2][0] = -sin(angle);
            matrix[2][1] = 0;
            matrix[2][2] = cos(angle);

            return matrix;
        }
        Matrix<float> create3DRotationMatrixAroundZRadf(float const& angle)
        {
            Matrix<float> matrix(3,3,0);
            matrix[0][0] = cos(angle);
            matrix[0][1] = -sin(angle);
            matrix[0][2] = 0;
            matrix[1][0] = sin(angle);
            matrix[1][1] = cos(angle);
            matrix[1][2] = 0;
            matrix[2][0] = 0;
            matrix[2][1] = 0;
            matrix[2][2] = 1;

            return matrix;
        }
    } // namespace math
    
} // namespace O
