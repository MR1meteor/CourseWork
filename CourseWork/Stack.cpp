#include "Stack.h"

stack<Figure*,vector<Figure*>> Stack::elements;

void Stack::Add(Figure* element)
{
	elements.push(element);
}

void Stack::Remove()
{
	elements.pop();
}

void Stack::Clear()
{
	while (!elements.empty())
	{
		elements.pop();
	}
}

void Stack::Show()
{
	stack<Figure*, vector<Figure*>> elementsDouble;

	while (!elements.empty())
	{
		elements.top()->Draw();
		elementsDouble.push(elements.top());
		elements.pop();
	}

	while (!elementsDouble.empty())
	{
		elements.push(elementsDouble.top());
		elementsDouble.pop();
	}
}