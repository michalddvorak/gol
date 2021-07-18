#include "bitmap.hpp"

using namespace std::string_literals;

std::vector<bool>& bitmap::operator [](size_t i)
{
	return m_map[i];
}
bitmap::bitmap(size_t rows, size_t cols) : m_map(rows, std::vector<bool>(cols)),
										   m_rows(rows),
										   m_cols(cols) { }
const std::vector<bool>& bitmap::operator [](size_t i) const
{
	return m_map[i];
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
