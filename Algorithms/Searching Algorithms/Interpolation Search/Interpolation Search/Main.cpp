#include <iostream>
#include <algorithm>

using namespace std;

int interpolationSearch(int arr[], int n, int x)
{
	int low = 0;
	int high = n - 1;

	while (low <= high && arr[low] <= x && arr[high] >= x)
	{
		if (low == high)
		{
			if (arr[low] == x)
				return low;
			return -1;
		}

		int position = low + ((x - arr[low]) * (high - low) / (arr[high] - arr[low]));

		if (x == arr[position])
			return position;

		if (x < arr[position])
			high = position - 1;

		if (x > arr[position])
			low = position + 1;

	}

	return -1;
}

int main()
{
	int arr[] = { 0,2,4,6,8,10,12,14,16,18,20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 4;

	int result = interpolationSearch(arr, n, x);

	cout << result << endl;

	return 0;
}