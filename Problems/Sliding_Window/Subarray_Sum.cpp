#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int left = 0, cnt = 0, ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        cnt += nums[i];
        if (cnt < goal)
            continue;

        if (cnt == goal)
            ans++;
        else
        {
            while (left < i && cnt > goal)
                cnt -= nums[left++];
        }

        int t = left;
        while (t < i && nums[t] == 0)
        {
            t++, ans++;
        }
    }

    return ans;
}

int numSubarraysWithSum(vector<int> &A, int S)
{
    unordered_map<int, int> c({{0, 1}});
    int psum = 0, res = 0;

    for (int i : A)
    {
        psum += i;
        res += c[psum - S];
        c[psum]++;
    }
    return res;
}

int main()
{
    return 0;
}