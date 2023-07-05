#include "Person.h"
Person::Person() : m_name(nullptr), m_id(0) {};
Person::Person(const char* name, int id): m_id(id), m_name(nullptr) {
	SetName(name);
}
Person::Person(const Person& other) :m_name(nullptr), m_id(other.m_id) {
	SetName(other.m_name);
}
Person::~Person() {
	if(m_name)
	delete m_name;
}
void Person::SetName(const char* newName) {
	if (m_name)
		delete m_name;
	if (newName) {
		m_name = _strdup(newName);
	}
}
void Person::SetId(int newId) {
	m_id = newId;
}
char* Person::GetName()const {
	return m_name;
}
int Person::GetId()const {
	return m_id;
}
