#include "Circle.h"
#include "BaseException.h"
#include "Stack.h"

Circle::Circle(int x, int y, COLORREF inside, COLORREF line, double r) : Figure(x, y, inside, line), R(r)
{
	if (R <= 0)
	{
		throw BaseException(
			GetData(),
			"Circle constructor: Circle()",
			"Invalid radius"
		);
	}

	Stack::Add(this);
}

string Circle::GetData()
{
	return "X: " + std::to_string(x) + " | Y: " + std::to_string(y) + " | R: " + std::to_string(R);
}

void Circle::Draw()
{

	if (x - R < rect.left || y - R < rect.top ||
		x + R > rect.right || y + R > rect.bottom)
	{
		throw BaseException(
			GetData(),
			"Circle method: Draw()",
			"Out of bounds"
		);
	}

	pen = CreatePen(PS_SOLID, 2, outline);
	brush = CreateSolidBrush(color);

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);

	Ellipse(hdc, double(x - R), double(y - R), double(x + R), double(y + R));

	DeleteObject(pen);
	DeleteObject(brush);
}

void Circle::Move(int x, int y)
{
	Hide();

	if (x <= 0 || y <= 0)
	{
		throw BaseException(
			GetData(),
			"Circle method: Move()",
			"Invalid coordinates"
		);
	}

	this->x = x;
	this->y = y;

	Draw();
}

void Circle::Hide()
{
	if (x - R < rect.left || y - R < rect.top ||
		x + R > rect.right || y + R > rect.bottom)
	{
		throw BaseException(
			GetData(),
			"Circle method: Draw()",
			"Out of bounds"
		);
	}

	pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	brush = CreateSolidBrush(RGB(0, 0, 0));

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);

	Ellipse(hdc, double(x - R), double(y - R), double(x + R), double(y + R));

	DeleteObject(pen);
	DeleteObject(brush);
}