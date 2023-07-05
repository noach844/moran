
#ifndef SRC_Q1_H_
#define SRC_Q1_H_


class SnakesNladders {
private:
	int game[100];

public:
	SnakesNladders()
	{
		for (int i = 0; i < 100; i++)
		{
			game[i] =0;

		}
	}

	void addLadder(int from, int to) {
		if (from < to && 0 <= to < 100)
		{
			game[from] = to;
		}
	}

	// implement
	void addSnake(int from, int to) {
		if (from > to && 0 <= from < 100)
		{
			game[from] = to;
		}
	}

	// implement
	class iterator {
		int pointer;
		SnakesNladders* g;
	public:
		iterator(SnakesNladders* g) {
			pointer = 0;
			this->g = g;
		}
		int operator*()
		{
			return pointer;
		}
		void operator++()
		{
			if (pointer < 99)
			{
				pointer++;
			}
			while (g->game[pointer] != 0 )
			{
					pointer = g->game[pointer];
			}
		}
	};

	// implement 
	iterator getIterator() {
	return iterator(this);
	}

	// implement
	bool hasLoops() {
		for (int i = 0; i < 100; i++)
		{
			int x = -1;
			if (game[i] != 0)
				x = game[i];
			if (x != -1)
			{
				while (x != i && game[x] != 0)
				{
						x = game[x];
				}
				if (x == i)
					return true;
			}
		}
		return false;
	}
};

#endif /* SRC_Q1_H_ */