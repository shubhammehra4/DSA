#include <bits/stdc++.h>
using namespace std;

int findMinXor(vector<int> &A)
{
    sort(A.begin(), A.end());
    int minXor = INT_MAX;
    int val = 0;

    for (int i = 0; i < A.size() - 1; i++)
    {
        val = A[i] ^ A[i + 1];
        minXor = min(minXor, val);
    }
    return minXor;
}

int main()
{
    vector<int> arr = {9, 5, 3};
    cout << findMinXor(arr) << endl;
    return 0;
}