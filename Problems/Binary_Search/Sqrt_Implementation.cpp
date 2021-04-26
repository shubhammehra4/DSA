#include <bits/stdc++.h>
#define ll long long
using namespace std;

int sqrt(int x)
{
    if (x == 0 || x == 1)
        return x;

    ll int start = 1, end = x, ans;

    while (start <= end)
    {
        ll int mid = (start + end) / 2;

        if (mid * mid == x)
            return mid;

        if (mid * mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }

    return ans;
}

int main()
{
    cout << sqrt(9767564789);
    return 0;
}