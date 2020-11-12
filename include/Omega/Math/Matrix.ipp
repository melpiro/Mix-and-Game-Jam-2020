

namespace O{
namespace math{
    
template<class T>
inline Matrix<T>::Matrix() :
    m_matrix(0)
{

}
template<class T>
inline Matrix<T>::Matrix(const size_t& nb_line, const size_t& nb_collumn, const T& value)
{
    for (size_t i = 0; i <nb_line; i++)
    {
        std::vector<T> valuesLine(0);
        for (size_t j = 0; j < nb_collumn; j++)
        {
            valuesLine.push_back(value);
        }
        
        m_matrix.push_back(valuesLine);
    }

    this->nb_line = nb_line;
    this->nb_col = nb_collumn;
    
}
template<class T>
inline void Matrix<T>::setValue(const size_t& line_index, const size_t& collumn_index, T value)
{
    m_matrix[line_index][collumn_index] = value;
}
template<class T>
inline void Matrix<T>::createCollumnFrom(const std::vector<T>& vector)
{
    nb_col = 1;
    nb_line = vector.size();
    m_matrix = std::vector<std::vector<T>>( vector.size() );
    for (size_t i = 0; i < nb_line; i++)
    {
        m_matrix[i] = std::vector<T> {vector[i]};
    }
}
template<class T>
inline void Matrix<T>::createLineFrom(const std::vector<T>& vector)
{
    nb_col = vector.size();
    nb_line = 1;
    m_matrix = std::vector<std::vector<T>>( 1 );
    for (size_t i = 0; i < nb_col; i++)
    {
        m_matrix[0].push_back(vector[i]);
    }
}
template<class T>
inline Matrix<T> Matrix<T>::getInvLineAndCollumnMatrix() const
{
    Matrix<T> res(nb_col, nb_line);
    for (size_t i = 0; i < nb_line; i++)
    {
        for (size_t j = 0; j < nb_col; j++)
        {
            res.setValue(j, i, getValue(i, j));
        }
        
    }
    return res;
}


template<typename T>
inline Matrix<T> operator+(Matrix<T> const& a, Matrix<T> const& b)
{
    if (a.getNbLine() == b.getNbLine() && a.getNbCollumn() == b.getNbCollumn())
    {
        Matrix<T> res(a.getNbLine(), a.getNbCollumn());
        for (size_t i = 0; i < a.getNbLine(); i++)
        {
            for (size_t j = 0; j < a.getNbCollumn(); j++)
            {
                res.setValue(i, j, a.getValue(i,j) + b.getValue(i,j));
            }
            
        }
        return res;
    }
    return Matrix<T>();
}
template<typename T>
inline Matrix<T> operator-(Matrix<T> const& a, Matrix<T> const& b)
{
    if (a.getNbLine() == b.getNbLine() && a.getNbCollumn() == b.getNbCollumn())
    {
        Matrix<T> res(a.getNbLine(), a.getNbCollumn());
        for (size_t i = 0; i < a.getNbLine(); i++)
        {
            for (size_t j = 0; j < a.getNbCollumn(); j++)
            {
                res.setValue(i, j, a.getValue(i,j) - b.getValue(i,j));
            }
            
        }
        return res;
    }
    return Matrix<T>();
}
template<typename T>
inline Matrix<T> operator*(Matrix<T> const& a, Matrix<T> const& b)
{
    if (a.getNbCollumn() == b.getNbLine())
    {
        Matrix<T> res(a.getNbLine(), b.getNbCollumn());

        for (size_t i = 0; i < res.getNbLine(); i++)
        {
            for (size_t j = 0; j < res.getNbCollumn(); j++)
            {
                T value = T();
                for (size_t m1 = 0; m1 < a.getNbCollumn(); m1++)
                {
                    value += a.getValue(i,m1) * b.getValue(m1, j);
                    
                    
                }

                res.setValue(i, j, value);
                
            }
            
        }
        return res;
        
    }
    else if (a.getNbLine() == b.getNbLine() && a.getNbCollumn() == b.getNbCollumn())
    {
        Matrix<T> res(a.getNbLine(), a.getNbCollumn());

        for (size_t i = 0; i < res.getNbLine(); i++)
        {
            for (size_t j = 0; j < res.getNbCollumn(); j++)
            {
                res.setValue(i, j, a.getValue(i,j) * b.getValue(i,j));
                
            }
            
        }
        return res;
    }
    return Matrix<T>();
}
template<typename T>
inline Matrix<T> operator*(Matrix<T> const& a, T const& b)
{
    
    Matrix<T> res(a.getNbLine(), a.getNbCollumn());
    for (size_t i = 0; i < a.getNbLine(); i++)
    {
        for (size_t j = 0; j < a.getNbCollumn(); j++)
        {
            res.setValue(i,j,a.getValue(i,j) * b);
        }
    }
    return res;
}
template<typename T>
inline std::vector<T>& Matrix<T>::operator[] (int line)
{
    return m_matrix[line];
}

template<typename T>
inline std::ostream& operator<<( std::ostream &flux, Matrix<T> const& m )
{
    if (m.getNbCollumn() == 0 || m.getNbLine() == 0)
    {
        std::cout << "|X|" <<std::endl;
    }
    flux << '\n';
    for (size_t i = 0; i < m.getNbLine(); i++)
    {
        flux << '|';

        for (size_t j = 0; j < m.getNbCollumn(); j++)
        {
            flux << m.getValue(i,j);
            if (j + 1 != m.getNbCollumn()) flux <<",";
            
        }

        flux << '|';

        flux<< '\n';
    }
    return flux;
}

template <typename T>
inline Matrix<T> convertToLineMatrix(sf::Vector2<T> vector)
{
    O::math::Matrix<T> mat(1,2);
    mat[0][0] = vector.x;
    mat[0][1] = vector.y;
    return mat;
}

template <typename T>
inline Matrix<T> convertToColMatrix(sf::Vector2<T> vector)
{
    O::math::Matrix<T> mat(2,1, T());
    mat[0][0] = vector.x;
    mat[1][0] = vector.y;
    return mat;
}

template <typename T>
inline sf::Vector2<T> convertToVector2(Matrix<T> mat)
{
    if (mat.getNbCollumn() == 1)
    {
        if (mat.getNbLine() == 2)
        {
            return sf::Vector2<T>(mat[0][0], mat[1][0]);
        }
    }
    else if (mat.getNbLine() == 1)
    {
        if (mat.getNbCollumn() == 2)
        {
            return sf::Vector2<T>(mat[0][0], mat[0][1]);
        }
    }
    std::cerr << "[O::math::Matrix::convertToVector2] invalid matrix size\n";
    return sf::Vector2<T>(T(),T());
}

template <typename T>
inline Matrix<T> convertToLineMatrix(sf::Vector3<T> vector)
{
    O::math::Matrix<T> mat(1,3, T());
    mat[0][0] = vector.x;
    mat[0][1] = vector.y;
    mat[0][2] = vector.z;
    return mat;
}
template <typename T>
inline Matrix<T> convertToColMatrix(sf::Vector3<T> vector)
{
    O::math::Matrix<T> mat(3,1, T());
    mat[0][0] = vector.x;
    mat[1][0] = vector.y;
    mat[2][0] = vector.z;
    return mat;
}

template <typename T>
inline sf::Vector3<T> convertToVector3(Matrix<T> mat)
{
    if (mat.getNbCollumn() == 1)
    {
        if (mat.getNbLine() == 3)
        {
            return sf::Vector3<T>(mat[0][0], mat[1][0], mat[2][0]);
        }
    }
    else if (mat.getNbLine() == 1)
    {
        if (mat.getNbCollumn() == 3)
        {
            return sf::Vector3<T>(mat[0][0], mat[0][1], mat[0][2]);
        }
    }
    std::cerr << "[O::math::Matrix::convertToVector3] invalid matrix size\n";
    return sf::Vector3<T>(T(),T(),T());
}

}}