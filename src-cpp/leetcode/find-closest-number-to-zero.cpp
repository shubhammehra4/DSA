#include <bits/stdc++.h>
using namespace std;

int findClosestNumber(vector<int> &nums)
{
    return *min_element(begin(nums), end(nums),
                        [](int a, int b)
                        {
                            return abs(a) < abs(b) || (abs(a) == abs(b) && a > b);
                        });
}