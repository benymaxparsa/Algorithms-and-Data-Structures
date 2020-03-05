#include "LLStack.h"

using namespace std;

int main()
{
	LLStack* s = new LLStack();

	s->push(3);
	s->push(6);
	s->pop();
	s->push(9);

	cout << s->Size() << "  " << s->top() << "  " << s->isEmpty() << endl;
	s->pop();
	s->pop();
	cout << s->Size() << "  " << s->isEmpty() << endl;
	s->pop();
	cout << s->Size() << endl;

	return 0;
}