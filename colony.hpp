#pragma once
#include "bitmap.hpp"
#include "printer.hpp"

class colony
{
 public:
	explicit colony(bitmap b);
	void next_gen();
	void print(const printer& p) const;
	
 private:
	size_t neighbours_alive(size_t i, size_t j) const;
	bitmap m_map;
};




