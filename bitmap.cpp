#include "bitmap.hpp"

using namespace std::string_literals;

bitmap::bitmap(size_t rows, size_t cols) : m_rows(rows),
										   m_cols(cols),
										   m_interal_array(new bool* [rows]),
										   m_actual_array(new bool[rows * cols])
{
	init_internal_array();
}


bitmap::bitmap(const bitmap& other) : m_rows(other.m_rows),
									  m_cols(other.m_cols),
									  m_interal_array(new bool* [m_rows]),
									  m_actual_array(new bool[m_rows * m_cols])
{
	std::copy(other.m_actual_array, other.m_actual_array + m_rows * m_cols, m_actual_array);
	init_internal_array();
}

bitmap::bitmap(bitmap&& other) noexcept: m_rows(other.m_rows),
										 m_cols(other.m_cols),
										 m_interal_array(std::exchange(other.m_interal_array, nullptr)),
										 m_actual_array(std::exchange(other.m_actual_array, nullptr)) { }

bitmap::~bitmap()
{
	delete[] m_actual_array;
	delete[] m_interal_array;
}


bitmap& bitmap::operator =(bitmap other) noexcept
{
	other.swap(*this);
	return *this;
}


void swap(bitmap& a, bitmap& b) noexcept
{
	a.swap(b);
}

void bitmap::swap(bitmap& other) noexcept
{
	using std::swap;
	swap(m_interal_array, other.m_interal_array);
	swap(m_actual_array, other.m_actual_array);
	swap(m_rows, other.m_rows);
	swap(m_cols, other.m_cols);
}

void bitmap::init_internal_array()
{
	for(size_t i = 0; i < m_rows; ++i)
		m_interal_array[i] = m_actual_array + i * m_cols;
}
bool* bitmap::operator [](size_t i)
{
	return m_interal_array[i];
}
const bool* bitmap::operator [](size_t i) const
{
	return m_interal_array[i];
}
size_t bitmap::rows() const
{
	return m_rows;
}
size_t bitmap::cols() const
{
	return m_cols;
}
std::variant<bitmap, std::string> bitmap_factory::from_stream(size_t rows, size_t cols, std::istream& is)
{
	bitmap bm(rows, cols);
	
	for(size_t i = 0; i < rows; ++i)
		for(size_t j = 0; j < cols; ++j)
		{
			char c;
			if(!(is >> c))
				return "Stream error";
			if(c == '0')
				bm[i][j] = false;
			else if(c == '1')
				bm[i][j] = true;
			else
				return "Invalid input character \'"s + c + "\'.";
		}
	return bm;
}
bitmap bitmap::add_sentinels() const
{
	bitmap bm(m_rows + 2, m_cols + 2);
	
	for(size_t i = 0; i < m_rows + 2; ++i)
		for(size_t j = 0; j < m_cols + 2; ++j)
			if(i == 0 || i == m_rows + 1
			   || j == 0 || j == m_cols + 1)
				bm[i][j] = false;
			else
				bm[i][j] = (*this)[i - 1][j - 1];
	return bm;
}

