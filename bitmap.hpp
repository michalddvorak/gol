#pragma once

#include <vector>
#include <istream>
#include <variant>

class bitmap
{
 public:
	bitmap(size_t rows, size_t cols);
	
	bool* operator [](size_t i);
	const bool* operator [](size_t i) const;
	
	bitmap(const bitmap& other);
	bitmap(bitmap&& other) noexcept;
	bitmap& operator =(bitmap other) noexcept;
	~bitmap();
	friend void swap(bitmap& a, bitmap& b) noexcept;
	void swap(bitmap& other) noexcept;
	
	size_t rows() const;
	size_t cols() const;
	bitmap add_sentinels() const;
 private:
	void init_internal_array();
	size_t m_rows, m_cols;
	bool** m_interal_array;
	bool* m_actual_array;
};


class bitmap_factory
{
 public:
	bitmap_factory() = delete;
	bitmap_factory(const bitmap_factory&) = delete;
	bitmap_factory(bitmap_factory&&) = delete;
	static std::variant<bitmap, std::string> from_stream(size_t rows, size_t cols, std::istream& is);
};




