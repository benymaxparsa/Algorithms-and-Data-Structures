#pragma once
#ifndef TwoStacks1_h
#define TwoStacks1_h

class TwoStacks1
{
public:
	TwoStacks1(int n);
	~TwoStacks1();
	void push1(int x);
	void push2(int x);
	int pop1();
	int pop2();

private:
	int* arr;
	int size;
	int top1, top2;

};

#endif // !TwoStacks1_h