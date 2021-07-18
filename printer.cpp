#include <iostream>
#include "printer.hpp"


printer::printer(std::string alive, std::string dead) : m_strs {std::move(dead), std::move(alive)} { }
void printer::print(const bitmap& b) const
{
	for(size_t i = 0; i < b.rows(); ++i, std::cout << "\n")
		for(size_t j = 0; j < b.cols(); ++j)
			std::cout << m_strs[b[i][j]];
}
