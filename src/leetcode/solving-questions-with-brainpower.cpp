#include <bits/stdc++.h>
using namespace std;

long long mostPoints(vector<vector<int>> &questions)
{
    long long n = questions.size();
    vector<long long> memo(n + 1, 0);

    for (long long idx = n - 1; idx >= 0; idx--)
    {
        long long points = questions[idx][0];
        long long power = questions[idx][1];

        long long solevQuestion = points + (idx + 1 + power <= n ? memo[idx + 1 + power] : 0);
        long long leaveQuestion = memo[idx + 1];

        memo[idx] = max(solevQuestion, leaveQuestion);
    }

    return memo[0];
}
