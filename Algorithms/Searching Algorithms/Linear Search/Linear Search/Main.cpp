#include <iostream>

using namespace std;

int LinearSearch(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x)
			return i;
	}
	return -1;
}

int main()
{
	int arr[] = { 1,3,7,9,44,2,8 };
	int x = 2;
	int n = sizeof(arr) / sizeof(arr[0]);

	int result = LinearSearch(arr, n, x);

	cout << result << endl;

	return 0;
}