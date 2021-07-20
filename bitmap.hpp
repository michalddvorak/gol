#pragma once

#include <istream>
#include <variant>
#include <string>
#include "matrix.hpp"

using bitmap = matrix<bool>;

class bitmap_factory
{
 public:
	bitmap_factory() = delete;
	bitmap_factory(const bitmap_factory&) = delete;
	bitmap_factory(bitmap_factory&&) = delete;
	static std::variant<bitmap, std::string> from_stream(size_t rows, size_t cols, std::istream& is);
};




