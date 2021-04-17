#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive (vector<int> &A)
{
    int n = A.size();
    bool present[n + 1] = { false };

    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0 && A[i] <= n)
            present[A[i]] = true;
    }

    for (int i = 1; i <= n; i++)
        if (!present[i])
            return i;

    return n + 1;
}


int main()
{
    std::vector<int> arr = {5, -9, 7, 8, 1, 2};
    cout << firstMissingPositive (arr);
    return 0;
}