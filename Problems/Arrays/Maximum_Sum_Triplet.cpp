#include <bits/stdc++.h>
using namespace std;

int maximumSumTriplet(vector<int> &A)
{
    int ans = 0;
    int n = A.size();
    vector<int> right(n, 0); // Right is for accessing the higher value
    for (int i = n - 2; i >= 0; i--)
    {
        int mx = max(right[i + 1], A[i + 1]);
        if (mx > A[i])
            right[i] = mx;
    }

    set<int> s; // Set if for accessing the lower value
    s.insert(A[0]);
    for (int i = 1; i < n - 1; i++)
    {
        s.insert(A[i]);
        if (right[i] != 0)
        {
            auto itr = s.find(A[i]);
            if (itr != s.begin())
                ans = max(ans, (A[i] + (*(--itr)) + right[i]));
        }
    }
    return ans;
}

int main()
{

    return 0;
}