#include "Grid.h"

Grid::Grid(double tileW, double tileH, int width, int height, int color)
{
	this->_numOfRect = width * height;
	_rectsGrid = new Rectangle * [_numOfRect];
	int left = 0, top = 0;
	for (int i = 0; i < _numOfRect; ++i)
	{
		_rectsGrid[i] = new Rectangle(left * tileW, top * tileH, tileW, tileH, color);
		++top;
		if (top == height)
		{
			top = 0;
			++left;
		}
	}
	//int count = 0;
	/*for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			_rectsGrid[count] = new Rectangle(tileW * i, tileH * j, tileW, tileH , color);
			count++;
		}

	}
	*/
}

Grid :: ~Grid()
{
	for (int i = 0; i < _numOfRect; i++)
	{
		delete this->_rectsGrid[i];
	}
}

Rectangle* Grid::getRectAtPoint(const Point& p)
{
	for (int i = 0; i < _numOfRect; i++)
	{
		if (_rectsGrid[i]->contains(p))
		{
			return _rectsGrid[i];
		}
	}
}
Rectangle* Grid::getRectAtIndex(int i)
{
	return _rectsGrid[i];
}

void Grid::moveGrid(double deltaLeft, double deltaTop)
{
	for (int i = 0; i < _numOfRect; i++)
	{
		_rectsGrid[i]->moveRect(deltaLeft, deltaTop);
	}
}

void Grid::scaleGrid(double rectWidth, double rectHeight)
{
	for (int i = 0; i < _numOfRect; i++)
	{
		_rectsGrid[i]->scaleRect(rectWidth, rectHeight);
	}
}
