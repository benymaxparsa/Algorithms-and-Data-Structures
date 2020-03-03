#include <iostream>
#include <algorithm>

using namespace std;


int binarySearch(int arr[], int left, int right, int x)
{
	if (left > right)
		return -1;

	int mid = left + (right - left) / 2;

	if (arr[mid] == x)
		return mid;

	if (arr[mid] < x)
		return binarySearch(arr, mid + 1, right, x);

	return binarySearch(arr, left, mid - 1, x);

}

int exponentialSearch(int arr[], int n, int x)
{
	if (arr[0] == x)
		return 0;

	int range = 1;

	while (range < n && arr[range] <= x)
		range = range * 2;

	return binarySearch(arr, range / 2, min(range, n), x);
}


int main()
{
	int arr[] = { 0, 3, 5, 9, 13, 40, 66 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int find = 40;

	int result = exponentialSearch(arr, size, find);

	cout << result << endl;

	return 0;
}