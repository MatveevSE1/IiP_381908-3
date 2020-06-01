#ifndef BEAUTIFUL_H
#define BEAUTIFUL_H

#include <initializer_list>
#include <cassert>
#include <iostream>

template<class T>
class Beautiful
{
public:
	Beautiful(); //d
	Beautiful(int _size); //d
	Beautiful(const std::initializer_list<T>& list); // d using initializer list such as {1, 2, 3} ; USE Beautiful(list.size())
	Beautiful(const Beautiful& beautiful); //d
	~Beautiful(); //d

	int size(); // get size // d
	void clear(); //delete array // d
	//void erase(); // empty array but saves size
	void insert(T value, int index); // insert value before index d
	void remove(int index); // remove value on index pos d
	void popBack(); // delete last element d
	void pushBack(T value); // place element after the past d
	void resize(int _nSize); // new size of array but save elements // d
	void reallocate(int _nSize); // new size of array but elements are deleted // d

	T& operator[](int index); // d
	Beautiful& operator=(const Beautiful& beautiful); // d
	Beautiful& operator=(const std::initializer_list<T>& list); // d


	friend std::ostream& operator>>(std::ostream& out, const Beautiful<T>& beautiful); // FIX
	//friend std::istream& operator<<(std::istream& in, const Beautiful& beautiful); // FIX
private:
	T* m_data;
	int m_size;
};

template<typename T>
Beautiful<T>::Beautiful() : m_size(0), m_data(nullptr)
{ }

template<typename T>
Beautiful<T>::Beautiful(int _size) : m_size(_size)
{
	assert(_size >= 0);

	if (_size > 0)
		m_data = new T[m_size];
	else
		m_data = nullptr;
	for (int i = 0; i < m_size; i++)
		m_data[i] = 0;
}

template<typename T>
Beautiful<T>::Beautiful(const std::initializer_list<T>& list) : Beautiful(list.size())
{
	int count = 0;
	for (auto& x : list) {
		m_data[count] = x;
		++count;
	}

}

template<typename T>
Beautiful<T>::Beautiful(const Beautiful& beautiful)
{
	assert(this != &beautiful);

	m_size = beautiful.m_size;
	m_data = new T[m_size];
	for (int i = 0; i < m_size; i++) {
		m_data[i] = beautiful.m_data[i];
	}

}

template<typename T>
Beautiful<T>::~Beautiful()
{

	delete[] m_data;
}

template<typename T>
int Beautiful<T>::size()
{
	return m_size;
}

template<typename T>
void Beautiful<T>::clear()
{
	delete[] m_data;
	m_data = nullptr;
	m_size = 0;
	
}

template<typename T>
void Beautiful<T>::resize(int _nSize)
{
	if (_nSize == m_size) // already have needed array
		return;

	if (_nSize <= 0) { // empty array is ready
		clear();
		return;
	}
	T* data = new T[_nSize];
	if (m_size > 0) {
		auto elemsToCopy = (_nSize > m_size) ? m_size : _nSize; // return smallest size 
		for (int i = 0; i < elemsToCopy; i++) {
			data[i] = m_data[i];
		}
	}

	delete[] m_data;
	// finish copy here
	m_data = data;
	m_size = _nSize;

}

template<typename T>
void Beautiful<T>::reallocate(int _nSize)
{
	clear();

	if (_nSize <= 0) // empty array is ready
		return;
	
	m_data = new T[_nSize];
	m_size = _nSize;

}

template<typename T>
void Beautiful<T>::insert(T value, int index)
{
	assert(index >= 0 and index <= m_size);

	T* data = new T[m_size + 1];

	for (int before = 0; before < index; before++) {
		data[before] = m_data[before];
	}
	data[index] = value;

	for (int after = index; after < m_size; after++) {
		data[after + 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	++m_size;
}

template<typename T>
void Beautiful<T>::remove(int index)
{
	assert(index >= 0 and index <= m_size);

	if (m_size == 1) { // if it the last element
		clear();
		return;
	}

	T* data = new T[m_size - 1];

	for (int before = 0; before < index; before++) {
		data[before] = m_data[before];
	}

	for (int after = index; after < m_size; after++) {
		data[after - 1] = m_data[after];
	}

	delete[] m_data;
	m_data = data;
	--m_size;

}

template<typename T>
void Beautiful<T>::popBack()
{
	remove(m_size);
}


template<typename T>
void Beautiful<T>::pushBack(T value)
{
	insert(value, m_size);
}

template<typename T>
T& Beautiful<T>::operator[](int index)
{
	assert(index >= 0 and index < m_size);
	return m_data[index];
}

template<typename T>
Beautiful<T>& Beautiful<T>::operator=(const Beautiful<T>& beautiful)
{
	assert(this != &beautiful);

	m_size = beautiful.m_size;
	m_data = new T[m_size];
	for (int i = 0; i < m_size; i++) {
		m_data[i] = beautiful.m_data[i];
	}
	return *this;
}

template<typename T>
Beautiful<T>& Beautiful<T>::operator=(const std::initializer_list<T>& list)
{
	int count = 0;
	for (auto& x : list) {
		m_data[count] = x;
		++count;
	}
	return *this;
}

template<typename T>
std::ostream& operator>>(std::ostream& out, const Beautiful<T>& beautiful)
{
	for (int i = 0; i < beautiful.m_size; i++) {
		out << beautiful[i];
	}
	return out;
}
#endif

