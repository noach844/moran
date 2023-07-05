#ifndef SRC_SET_H_
#define SRC_SET_H_

#include<vector>
#include<algorithm>
#include<typeinfo>
using namespace std;

#include "objects.h"
class Set : public Object {
private:
	Object** team;
	int size1;
public: 
	Set(int id) :Object(id), size1(0) {
		team = new Object * ();
	}
	Set(Set& other):Object(other.id), size1(other.size1),team(other.team){}
	virtual ~Set() {};
	bool add(Object& other)
	{
		bool chack = false;
		for (int i = 0; i < size1; i++)
		{
			if (team[i]->id == other.id)
			{
				chack = true;
			}
		}
		if (chack == true)
			return false;
		else
		{
			if (typeid(other) == typeid(Student))
			{
				team[size1] = new Student(other.id);
				size1++;
				return true;
			}
			if (typeid(other) == typeid(Orange))
			{
				team[size1] = new Orange(other.id);
				size1++;
				return true;
			}
			if (typeid(other) == typeid(Phone))
			{
				team[size1] = new Phone(other.id);
				size1++;
				return true;
			}
			if (typeid(other) == typeid(Set))
			{
				team[size1] = new Set(other.id);
				size1++;
				return true;
			}
		}
	}
	void remove(int id) {
		Object** temp = new Object * [size1 - 1];
		for (int i = 0; i < size1; i++)
		{
			if (team[i]->id != id)
				temp[i] = team[i];
			if (team[i]->id == id)
			{
				for (int t = i; t < size1; t++)
				{
					temp[t] = team[t + 1];
				}
				i = size1;
			}
		}
		delete[] team;
		team = temp;
		size1 = size1 - 1;
	}
	bool contains(int id) {
		for (int i = 0; i < size1; i++)
		{
			if (team[i]->id == id)
				return true;
		}
		return false;
	}
	int size() {
		return size1;
	}
	int deepSize() {
		int sum = 0;
		for (int i = 0; i < this->size1; i++)
		{
			sum = sum + 1;
			if (typeid(this->team[i]) == typeid(Set))
			{
				sum= sum + ((Set*)team[i])->deepSize();
			}
		}
		return sum;
	}
};





#endif /* SRC_SET_H_ */
