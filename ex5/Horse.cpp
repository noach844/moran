#include "Horse.h"
Horse::Horse()
	: Mammals(),
	m_type(nullptr)
{
}
Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type)//init the Horse with a given attributes
	:Mammals(color, childs, avgLifetime, preg, milk)
{
	m_type = strdup(type);
}
Horse::Horse(ifstream& in_file)
	:Mammals(in_file)
{
	int n;
	in_file.read((char*)&n, sizeof(n));
	char* thetype = new char[n + 1];
	in_file.read(thetype, n);
	thetype[n] = '\0';
	m_type = strdup(thetype);
}
Horse::~Horse()
{
	if (m_type)
		delete m_type;

	m_type = nullptr;
}
const char* Horse::GetType() const {
	return m_type;
}