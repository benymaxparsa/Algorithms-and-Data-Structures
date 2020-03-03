#include <iostream>
#include <algorithm>

using namespace std;

int jumpSearch(int arr[], int n, int x)
{
	int next = sqrt(n);
	int prev = 0;

	while (arr[min(next,n) - 1] < x)
	{
		prev = next;
		next += next;
		if (prev >= n)
			return -1;
	}

	while (arr[prev] < x)
	{
		prev++;

		if (prev == min(next, n))
			return -1;

	}

	if (arr[prev] == x)
		return prev;
	return -1;
}


int main()
{
	int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	int x = 55;
	int n = sizeof(arr) / sizeof(arr[0]);

	int result = jumpSearch(arr, n, x);

	cout << result << endl;

	return 0;
}