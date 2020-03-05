#pragma once
#ifndef SpecialStack_h
#define SpecialStack_h

#include "Stack.h"

class SpecialStack : public Stack
{
public:
	int pop();
	void push(int x);
	int getMin();

private:
	Stack* min = new Stack();

};


#endif // !SpecialStack_h
//