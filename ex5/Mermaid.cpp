#include "Mermaid.h"
Mermaid::Mermaid()
	: MammalsFish(),
	m_firstName(nullptr),
	m_lastName(nullptr)
{
}
Mermaid::Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName)//init the Mermaid with a given attributes
	:MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)
{
	m_firstName = strdup(firstName);
	m_lastName = strdup(lastName);
}
Mermaid::Mermaid(ifstream& in_file)
	:MammalsFish(in_file)
{
	int n;
	in_file.read((char*)&n, sizeof(n));
	char* firstName = new char[n + 1];
	in_file.read(firstName, n);
	firstName[n] = '\0';
	m_firstName = strdup(firstName);
	int t;
	in_file.read((char*)&t, sizeof(t));
	char* lastName = new char[t + 1];
	in_file.read(lastName, t);
	lastName[t] = '\0';
	m_lastName = strdup(lastName);
}
Mermaid::~Mermaid()
{
	if (m_firstName)
		delete m_firstName;

	m_firstName = nullptr;

	if (m_lastName)
		delete m_lastName;

	m_lastName = nullptr;
}
const char* Mermaid:: GetFirstName() const {
	return m_firstName;
}
const char* Mermaid::GetLastName() const {
	return m_lastName;
}