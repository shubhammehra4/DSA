#include <bits/stdc++.h>
using namespace std;
#define INF 1000007

int shortestDist(vector<vector<int>> graph)
{
    int N = graph[0].size();
    int cost[N], d[N], path[N];
    cost[N - 1] = 0;

    for (int i = N - 2; i >= 0; i--)
    {
        int min = 1000001;
        for (int j = i + 1; j < N; j++)
        {
            if (graph[i][j] == INF)
                continue;

            if (min > graph[i][j] + cost[j])
            {
                min = graph[i][j] + cost[j];
                d[i] = j;
            }
        }
        cost[i] = min;
    }

    return cost[0];
}

int main()
{
    vector<vector<int>> graph = {{INF, 1, 2, 5, INF, INF, INF, INF},
                                 {INF, INF, INF, INF, 4, 11, INF, INF},
                                 {INF, INF, INF, INF, 9, 5, 16, INF},
                                 {INF, INF, INF, INF, INF, INF, 2, INF},
                                 {INF, INF, INF, INF, INF, INF, INF, 18},
                                 {INF, INF, INF, INF, INF, INF, INF, 13},
                                 {INF, INF, INF, INF, INF, INF, INF, 2}};

    cout << shortestDist(graph);
    return 0;
}
