// There is a corridor in a Jail which is N units long. Given an array A of size N.
// The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.

// All the lights are of specific power B which if is placed at position X,
// it can light the corridor from[X - B + 1, X + B - 1].
// Initially all lights are off.

// Return the minimum number of lights to be turned ON to light the whole corridor or
// -1 if the whole corridor cannot be lighted.
#include <bits/stdc++.h>
using namespace std;

int minimumLights(vector<int> &A, int B)
{
    int n = A.size(), i = 0, ans = 0;
    if (B == 0)
        return -1;

    while (i < n)
    {
        int idx = -1;
        //check range [X-B+1, X+B-1] and find rightmost bulb
        for (int j = max(0, i - B + 1); j < min(n, i + B); j++)
        {
            if (A[j] == 1)
                idx = j;
        }
        if (idx == -1)
            return -1;
        ans++;
        //Start now from index which is outside the current selected bulb
        i = idx + B;
    }
    return ans;
}

int main()
{

    return 0;
}