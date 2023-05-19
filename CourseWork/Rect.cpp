#include "Rect.h"
#include "Stack.h"
#include "BaseException.h"

Rect::Rect(int x, int y, COLORREF inside, COLORREF line, int width, int height) : Figure(x, y, inside, line), width(width), height(height)
{
	if (width <= 0 || height <= 0)
	{
		throw BaseException(
			GetData(),
			"Rect constructor: Rect()",
			"Invalid size"
		);
	}

	Stack::Add(this);
}
string Rect::GetData()
{
	return "X: " + std::to_string(x) + " | Y: " + std::to_string(y) +
		" | Width: " + std::to_string(width) + " | Height: " + std::to_string(height);
}

void Rect::Draw()
{
	if (x - width < rect.left || y - height < rect.top ||
		x + width > rect.right || y + height > rect.bottom)
	{
		throw BaseException(
			GetData(),
			"Rect method: Draw()",
			"Out of bounds"
		);
	}

	pen = CreatePen(PS_SOLID, 2, outline);
	brush = CreateSolidBrush(color);

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	
	Rectangle(hdc, double(x - width), double(y - height), double(x + width), double(y + height));

	DeleteObject(pen);
	DeleteObject(brush);
}

void Rect::Move(int x, int y)
{
	Hide();

	if (x <= 0 || y <= 0)
	{
		throw BaseException(
			GetData(),
			"Rect method: Move()",
			"Invalid coordinates"
		);
	}

	this->x = x;
	this->y = y;

	Draw();
}

void Rect::Hide()
{
	if (x - width < rect.left || y - height < rect.top ||
		x + width > rect.right || y + height > rect.bottom)
	{
		throw BaseException(
			GetData(),
			"Rect method: Draw()",
			"Out of bounds"
		);
	}

	pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	brush = CreateSolidBrush(RGB(0, 0, 0));

	SelectObject(hdc, pen);
	SelectObject(hdc, brush);

	Rectangle(hdc, double(x - width), double(y - height), double(x + width), double(y + height));

	DeleteObject(pen);
	DeleteObject(brush);
}