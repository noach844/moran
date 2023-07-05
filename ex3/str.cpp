#include "str.h"

//-----------------------------------------------------------------------------------------------//
Str::Str() : Str("none")
{
}
//-----------------------------------------------------------------------------------------------//
Str::Str(const Str& other) : m_str(nullptr)
{
	*this = other;
}
//-----------------------------------------------------------------------------------------------//
Str::Str(const char* str)
{
	m_str = new char[strlen(str) + 1];
	strcpy(m_str, str);
}
//-----------------------------------------------------------------------------------------------//
Str::~Str()
{
	if (m_str)
		delete m_str;
}
//-----------------------------------------------------------------------------------------------//
bool Str::operator==(const Str& other) const
{
	return(strcmp(m_str, other.m_str) == 0);
}
//-----------------------------------------------------------------------------------------------//
bool Str::operator!=(const Str& other) const
{
	return !(*this == other);
}
//-----------------------------------------------------------------------------------------------//
bool Str::operator>(const Str& other) const
{
	return(strcmp(m_str, other.m_str) > 0);
}
//-----------------------------------------------------------------------------------------------//
bool Str::operator<(const Str& other) const
{
	return(strcmp(m_str, other.m_str) < 0);
}
//-----------------------------------------------------------------------------------------------//
const Str& Str::operator=(const Str& other)
{
	if (this != &other)
	{
		if (m_str)
			delete m_str;

		m_str = new char[strlen(other.m_str) + 1];
		strcpy(m_str, other.m_str);
	}

	return *this;
}
//-----------------------------------------------------------------------------------------------//
const Str& Str::operator=(const char* str)
{
	if (m_str)
		delete m_str;

	m_str = new char[strlen(str) + 1];
	strcpy(m_str, str);

	return *this;
}
//-----------------------------------------------------------------------------------------------//
char& Str::operator[](int index) const
{
	return m_str[index];
}
//-----------------------------------------------------------------------------------------------//
const Str& Str::operator++()
{
	for (int i = 0; (unsigned int)i < strlen(m_str); ++i)
		++(m_str[i]);

	return *this;
}
//-----------------------------------------------------------------------------------------------//
Str	Str::operator++(int)
{
	Str s(*this);

	++(*this);

	return s;
}
//-----------------------------------------------------------------------------------------------//
int	Str::operator()(char ch) const
{
	int len = strlen(m_str);
	for (int i = 0; i < len; ++i)
	{
		if (m_str[i] == ch)
			return i;
	}

	return -2;
}
//-----------------------------------------------------------------------------------------------//
Str	Str::operator+(const Str& other) const
{
	Str s(m_str);

	s += other;

	return s;
}
//-----------------------------------------------------------------------------------------------//
const Str& Str::operator+=(const Str& other)
{
	char* t = new char[strlen(m_str) + strlen(other.m_str) + 1];
	strcpy(t, m_str);
	strcat(t, other.m_str);

	delete m_str;
	m_str = t;

	return *this;
}
//-----------------------------------------------------------------------------------------------//
Str::operator int() const
{
	return strlen(m_str);
}
//-----------------------------------------------------------------------------------------------//
Str operator+(const char* str, const Str& other)
{
	Str s(str);

	s += other;

	return s;
}
//-----------------------------------------------------------------------------------------------//
Str operator*(int num, const Str& other)
{
	Str s(other);

	for (int i = 0; i < num - 1; ++i)
		s += other;

	return s;
}
//-----------------------------------------------------------------------------------------------//