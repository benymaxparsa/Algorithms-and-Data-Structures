#include "LLStack.h"

LLStack::LLStack()
{
	size = 0;
	root = NULL;
}

LLStack::~LLStack()
{
}

StackNode* LLStack::lastData()
{
	StackNode* p = root;
	while (p->next)
	{
		p = p->next;
	}
	return p;
}

void LLStack::push(int data)
{
	StackNode* node = new StackNode(data);
	size++;
	if (!root)
	{
		root = node;
		return;
	}
	else
	{
		lastData()->next = node;
		return;
	}
}

int LLStack::pop()
{
	if (!root)
		return 0;
	else
	{
		StackNode* p = lastData();
		int data =p->data;
		size--;
		p = NULL;
		if (size == 0)
			root = NULL;
		return data;
	}

}

int LLStack::top()
{
	if (!root)
		return 0;
	else
	{
		StackNode* p = root;
		while (p->next)
		{
			p = p->next;
		}
		return p->data;
	}
}

bool LLStack::isEmpty()
{
	if (!root && size == 0)
		return true;
	else
		return false;
}

int LLStack::Size()
{
	return size;
}
