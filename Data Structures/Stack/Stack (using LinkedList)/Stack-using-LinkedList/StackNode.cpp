#include "StackNode.h"

StackNode::StackNode(int data)
{
	this->data = data;
	next = NULL;
}

StackNode::~StackNode()
{
	delete next;
}
