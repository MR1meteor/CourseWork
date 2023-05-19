#pragma once
#include "Figure.h"

class Rect : public Figure
{
private:
	int width;
	int height;

public:
	Rect(int, int, COLORREF, COLORREF, int, int);

	string GetData() override;

	int GetWidth() { return width; }
	int GetHeight() { return height; }

	void Draw() override;
	void Move(int, int) override;
	void Hide() override;
};