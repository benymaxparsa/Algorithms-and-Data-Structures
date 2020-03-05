#include "Stack.h"
#include <iostream>

using namespace std;

int main() 
{
	Stack s;

	cout << s.isEmpty() << endl;
	cout << s.isFull() << endl;
	s.push(5);
	s.push(7);
	s.push(9);
	cout << s.isEmpty() << endl;
	cout <<"size "<< s.size() << endl;
	s.pop();
	cout << "size " << s.size() << endl;

	return 0;
}