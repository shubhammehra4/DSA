#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back

vector<vector<int>> threeSum(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = A.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; ++i)
    {
        if (i > 0 && A[i] == A[i - 1])
            continue;
        int l = i + 1, r = n - 1;

        while (l < r)
        {
            // long long sum = A[i] + (long long)A[l] + (long long)A[r];
            long long sum = 0LL + A[i] + A[l] + A[r];
            if (sum == 0)
            {
                ans.pb({A[i], A[l], A[r]});
                while (l < n - 1 && A[l] == A[l + 1])
                    ++l;
                while (r > 0 && A[r] == A[r - 1])
                    --r;

                ++l, --r;
            }
            else if (sum > 0)
                --r;
            else
                ++l;
        }
    }
    return ans;
}

int main()
{

    return 0;
}