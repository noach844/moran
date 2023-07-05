#ifndef SRC_PLAYLIST_H_
#define SRC_PLAYLIST_H_

#include <vector>
#include <typeinfo>
#include "Q1.h"
using namespace std;


class PlayList: public Item {
private:
	vector<Item*> thelist;
	vector<string>deepListOfSongs;
public:
	PlayList(string name): Item(name), thelist(NULL), deepListOfSongs(NULL) {
	}
	PlayList(PlayList& other):Item(other.name),thelist(other.thelist),deepListOfSongs(other.deepListOfSongs){}

	PlayList& operator+=(Item* other) {
			thelist.push_back(other);
			return *this;
	}
	int build(vector<Item*>& thelist, vector<string>& deepListOfSongs)
	{
		for(int i=0; i<thelist.size(); i++)
		{
			if (typeid(*thelist[i]) == typeid(Song))
				deepListOfSongs.push_back(thelist[i]->name);
			if (typeid(*(thelist[i])) == typeid(PlayList)) {
				PlayList* t = (PlayList*) thelist[i];
				build(t->thelist, deepListOfSongs);
			}
		}
		return 0;
	}
	int theend(vector<string>& deepListOfSongs) {
		return deepListOfSongs.size();
	}
	vector<string>::iterator begin() {
		build(thelist, deepListOfSongs);
		return deepListOfSongs.begin();
	}
	vector<string>::iterator end() {
		return deepListOfSongs.end();
	}

};

#endif /* SRC_PLAYLIST_H_ */
