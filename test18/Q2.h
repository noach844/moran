
#ifndef SRC_Q2_H_
#define SRC_Q2_H_

#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Stream {
	vector<T> items;
public:
	Stream() : items(NULL){}
	Stream(vector<T> items1) :items(items1) {}
	void push(T t) {
		items.push_back(t);
	}

	vector<T> get() { return items; }
	Stream<T> distinct() {
		vector<T> newitem;
			newitem.push_back(items[0]);
			for (int i = 1; i < items.size(); i++)
			{
				auto it = find(newitem.begin(), newitem.end(),items[i]);
				if (it==newitem.end())
					newitem.push_back(items[i]);
			}
		Stream other(newitem);
		return other;
	}
	template<class Predicate>
	Stream<T> filter(Predicate p) {
		vector<T> newitem;
		for (int i = 0; i < items.size(); i++)
		{
			if (p(items[i]) == true)
				newitem.push_back(items[i]);
		}
		Stream other(newitem);
		return other;
	}
	template<class F>
	void forEach(F p) {
		for (int i = 0; i < items.size(); i++)
			p(items[i]);
	}
	template<class Binari>
	T reduce(T id, Binari x) {
		T result;
		result = x(id, items[0]);
		for (int i = 1; i < items.size(); i++)
		{
			result = x(result, items[i]);
		}
		return result;
	}
	template<class Predicate>
	bool allMatch(Predicate c) {
		for (int i = 1; i < items.size(); i++)
		{
			if (c(items[i]) == false)
				return false;
		}
		return true;
	}

	template<class Predicate>
	bool anyMatch(Predicate x) {
		for (int i = 1; i < items.size(); i++)
		{
			if (x(items[i]) == true)
				return true;
		}
		return false;
	}


};


#endif /* SRC_Q2_H_ */
