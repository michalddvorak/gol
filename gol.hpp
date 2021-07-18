#pragma once

#include "colony.hpp"

class gol
{
 public:
	gol(colony& colony, printer& printer);
	void run(size_t generation);
 private:
	static void clear_screen();
	static void move_cursor();
	colony& m_colony;
	printer& m_printer;
};




