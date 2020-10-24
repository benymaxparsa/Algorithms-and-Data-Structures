#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Partition (vector<int> &list , int lo, int hi)
{
    int i = lo, j = hi + 1;
    
    while (true)
    {
        while (list[++i] < list[lo])
            if (i == hi)
                break;
        while (list[--j] > list[lo])
            if (j == lo)
                break;
        if (i >= j)
            break;
        
        swap(list[i], list[j]);
    }
    swap(list[lo], list[j]);
    return j;
}

int MedianOfThree(int lo, int hi)
{
    int a = lo, b = (lo + (hi - lo) / 2), c = hi;
    return max(min(a,b), min(max(a,b),c));
}

void QuickSort (vector<int> &list, int lo, int hi)
{
    if (hi <= lo)
        return;
    
    int median = MedianOfThree(lo, hi);
    swap(list[lo], list[median]);

    int pivot = Partition(list, lo, hi);
    QuickSort(list, lo, pivot - 1);
    QuickSort(list, pivot + 1, hi);
}

void QuickSort (vector<int> &list)
{
    random_shuffle(list.begin(), list.end());
    QuickSort(list, 0, list.size()-1);
}

void Print(const vector<int> &list)
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> list = {9, 7, 6, 15, 17, 5, 10, 11};
    QuickSort(list);
    Print(list);
}