#pragma once
#include <utility>
template<typename T>
class matrix
{
 public:
	matrix(size_t rows, size_t cols) : m_rows(rows),
									   m_cols(cols),
									   m_interal_array(new T* [rows]),
									   m_actual_array(new T[rows * cols])
	{
		init_internal_array();
	}
	
	T* operator [](size_t i)
	{
		return m_interal_array[i];
	}
	const T* operator [](size_t i) const
	{
		return m_interal_array[i];
	}
	
	matrix(const matrix& other) : m_rows(other.m_rows),
								  m_cols(other.m_cols),
								  m_interal_array(new T* [m_rows]),
								  m_actual_array(new T[m_rows * m_cols])
	{
		std::copy(other.m_actual_array, other.m_actual_array + m_rows * m_cols, m_actual_array);
		init_internal_array();
	}
	matrix(matrix&& other) noexcept: m_rows(other.m_rows),
									 m_cols(other.m_cols),
									 m_interal_array(std::exchange(other.m_interal_array, nullptr)),
									 m_actual_array(std::exchange(other.m_actual_array, nullptr)) { }
	
	matrix& operator =(matrix other) noexcept
	{
		other.swap(*this);
		return *this;
	}
	~matrix()
	{
		delete[] m_actual_array;
		delete[] m_interal_array;
	}
	template<typename X>
	friend void swap(matrix<X>& a, matrix<X>& b) noexcept;
	void swap(matrix& other) noexcept
	{
		std::swap(m_interal_array, other.m_interal_array);
		std::swap(m_actual_array, other.m_actual_array);
		std::swap(m_rows, other.m_rows);
		std::swap(m_cols, other.m_cols);
	}
	
	size_t rows() const
	{
		return m_rows;
	}
	size_t cols() const
	{
		return m_cols;
	}
 private:
	void init_internal_array()
	{
		for(size_t i = 0; i < m_rows; ++i)
			m_interal_array[i] = m_actual_array + i * m_cols;
	}
	size_t m_rows, m_cols;
	T** m_interal_array;
	T* m_actual_array;
};

template<typename T>
void swap(matrix<T>& a, matrix<T>& b) noexcept
{
	a.swap(b);
}





