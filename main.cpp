#include <sstream>
#include <iostream>
#include <fstream>
#include "overload.hpp"
#include "gol.hpp"

#define BLACK_SQUARE "\033[48;2;0;0;0m \033[0m"
#define WHITE_SQUARE "\033[48;2;255;255;255m \033[0m"


#ifndef ALIVE
#define ALIVE WHITE_SQUARE
#endif

#ifndef DEAD
#define DEAD BLACK_SQUARE
#endif

void help()
{
	std::cerr << "gol <filename> <generations>" << std::endl;
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		help();
		return 1;
	}
	
	std::ifstream ifs(argv[1]);
	if(!ifs.is_open())
	{
		std::cerr << "Could not open file \"" << argv[1] << "\"." << std::endl;
		return 1;
	}
	size_t generations;
	std::stringstream ss(argv[2]);
	if(!(ss >> generations))
	{
		std::cerr << "Invalid number of generations \"" << argv[2] << "\"." << std::endl;
		return 1;
	}
	
	size_t rows, cols;
	if(!(ifs >> rows >> cols))
	{
		std::cerr << "Could not parse dimensions from file." << std::endl;
		return 1;
	}
	auto bm = bitmap_factory::from_stream(rows, cols, ifs);
	return match(bm,
				 [](std::string err) {
					 std::cerr << err << std::endl;
					 return 1;
				 },
				 [&](bitmap bm) {
					 colony c(bm);
					 printer p(ALIVE, DEAD);
					 gol gol(c, p);
					 gol.run(generations);
					 return 0;
				 });
}
