#include "Fish.h"
Fish::Fish() :Animal() {
	m_finCount = 0;
	m_gillsCount = 0;
}
Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills) : Animal(color, childs, avgLifetime) {
	m_finCount = fin;
	m_gillsCount =gills;
}
Fish::Fish(ifstream& in_file) : Animal(in_file) {
	in_file.read((char*)&m_finCount, sizeof(m_finCount));
	in_file.read((char*)&m_gillsCount, sizeof(m_gillsCount));
}
Fish::Fish(int fincount, int gillscount) :Animal() {
	m_finCount = fincount;
	m_gillsCount = gillscount;
}
Fish::~Fish(){}
int	Fish::GetFinCount() const {
	return m_finCount;
}
int	Fish::GetGillsCount() const {
	return m_gillsCount;
}