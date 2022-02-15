#include <bits/stdc++.h>
using namespace std;

int maxProfitKnapSack(vector<int> &weight, vector<int> &profit, int weightLimit)
{
    int n = size(weight);
    vector<vector<int>> knapSack(n + 1, vector<int>(weightLimit + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= weightLimit; w++)
        {
            if (weight[i - 1] <= w)
                knapSack[i][w] = max(profit[i - 1] + knapSack[i - 1][w - weight[i - 1]],
                                     knapSack[i - 1][w]);
            else
                knapSack[i][w] = knapSack[i - 1][w];
        }
    }

    return knapSack[n][weightLimit];
}

// int main()
// {
//     int p[] = {60, 100, 120};
//     int wt[] = {10, 20, 30};
//     int W = 40;
//     int n = sizeof(p) / sizeof(p[0]);

//     cout << knapSack(W, wt, p, n);

//     return 0;
// }