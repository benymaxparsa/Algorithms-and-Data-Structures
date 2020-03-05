#ifndef Stack_h
#define Stack_h

#define MAX 1000

class Stack
{
private:
	int top;
	int arr[MAX];

public:
	Stack() { top = -1; }
	~Stack(){}
	int pop();
	bool push(int x);
	int peek();
	bool isEmpty();
	int size();
	bool isFull();
};

#endif // !Stack_h