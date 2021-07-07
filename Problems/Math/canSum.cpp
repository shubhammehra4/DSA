#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool canSum(int target, list<int> arr) // Time: O(n^m) Space: O(m)
{
    if (target == 0)
        return true;

    if (target < 0)
        return false;

    for (auto i : arr)
    {
        int remainder = target - i;

        if (canSum(remainder, arr))
            return true;
    }

    return false;
}

bool memo[1000000] = {0};
bool memoCanSum(int target, list<int> arr) // Time: O(n*m) Space: O(m)
{
    if (memo[target])
        return memo[target];

    if (target == 0)
        return true;

    if (target < 0)
        return false;

    for (auto i : arr)
    {
        int remainder = target - i;

        if (memoCanSum(remainder, arr))
        {
            memo[target] = true;
            return true;
        }
    }

    memo[target] = false;
    return false;
}

int main()
{
    cout << memoCanSum(300, {7, 14}) << endl;
}