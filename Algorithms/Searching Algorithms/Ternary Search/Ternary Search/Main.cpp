#include <iostream>

using namespace std;

int ternarySearch(int arr[], int left, int right, int x)
{
	if (left > right)
		return -1;

	int mid1 = left + (right - left) / 3;
	int mid2 = mid1 + (right - left) / 3;

	if (arr[mid1] == x)
		return mid1;
	if (arr[mid2] == x)
		return mid2;

	if (arr[mid1] > x)
		return ternarySearch(arr, left, mid1 - 1, x);

	if (arr[mid2] < x)
		return ternarySearch(arr, mid2 + 1, right, x);

	return ternarySearch(arr, mid1 + 1, mid2 - 1, x);

}

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int high = sizeof(arr) / sizeof(arr[0]);
	int low = 0;

	int result = ternarySearch(arr, low, high - 1, x);

	cout << result << endl;

	return 0;
}