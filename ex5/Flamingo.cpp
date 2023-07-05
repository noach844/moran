#include "Flamingo.h"
Flamingo::Flamingo():Birds() {
	m_avgHeight = 0;
}
Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight) :Birds(color, childs, avgLifetime, incubation) {
	m_avgHeight = avgHeight;
}
Flamingo::Flamingo(ifstream& in_file) :Birds(in_file) {
	in_file.read((char*)&m_avgHeight, sizeof(m_avgHeight));
}
Flamingo::~Flamingo(){}
float Flamingo::GetHeight() const {
	return m_avgHeight;
}