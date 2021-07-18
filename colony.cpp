#include "colony.hpp"

colony::colony(bitmap b) : m_map(std::move(b)) { }
size_t colony::neighbours_alive(size_t i, size_t j) const
{
	size_t cnt = 0;
	if(i != 0)
		cnt += m_map[i - 1][j];
	if(j != 0)
		cnt += m_map[i][j - 1];
	if(i != 0 && j != 0)
		cnt += m_map[i - 1][j - 1];
	if(i != m_map.rows() - 1)
		cnt += m_map[i + 1][j];
	if(j != m_map.cols() - 1)
		cnt += m_map[i][j + 1];
	if(i != 0 && j != m_map.cols() - 1)
		cnt += m_map[i - 1][j + 1];
	if(i != m_map.rows() - 1 && j != 0)
		cnt += m_map[i + 1][j - 1];
	if(i != m_map.rows() - 1 && j != m_map.cols() - 1)
		cnt += m_map[i + 1][j + 1];
	return cnt;
}
void colony::next_gen()
{
	bitmap new_map(m_map.rows(), m_map.cols());
	for(size_t i = 0; i < m_map.rows(); ++i)
		for(size_t j = 0; j < m_map.cols(); ++j)
		{
			size_t nbs_alive = neighbours_alive(i, j);
			bool cur = m_map[i][j];
			if(nbs_alive == 3 || (cur && nbs_alive == 2))
				new_map[i][j] = true;
			else if(cur && (nbs_alive > 3 || nbs_alive < 2))
				new_map[i][j] = false;
		}
	m_map = new_map;
}
void colony::print(const printer& p) const
{
	p.print(m_map);
}
