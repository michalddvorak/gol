#pragma once

#include "bitmap.hpp"

class printer
{
 public:
	printer(std::string alive, std::string dead);
	void print(const bitmap& b) const;
 private:
	std::string m_strs[2];
};




