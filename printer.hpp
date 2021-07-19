#pragma once

#include "bitmap.hpp"

class printer
{
 public:
	printer(std::string alive, std::string dead);
	void print(const bitmap& bm, size_t rstart, size_t rend, size_t cstart, size_t cend) const;
 private:
	std::string m_strs[2];
};




