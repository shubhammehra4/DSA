#include <bits/stdc++.h>
using namespace std;

int sumOddLengthSubarrays(vector<int> &a)
{
    int n = a.size();
    int x;
    int s = 0;

    for (int i = 0; i < n; i++)
    {
        // Formula by Observation on Test Case
        x = ceil((((i + 1) * (n - i))) / (2 * 1.0));
        s += a[i] * x;
    }

    return s;
}

int main()
{

    return 0;
}