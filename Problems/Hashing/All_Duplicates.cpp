#include <bits/stdc++.h>
using namespace std;

// Will only work if elements appear once or twice
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    int num;

    for (int i = 0; i < nums.size(); i++)
    {
        num = abs(nums[i]);
        nums[num - 1] *= -1;

        if (nums[num - 1] > 0)
            ans.push_back(num);
    }
    return ans;
}

int main()
{
    return 0;
}