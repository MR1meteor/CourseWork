#pragma once
#include "Figure.h"

class Circle : public Figure
{
private:
	double R;

public:
	Circle(int, int, COLORREF, COLORREF, double);

	string GetData() override;

	double GetR() { return R; }

	void Draw() override;
	void Move(int, int) override;
	void Hide() override;
};