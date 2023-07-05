
#ifndef SRC_Q1_H_
#define SRC_Q1_H_


class SnakesNladders {
	int game[100];
public:
	SnakesNladders() {
		for (int i = 0; i < 100; i++)
		{
			game[i] = 0;
		}
	}
	void addLadder(int from, int to) {
		if (from < to && to < 100)
		{
			game[from] = to;
		}
	}
	void addSnake(int from, int to) {
		if (to < from && to >= 0)
		{
			game[from] = to;
		}
	}
	class iterator {
		SnakesNladders* other;
		int index;
	public:
		iterator(SnakesNladders* temp) {
			index = 0;
			this->other = temp;
		}
		int operator*() {
			return index;
		}
		void operator++() {
			if(index<99)
				index++;
			while (other->game[index]!=0)
			{
				index = other->game[index];
			}
		}
	};

	iterator getIterator() {
		return iterator(this);
	}
	bool hasLoops() {
		for (int i = 0; i < 100; i++)
			if (game[i] != 0) {
				int it = game[i];
				while (it != i && game[it] != 0) {
					it = game[it];
				}
				if (it == i)
					return true;
			}
		return false;
	}
};

#endif /* SRC_Q1_H_ */
