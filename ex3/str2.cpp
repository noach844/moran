#include "str.h"
Str::Str():Str("none") {
}
Str::Str(const Str& other): m_str(nullptr) {
	*this = other;
}
Str::Str(const char* str) {
	m_str = strdup(str);
}
Str::~Str() {
	if(m_str)
		delete m_str;
}
bool Str::operator==(const Str& other) const {
	if (strcmp(m_str, other.m_str) == 0)
		return true;
	else
		return false;
}
bool Str::operator!=(const Str& other) const {
	if (strcmp(m_str, other.m_str) == 0)
		return false;
	else
		return true;
}
bool Str::operator>(const Str& other) const {
	if (strcmp(m_str, other.m_str) > 0)
		return true;
	else
		return false;
}
bool Str::operator<(const Str& other) const {
	if (strcmp(m_str, other.m_str) < 0)
		return true;
	else
		return false;
}
const Str& Str::operator=(const Str& other) {
	if (m_str)
		delete m_str;
	m_str = new char[strlen(other.m_str)+1];
	strcpy(m_str, other.m_str);
	return *this;
}
const Str& Str::operator=(const char* str)
{
	if (m_str)
		delete m_str;
	m_str = strdup(str);
	return *this;
}
char& Str::operator[](int index) const {
	if (m_str == nullptr)
		return m_str[0];
	if(strlen(m_str)>index)
		return m_str[index];
}
const Str& Str::operator++()
{
	for (int i = 0; (unsigned int)i < strlen(m_str); ++i)
		++(m_str[i]);

	return *this;
}
Str	Str::operator++(int)
{
	Str s(*this);

	++(*this);

	return s;
}
int	Str:: operator()(char ch) const {
	for (int i = 0; i < strlen(m_str); i++)
	{
		if (m_str[i] == ch)
			return i;
	}
	return -1;
}
Str	Str::operator+(const Str& other) const
{
	Str s(m_str);

	s += other;

	return s;
}
//Str Str::operator+(const Str& other) const {
//	if (other.m_str == nullptr)
//		return m_str;
//	if (m_str == nullptr)
//		return other.m_str;
//	char* newchar;
//	int len = strlen(m_str) + strlen(other.m_str);
//	newchar = new char[len];
//	for (int i = 0; i < strlen(m_str); i++) {
//		newchar[i] = m_str[i];
//	}
//	int z = 0;
//	for (int t = strlen(m_str + 1); t < strlen(other.m_str); t++)
//	{
//		newchar[t] = other.m_str[z];
//		z++;
//	}
//	return newchar;
//}
const Str& Str::operator+=(const Str& other)
{
	char* t = new char[strlen(m_str) + strlen(other.m_str) + 1];
	strcpy(t, m_str);
	strcat(t, other.m_str);

	delete m_str;
	m_str = t;

	return *this;
}
Str::operator int() const
{
	return strlen(m_str);
}
Str operator+(const char* str, const Str& other)
{
	Str s(str);

	s += other;

	return s;
}
Str operator*(int num, const Str& other)
{
	Str s(other);

	for (int i = 0; i < num - 1; ++i)
		s += other;

	return s;
}
