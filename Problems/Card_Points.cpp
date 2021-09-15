#include <bits/stdc++.h>
using namespace std;

// Prefix Sum
int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size(), lSum = 0;

    if (k == n)
        return accumulate(cardPoints.begin(), cardPoints.end(), 0);

    for (int i = 0; i < k; i++)
        lSum += cardPoints[i];

    int max_sum = lSum;
    int rSum = 0;
    for (int i = 0; i < k; i++)
    {
        rSum += cardPoints[n - 1 - i];
        lSum -= cardPoints[k - 1 - i];
        max_sum = max(max_sum, lSum + rSum);
    }

    return max_sum;
}

int main()
{
    return 0;
}