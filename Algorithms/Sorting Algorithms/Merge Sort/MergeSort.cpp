#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &list, vector<int> &aux, int lo, int mid, int hi)
{
    for (int k = lo; k <= hi; k++)
        aux[k] = list[k];
    
    int i = lo , j = mid+1;

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

void MergeSort(vector<int> &list, vector<int> &aux, int lo, int hi)
{
    if (hi <= lo)
        return;
    
    int mid = lo + (hi - lo) / 2;

    MergeSort(list, aux, lo, mid);
    MergeSort(list, aux, mid+1, hi);
    Merge(list, aux, lo, mid, hi);
}

void MergeSort(vector<int> &list)
{
    vector<int> aux;
    aux.assign(list.size(), 0);
    MergeSort(list, aux, 0, list.size()-1);
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
    MergeSort(list);
    Print(list);

}