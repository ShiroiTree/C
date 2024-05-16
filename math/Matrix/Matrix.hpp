/*








*/

#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

typedef unsigned int size_T;

template<typename T,size_T x,size_T y>
class Matrix
{
public:
    Matrix();
    ~Matrix();

private:
    size_T m_X,m_Y;
    T** m_Data;
};




#endif


