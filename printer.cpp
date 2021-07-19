#include <iostream>
#include "printer.hpp"


printer::printer(std::string alive, std::string dead) : m_strs {std::move(dead), std::move(alive)} { }
void printer::print(const bitmap& b, size_t rstart, size_t rend, size_t cstart, size_t cend) const
{
	for(size_t i = rstart; i < rend; ++i, std::cout << "\n")
		for(size_t j = cstart; j < cend; ++j)
			std::cout << m_strs[b[i][j]];
}
