#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        int temp = nums[i];

        temp = (temp > 0) ? temp : -temp;

        if (nums[temp - 1] > 0)
            nums[temp - 1] *= -1;
    }

    for (int i = 0; i < nums.size(); i++)
        if (nums[i] > 0)
            ans.push_back(i + 1);

    return ans;
}

int main()
{
    return 0;
}