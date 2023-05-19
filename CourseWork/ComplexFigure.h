#pragma once
#include "Figure.h"
#include "Circle.h"
#include "Rect.h"

class ComplexFigure : public Figure
{
private:
	Circle& circle;
	Rect& rectangle;

public:
	ComplexFigure(Circle&, Rect&);

	string GetData() override;

	void Draw() override;
	void Move(int, int) override;
	void Hide() override;
};