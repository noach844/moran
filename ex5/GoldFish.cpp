#include "GoldFish.h"
GoldFish::GoldFish() :MammalsFish() {
	m_avgWeight = 0;
	m_avgLength = 0;
}
GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL)//init the GoldFish with a given attributes
	:MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)
{
	m_avgWeight = avgW;
	m_avgLength = avgL;
}
GoldFish::GoldFish(ifstream& in_file): MammalsFish(in_file)
{
	in_file.read((char*)&m_avgWeight, sizeof(m_avgWeight));
	in_file.read((char*)&m_avgLength, sizeof(m_avgLength));
}
GoldFish::~GoldFish()
{
}
float GoldFish::GetWeight() const {
	return m_avgWeight;
}
float GoldFish::GetLength() const {
	return m_avgLength;
}
