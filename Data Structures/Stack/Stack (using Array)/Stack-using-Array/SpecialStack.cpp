#include "SpecialStack.h"

int SpecialStack::pop()
{
	int x = Stack::pop();
	min->pop();
	return x;
}

void SpecialStack::push(int x)
{
	if (isEmpty())
	{
		Stack::push(x);
		min->push(x);
	}
	else
	{
		Stack::push(x);
		int y = min->pop();
		min->push(y);
		if (x > y)
			min->push(y);
		else
			min->push(x);
	}
}

int SpecialStack::getMin()
{
	int x = min->pop();
	min->push(x);
	return x;
}
//