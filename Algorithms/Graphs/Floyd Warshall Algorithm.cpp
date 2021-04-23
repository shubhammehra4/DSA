#include <bits/stdc++.h>
#define fab(a,b,i) for(int i=a;i<b;i++)
using namespace std;
#define INF 0x3f3f3f3f

class floydWarshall {
        int n;
        vector<vector<int>> dp;
        vector<vector<int>> next;
    public:
        floydWarshall (vector<vector<int>> adjMat);
        void allPairShortesPath();
        void propagateNegativeCycles();
        void reconstructPath (int s, int e);
};

floydWarshall::floydWarshall (vector<vector<int>> adjMat)
{
    n = adjMat.size();
    dp.resize (n, vector<int> (n) );
    next.resize (n, vector<int> (n, -1) );
    fab (0, n, i)
    {
        fab (0, n, j)
        {
            dp[i][j] = adjMat[i][j];

            if (adjMat[i][j] != INF)
                next[i][j] = j;
        }
    }
}

void floydWarshall::propagateNegativeCycles()
{
    fab (0, n, k)
    {
        fab (0, n, i)
        {
            fab (0, n, j)
            {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                {
                    dp[i][j] = - INF;
                    next[i][j] = -1;
                }
            }
        }
    }
}

void floydWarshall::allPairShortesPath()
{
    fab (0, n, k)
    {
        fab (0, n, i)
        {
            fab (0, n, j)
            {
                if (dp[i][k] + dp[k][j] < dp[i][j])
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    propagateNegativeCycles();
}

void floydWarshall::reconstructPath (int start, int end)
{
    vector<int> path;

    if (dp[start][end] == INF)
    {
        cout << "No Path exists\n";
        return;
    }

    int i = start;

    for (; i != end; i = next[i][end])
    {
        if (i == -1) { cout << "Negative Cycle\n"; return;}

        path.push_back (i);
    }

    if (next[i][end] == -1) return;

    path.push_back (end);
    fab (0, path.size(), i)
    {
        cout << path[i] << " ";
    }
    cout << "\nDistance : " << dp[start][end] << endl;
}


int main()
{
    vector<vector<int>> adjMat =
    {
        { 0, 5, INF, 10 },
        { INF, 0, 3, INF },
        { INF, INF, 0, 1 },
        { INF, INF, INF, 0 }
    };
    floydWarshall f (adjMat);
    f.allPairShortesPath();
    f.reconstructPath (0, 1);
    f.reconstructPath (0, 2);
    f.reconstructPath (0, 3);
    f.reconstructPath (1, 2);
    f.reconstructPath (1, 3);
    f.reconstructPath (2, 3);
    f.reconstructPath (3, 1);
    f.reconstructPath (3, 2);
    return 0;
}
