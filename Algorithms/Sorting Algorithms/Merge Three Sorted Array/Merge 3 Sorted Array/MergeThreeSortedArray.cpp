#include <iostream>
#include <vector>
using namespace std;

void TwoArrayMerge(vector<int>& first, int &i, vector<int>& second, int &j, vector<int>& aux, int &t)
{
	if (first[i] <= second[j])
		aux[t] = first[i++];

	else 
		aux[t] = second[j++];
}

void ThirdArrayMerge(vector<int>& first, int &i, vector<int>& second, int &j
	 , vector<int> & third, int &k, vector<int>& aux, int &t)
{
	if (first[i] <= second[j] && first[i] <= third[k])
		aux[t] = first[i++];

	else if (second[j] <= first[i] && second[j] <= third[k])
		aux[t] = second[j++];

	else if (third[k] <= first[i] && third[k] <= second[j])
		aux[t] = third[k++];
}

void Merge(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& aux)
{
	int i = 0, iEnd = a.size() - 1
		, j = 0, jEnd = b.size() - 1
		, k = 0, kEnd = c.size() - 1;
	
	for (int t = 0; t < aux.size(); t++)
	{
		if (i <= iEnd && j <= jEnd && k <= kEnd)
			ThirdArrayMerge(a, i, b, j, c, k, aux, t);

		else if (i > iEnd && k > kEnd)
			aux[t] = b[j++];

		else if (i > iEnd && j > jEnd)
			aux[t] = c[k++];

		else if (j > jEnd && k > kEnd)
			aux[t] = a[i++];

		else if (i > iEnd)
			TwoArrayMerge(b, j, c, k, aux, t);

		else if (j > jEnd)
			TwoArrayMerge(a, i, c, k, aux, t);

		else if (k > kEnd)
			TwoArrayMerge(a, i, b, j, aux, t);

	}

}

vector<int> Sort(vector<int>& a, vector<int>& b, vector<int>& c)
{
	int auxSize = a.size() + b.size() + c.size();
	vector<int> aux;
	aux.assign(auxSize, 0);
	Merge(a, b, c, aux);
	return aux;
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
	vector<int> firstList = { 1, 3, 5, 7, 9 };
	vector<int> secondList = { 0, 2, 6, 10 };
	vector<int> thirdList = { 4, 8, 11, 13, 14 };
	vector<int> sortedList;

	sortedList = Sort(firstList, secondList, thirdList);

	Print(sortedList);
}