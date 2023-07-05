#include "grid.h"
Grid::Grid(double tileW, double tileH, int width, int height, int color) {
	count = width * height;
	rect = new Rectangle * [count];
	int left = 0, top = 0;
	for (int i = 0; i <count; ++i)
	{
		rect[i] = new Rectangle(left * tileW, top * tileH, tileW, tileH, color);
		++top;
		if (top == height)
		{
			top = 0;
			++left;
		}
	}
}
Grid::~Grid()
{
	for (int i = 0; i < count; ++i)
		delete rect[i];

	delete[]rect;
}

 Rectangle* Grid::getRectAtPoint(const Point& p) {
//	for (int i = 0; i < count; i++)
//	{
//		if (rect[i]->contains(p) == true)
//			return rect[i];
//	}
//}
		Rectangle* rec = nullptr;
		for (int i = 0; i < count; ++i)
		{
			if (rect[i]->contains(p))
			{
				rec = rect[i];
				break;
			}
		}

		return rec;
	}
Rectangle* Grid::getRectAtIndex(int i) {
	return rect[i];
}
void Grid::moveGrid(double deltaLeft, double deltaTop) {
	for (int i = 0; i < count; i++)
	{
		rect[i]->moveRect(deltaLeft, deltaTop);
	}
}
void Grid::scaleGrid(double rectWidth, double rectHeight) {
	for (int i = 0; i < count; i++)
	{
		rect[i]->scaleRect(rectWidth, rectHeight);
	}
}