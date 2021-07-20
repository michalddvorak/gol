#include "colony.hpp"


colony::colony(const bitmap& b) : new_map(add_sentinels(b)),
								  last_map(new_map) { }

size_t colony::get_nbhood(const bitmap& bm, size_t i, size_t j)
{
	return bm[i - 1][j - 1] // << 0
		   | bm[i - 1][j] << 1
		   | bm[i - 1][j + 1] << 2
		   | bm[i][j - 1] << 3
		   | bm[i][j] << 4
		   | bm[i][j + 1] << 5
		   | bm[i + 1][j - 1] << 6
		   | bm[i + 1][j] << 7
		   | bm[i + 1][j + 1] << 8;
}
void colony::next_gen()
{
	last_map = new_map;
	for(size_t i = 1; i < last_map.rows() - 1; ++i)
		for(size_t j = 1; j < last_map.cols() - 1; ++j)
			new_map[i][j] = table[get_nbhood(last_map, i, j)];
}
void colony::print(const printer& p) const
{
	p.print(new_map, 1, new_map.rows() - 1, 1, new_map.cols() - 1);
}
bitmap colony::add_sentinels(const bitmap& bm)
{
	bitmap new_bm(bm.rows() + 2, bm.cols() + 2);
	
	for(size_t i = 0; i < bm.rows() + 2; ++i)
		for(size_t j = 0; j < bm.cols() + 2; ++j)
			if(i == 0 || i == bm.rows() + 1
			   || j == 0 || j == bm.cols() + 1)
				new_bm[i][j] = false;
			else
				new_bm[i][j] = bm[i - 1][j - 1];
	return new_bm;
}
