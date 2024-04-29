/*
* 
* The Vector.cpp are going to rebuilt the vector in stl with template class
*
* 
* 
* 
* 
*/

template<typename T>
class Vector
{
public:
	
	Vector();
	
	void push_back(T value);



private:
	T* m_Data;
	size_t m_size;



};