#include <bits/stdc++.h>
using namespace std;

int jumpSearch(vector<int> &arr, int target)
{
    int n = arr.size();
    int stepSize = sqrt(n);
    int step = stepSize;

    int stepStart = 0;
    while (arr[min(step, n) - 1] < target)
    {
        stepStart = step;
        step += stepSize;
        if (stepStart >= n)
            return -1;
    }

    int i = stepStart;
    while (arr[i] < target)
    {
        i++;
        if (i == min(step, n))
            return -1;
    }

    if (arr[i] == target)
        return i;

    return -1;
}