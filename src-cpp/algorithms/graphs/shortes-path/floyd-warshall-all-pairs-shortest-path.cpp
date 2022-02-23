#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

auto floydWarshall(vector<vector<int>> &adjMatrix)
{
    int n = adjMatrix.size();
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> next(n, vector<int>(n));

    auto setup = [&dp, &next, &n](vector<vector<int>> &matrix) -> void
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = matrix[i][j]; // Deep Copy as a base case
                if (matrix[i][j] != INF)
                    next[i][j] = j; // if dist != INF
            }
    };
    setup(adjMatrix);

    // FW Algo
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dp[i][k] + dp[k][j] < dp[i][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    next[i][j] = next[i][k];
                }

    // Repeat to check -ve cycles
    auto propogateNegativeCycles = [&next, &dp, &n]() -> void
    {
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dp[i][k] + dp[k][j] < dp[i][j])
                    {
                        dp[i][j] = -INF;
                        next[i][j] = -1;
                    }
    };
    propogateNegativeCycles();

    auto reconstructPath = [&dp, &next](int start, int end) -> vector<int>
    {
        vector<int> path;
        if (dp[start][end] == INF)
            return path;

        int at = start;
        for (; at != end; at = next[at][end])
        {
            if (at == -1)
                throw "Encountered Negative Cycle";
            path.push_back(at);
        }

        if (next[at][end] == -1)
            throw "Encountered Negative Cycle";

        path.push_back(end);
        return path;
    };

    return reconstructPath;
}

int main()
{
    vector<vector<int>> adjMat =
        {
            {0, 5, INF, 10},
            {INF, 0, 3, INF},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0}};

    return 0;
}
