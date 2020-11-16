#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Binomial(int row, int col);
int BinomialSpaceOptimized(int row, int col);

int main()
{
	cout << Binomial(4, 2) << endl;
	cout << BinomialSpaceOptimized(4, 2) << endl;
}

int Binomial(int row, int col)
{
	vector<vector<int>> list(row + 1, vector<int>(col + 1, 0));

	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= min(i, col); j++)
		{
			if (j == 0 || j == i)
				list[i][j] = 1;
			else
				list[i][j] = list[i - 1][j - 1] + list[i - 1][j];
		}
	}
	return list[row][col];
}

int BinomialSpaceOptimized(int row, int col)
{
	vector<int> table(col + 1, 0);

	table[0] = 1;
	for (int i = 1; i <= row; i++)
	{
		for (int j = min(i, col); j > 0; j--)
			table[j] = table[j - 1] + table[j];
	}
	return table[col];
}
