#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*
Your task is to count the number of ways numbers 1,2,…,n can be divided into two sets of equal sum.

For example, if n=7, there are four solutions:
 {1,3,4,6} and {2,5,7}
 {1,2,5,6} and {3,4,7}
 {1,2,4,7} and {3,5,6}
 {1,6,7} and  {2,3,4,5}

Reccurrence Relation
   i -> no. of elements, j -> sum
   f(i,j) = f(i-1,j) + f(i-1,j-i)
*/

int dpTwoSets(int n)
{
	int sum = (n * (n + 1)) / 2;
	if (sum % 2)
		return 0;

	sum /= 2;
	vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
	dp[0][0] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			dp[i][j] = dp[i - 1][j];
			int left = j - i;
			if (left >= 0)
				(dp[i][j] += dp[i - 1][left]) %= mod;
		}
	}
	return dp[n - 1][sum] % mod;
}

int main()
{
	int n;
	cin >> n;

	cout << dpTwoSets(n);
	return 0;
}