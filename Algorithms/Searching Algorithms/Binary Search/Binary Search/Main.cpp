#include <iostream>

using namespace std;

int recursiveBinarySearch(int arr[], int low, int high, int x)
{
	if (low > high)
		return -1;
	else
	{
		int mid = (high + low) / 2;
		if (x == arr[mid])
			return mid;
		if (x < arr[mid])
			return recursiveBinarySearch(arr, low, mid - 1, x);
		return recursiveBinarySearch(arr, mid + 1, high, x);
	}
}

int iterativeBinarySearch(int arr[], int low, int high, int x)
{
	while (low <= high)
	{
		int mid = (high + low) / 2;
		if (x == arr[mid])
			return mid;
		if (x < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main()
{

	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int high = sizeof(arr) / sizeof(arr[0]);
	int low = 0;

	int ReResult = recursiveBinarySearch(arr, low, high - 1, x);

	int ItrResult = iterativeBinarySearch(arr, low, high - 1, x);

	cout << ReResult << endl << ItrResult << endl;

	return 0;
}