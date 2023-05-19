#include "ComplexFigure.h"
#include "BaseException.h"
#include "Stack.h"

ComplexFigure::ComplexFigure(Circle& circle, Rect& rect) : Figure(1, 1, RGB(0, 0, 0), RGB(0, 0, 0)), circle(circle), rectangle(rect)
{
	if (circle.GetX() != rectangle.GetX() ||
		circle.GetY() != rectangle.GetY())
	{
		throw BaseException(
			GetData(),
			"Complex figure constructor: ComplexFigure()",
			"Coordinates error"
		);
	}

	double rectDiagonale = sqrt(pow(rectangle.GetHeight(), 2) + pow(rectangle.GetWidth(), 2));

	if (rectDiagonale != circle.GetR())
	{
		throw BaseException(
			GetData(),
			"Complex figure constructor: ComplexFigure()",
			"Complex figure cannot be created from these figures"
		);
	}

	Stack::Add(this);
}

string ComplexFigure::GetData()
{
	return "\nCircle: " + circle.GetData() + "\nRectangle: " + rectangle.GetData();
}

void ComplexFigure::Draw()
{
	circle.Draw();
	rectangle.Draw();
}

void ComplexFigure::Move(int x, int y)
{
	circle.Move(x, y);
	rectangle.Move(x, y);
}

void ComplexFigure::Hide()
{
	circle.Hide();
	rectangle.Hide();
}