#include "Figure.h"
#include "BaseException.h"

Figure::Figure(int x, int y, COLORREF inside, COLORREF line) : x(x), y(y), color(inside), outline(line)
{
	if (x <= 0 || y <= 0)
	{
		throw BaseException(
			GetData(),
			"Figure constructor: Figure()",
			"Invalid coordinates"
		);
	}

	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);

	if (hwnd == 0)
	{
		throw BaseException(
			"NoData",
			"Figure constructor: Figure()",
			"Error getting console window"
		);
	}

	if (hdc == 0)
	{
		throw BaseException(
			"NoData",
			"Figure constructor: Figure()",
			"Error getting console window"
		);
	}

	GetClientRect(hwnd, &rect);
}

Figure::~Figure()
{
	ReleaseDC(hwnd, hdc);
}

string Figure::GetData()
{
	return "X: " + std::to_string(x) + " | Y: " + std::to_string(y);
}