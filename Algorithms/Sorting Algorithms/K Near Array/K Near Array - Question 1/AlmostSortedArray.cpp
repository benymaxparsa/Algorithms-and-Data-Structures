#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& list, vector<int>& aux, int lo, int mid, int hi)
{
	for (int k = lo; k <= hi; k++)
		aux[k] = list[k];

	int i = lo, j = mid + 1;

	for (int k = lo; k <= hi; k++)
	{
		if (i > mid)
			list[k] = aux[j++];

		else if (j > hi)
			list[k] = aux[i++];

		else if (aux[j] < aux[i])
			list[k] = aux[j++];

		else
			list[k] = aux[i++];

	}

}

void MergeSort(vector<int>& list, vector<int>& aux, int lo, int hi)
{
	if (hi <= lo)
		return;

	int mid = lo + (hi - lo) / 2;

	MergeSort(list, aux, lo, mid);
	MergeSort(list, aux, mid + 1, hi);
	if (list[mid] > list[mid + 1])
		Merge(list, aux, lo, mid, hi);
}

void K_NearSort(vector<int>& list, int k)
{
	vector<int> aux;
	aux.assign(list.size(), 0);

	int i = 0, lo = 0, hi = (i + 2)* k - 1, n = list.size() - 1;

	while (hi <= n)
	{
		MergeSort(list, aux, lo, hi);
		i++;
		lo = i * k;
		hi = (i + 2) * k -1;
	}
	hi = (i + 1) * k - 1;
	if (hi < n)
	{
		MergeSort(list, aux, lo, n);
	}
}

void Print(const vector<int>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}


int main()
{
	vector<int> list = { 6, 5, 3, 2, 8, 10, 9 };
	int k = 3;
	K_NearSort(list, k);
	Print(list);

}