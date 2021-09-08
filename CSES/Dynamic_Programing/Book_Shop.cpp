#include <bits/stdc++.h>
using namespace std;

/*
You are in a book shop which sells n different books. You know the price and 
number of pages of each book.

You have decided that the total price of your purchases will be at most x. 
What is the maximum number of pages you can buy? You can buy each book at most once.


Reccurrence Relation
if pr[i] <=x
    f(x,i) = max( (pg[i] + f(x-price[i],i+1)), f(x, i+1) ) // Buy or leave
*/

int dpmaxPages(int x, vector<int> price, vector<int> pages)
{
    int n = price.size();
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (price[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - price[i - 1]] + pages[i - 1]));
        }
    }

    return dp[n][x];
}

// Space Optimized
int dpMaxPages(int x, vector<int> price, vector<int> pages)
{
    int n = price.size();
    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= price[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }

    return dp[x];
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> price, pages;
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        price.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        pages.push_back(temp);
    }

    cout << dpMaxPages(x, price, pages);

    return 0;
}