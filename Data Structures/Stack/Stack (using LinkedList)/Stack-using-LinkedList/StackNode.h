#pragma once
#ifndef StackNode_h
#define StackNode_h

#include <iostream>

class StackNode
{
private:
	int data;
	StackNode* next;
	friend class LLStack;
public:
	StackNode(int data);
	~StackNode();

};

#endif // !StackNode_h