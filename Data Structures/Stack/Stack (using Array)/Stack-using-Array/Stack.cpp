#include "Stack.h"

int Stack::pop()
{
	if (isEmpty())
		return 0;
	else
		return arr[top--];
}

bool Stack::push(int x)
{
	if (isFull())
		return false;
	else
	{
		arr[++top] = x;
		return true;
	}
}

int Stack::peek()
{
	if (isEmpty())
		return 0;
	else
		return arr[top];
}

bool Stack::isEmpty()
{
	return (top < 0);
}

int Stack::size()
{
	return (top + 1);
}

bool Stack::isFull()
{
	return (top >= (MAX-1));
}
