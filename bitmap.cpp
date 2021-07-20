#include "bitmap.hpp"

using namespace std::string_literals;

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

