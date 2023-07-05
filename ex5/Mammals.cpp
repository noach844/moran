#include "Mammals.h"
Mammals::Mammals():Animal() {
	m_pregnancyTime = 0;
	m_milkLiters = 0;
}
Mammals::Mammals(const char* color, int childs, float avgLifetime, float preg, float milk) :Animal(color, childs, avgLifetime) {
	m_pregnancyTime = preg;
	m_milkLiters = milk;
}
Mammals::Mammals(ifstream& in_file):Animal(in_file) {
	in_file.read((char*)&m_pregnancyTime, sizeof(m_pregnancyTime));
	in_file.read((char*)&m_milkLiters , sizeof(m_milkLiters));
}
Mammals::~Mammals() {}
float Mammals::GetPregnanceTime() const {
	return m_pregnancyTime;
}
float Mammals::GetMilk() const {
	return m_milkLiters;
}