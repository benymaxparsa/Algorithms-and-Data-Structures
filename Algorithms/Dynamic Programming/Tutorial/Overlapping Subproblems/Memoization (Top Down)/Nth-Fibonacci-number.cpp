#include <bits/stdc++.h>
using namespace std;
#define NIL -1
#define MAX 100

int lookup[MAX];

void InitiateLookup()
{
    for (int i = 0; i < MAX; i++)
    {
        lookup[i] = NIL;
    }
}

int Fibonacci(int n)
{
    if (lookup[n] == NIL)
    {
        if (n <= 1)
            lookup[n] = n;
        else
          lookup[n] = Fibonacci(n-1) + Fibonacci(n-2);
    }

    return lookup[n];
}

int main()
{
    InitiateLookup();
    cout << Fibonacci(40) << endl;

    return 0;
}