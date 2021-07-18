#include <thread>
#include <iostream>
#include "gol.hpp"

using namespace std::chrono_literals;

#ifndef SLEEP_TIME_MS
#define SLEEP_TIME_MS 50
#endif

gol::gol(colony& colony, printer& printer) : m_colony(colony),
											 m_printer(printer) { }

void gol::run(size_t generations)
{
	clear_screen();
	for(size_t i = 0; i <= generations; ++i)
	{
		move_cursor();
		std::cout << "Generation " << i << "/" << generations << std::endl;
		m_colony.print(m_printer);
		m_colony.next_gen();
		std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME_MS));
	}
}
void gol::clear_screen()
{
	std::cout << "\033[2J";
}

void gol::move_cursor()
{
	std::cout << "\033[1;1H";
}