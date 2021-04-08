#include <bits/stdc++.h>
using namespace std;

void arrange (vector<int> &A)
{
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        A[i] += (A[A[i]] % n) * n;
    }

    for (int i = 0; i < n; i++)
    {
        A[i] /= n;
    }
}

int main ()
{
    vector<int> arr = {3, 0, 1, 2};
    arrange (arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}