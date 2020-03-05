#pragma once
#ifndef TwoStacks2_h
#define TwoStacks2_h

class TwoStacks2
{
public:
	TwoStacks2(int n);
	~TwoStacks2();
	void push1(int x);
	void push2(int x);
	int pop1();
	int pop2();

private:
	int* arr;
	int size;
	int top1, top2;

};

#endif // !TwoStacks2_h