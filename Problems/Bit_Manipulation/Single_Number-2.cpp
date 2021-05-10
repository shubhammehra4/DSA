#include <bits/stdc++.h>
using namespace std;
// Time - O(32N) Space - O(1)
int singleNumber(const vector<int> &A)
{
    int ans = 0, odd, p = 1;
    int N = A.size();

    for (int i = 0; i < 32; i++)
    {
        odd = 0;
        for (int j = 0; j < N; j++)
        {
            if (p & A[j])
                odd++;
        }
        if (odd % 3 != 0)
            ans += p;
        p *= 2;
    }
    return ans;
}
// Time O(2N) Space - O(N)
int singleNumber2(const vector<int> &A)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < A.size(); i++)
        mp[A[i]]++;

    for (int i = 0; i < A.size(); i++)
        if (mp[A[i]] == 1)
            return A[i];

    return -1;
}

int main()
{

    return 0;
}