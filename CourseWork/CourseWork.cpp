#include "BaseException.h"
#include "ComplexFigure.h"
#include "Stack.h"

int main()
{
	COORD p = { 0, 15 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	system("color 0F");

	try
	{
		Circle circle = Circle(50, 50, RGB(255, 0, 255), RGB(255, 255, 0), 50);
		Rect rectangle = Rect(120, 40, RGB(255, 0, 0), RGB(255, 0, 0), 20, 30);

		Stack::Show();
	}
	catch (BaseException& ex)
	{
		ex.ShowInfo();
	}
}