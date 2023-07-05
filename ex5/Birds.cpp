#include "Birds.h"
Birds::Birds() :Animal() {
	m_incubationTime = 0;
}
Birds::Birds(const char* color, int childs, float avgLifetime, float incubation) :Animal(color, childs, avgLifetime) {
	m_incubationTime = incubation;
}
Birds::Birds(ifstream& in_file):Animal(in_file)
{
	in_file.read((char*)&m_incubationTime, sizeof(m_incubationTime));
}
Birds:: ~Birds(){}
float Birds::GetIncubationTime() const {
	return m_incubationTime;
}