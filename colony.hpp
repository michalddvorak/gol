#pragma once

#include <array>
#include "bitmap.hpp"
#include "printer.hpp"


class colony
{
 public:
	explicit colony(const bitmap& b);
	void next_gen();
	void print(const printer& p) const;
 
 private:
	
	static bitmap add_sentinels(const bitmap& bm);
	static size_t get_nbhood(const bitmap& bm, size_t i, size_t j);
	static constexpr bool table[1 << 9] = {
			false, false, false, false, false, false, false, true, false, false, false, true, false, true, true, false,
			false, false, false, true, false, true, true, true, false, true, true, true, true, true, true, false,
			false, false, false, true, false, true, true, false, false, true, true, false, true, false, false, false,
			false, true, true, true, true, true, true, false, true, true, true, false, true, false, false, false,
			false, false, false, true, false, true, true, false, false, true, true, false, true, false, false, false,
			false, true, true, true, true, true, true, false, true, true, true, false, true, false, false, false,
			false, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			true, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			false, false, false, true, false, true, true, false, false, true, true, false, true, false, false, false,
			false, true, true, true, true, true, true, false, true, true, true, false, true, false, false, false,
			false, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			true, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			false, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			true, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			false, false, false, true, false, true, true, false, false, true, true, false, true, false, false, false,
			false, true, true, true, true, true, true, false, true, true, true, false, true, false, false, false,
			false, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			true, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			false, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			true, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			false, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			true, true, true, false, true, false, false, false, true, false, false, false, false, false, false, false,
			true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
			false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
	bitmap new_map;
	bitmap last_map;
};







