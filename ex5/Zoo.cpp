#include "Zoo.h"
#include "Horse.h"
#include "Flamingo.h"
#include "GoldFish.h"
#include "Mermaid.h"
Zoo::Zoo()
{
	m_name = nullptr;
	m_address = nullptr;
	m_ticketPrice = 0;
	m_openHours = nullptr;
	m_closeHours = nullptr;
	m_numOfAnimals = 0;
	m_animals = nullptr;
}
Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)
	: m_ticketPrice(ticket),
	m_numOfAnimals(0),
	m_animals(nullptr)
{
	m_name = strdup(name);
	m_address = strdup(address);
	m_openHours = strdup(open);
	m_closeHours = strdup(close);
}
Zoo::Zoo(ifstream& in_file) 
	{
		m_name = readTextFromFile(in_file);
		m_address = readTextFromFile(in_file);

		in_file.read((char*)&m_ticketPrice, sizeof(m_ticketPrice));

		m_openHours = readTextFromFile(in_file);
		m_closeHours = readTextFromFile(in_file);

		in_file.read((char*)&m_numOfAnimals, sizeof(m_numOfAnimals));

		m_animals = new Animal * [m_numOfAnimals];
		for (int i = 0; i < m_numOfAnimals; ++i)
		{
			Animal* a = createAnimalBin(in_file);
			m_animals[i] = a;
		}

}