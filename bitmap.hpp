#pragma once
#include <vector>
#include <istream>
#include <variant>

class bitmap
{
 public:
	bitmap(size_t rows, size_t cols);
	std::vector<bool>& operator[](size_t i);
	const std::vector<bool>& operator[](size_t i) const;
	size_t rows() const;
	size_t cols() const;
	bitmap add_sentinels() const;
 private:
	std::vector<std::vector<bool>> m_map;
	size_t m_rows, m_cols;
};
class bitmap_factory
{
 public:
	bitmap_factory() = delete;
	bitmap_factory(const bitmap_factory&) = delete;
	bitmap_factory(bitmap_factory&&) = delete;
	static std::variant<bitmap,std::string> from_stream(size_t rows, size_t cols, std::istream& is);
};




