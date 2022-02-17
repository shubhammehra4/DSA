#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int j = 0;
    int currVal;

    for (int i = 1; i < arr.size(); i++)
    {
        j = i - 1;
        currVal = arr[i];

        while (j >= 0 && arr[j] > currVal)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = currVal;
    }
}