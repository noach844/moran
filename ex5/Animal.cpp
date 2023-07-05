#include "Animal.h"
Animal::Animal(): m_color(nullptr) {
	m_color=strdup("gray");
	m_childCount = 0;
	m_avgLifetime = 0;
}
Animal::Animal(const char* color, int childs, float avgLifetime) :m_color(nullptr) {
	m_color = strdup(color);
	m_childCount = childs;
	m_avgLifetime = avgLifetime;
}
Animal::Animal(ifstream& in_file) {
	int n;
	in_file.read((char*)&n, sizeof(n));
	char* name = new char[n + 1];
	in_file.read(name, n);
	name[n] = '\0';
	m_color = strdup(name);
	in_file.read((char*)&m_childCount, sizeof(m_childCount));
	in_file.read((char*)&m_avgLifetime, sizeof(m_avgLifetime));
}

Animal:: ~Animal() {
	delete m_color;
}
const char* Animal::GetColor() const {
	return m_color;
 }
int	Animal::GetChildCount() const {
	return m_childCount;
}
float Animal::GetLifetime() const {
	return m_avgLifetime;
}