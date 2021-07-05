#include <bits/stdc++.h>
using namespace std;

// Only +ve values b/w 1-n
void printRepeating(vector<int> arr)
{
    cout << "The repeating elements are:" << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[abs(arr[i])] >= 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
            cout << abs(arr[i]) << " ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 5, 6, 7, 8, 1, 6, 2};
    printRepeating(arr);
    return 0;
}