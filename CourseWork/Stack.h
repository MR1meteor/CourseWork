#pragma once
#include <stack>
#include <vector>
#include "Figure.h"

static class Stack
{
private:
	static stack<Figure*, vector<Figure*>> elements;

public:
	static void Add(Figure*);
	static void Remove();
	static void Clear();
	static void Show();
};