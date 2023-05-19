#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Figure
{
protected:
	int x, y;
	COLORREF color, outline;
	HWND hwnd;
	HDC hdc;
	HPEN pen;
	HBRUSH brush;
	RECT rect;

public:
	Figure(int, int, COLORREF, COLORREF);
	~Figure();

	int GetX() const { return x; }
	int GetY() const { return y; }

	virtual string GetData();

	virtual void Draw() = 0;
	virtual void Move(int, int) = 0;
	virtual void Hide() = 0;
};