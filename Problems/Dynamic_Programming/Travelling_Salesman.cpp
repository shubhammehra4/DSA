#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define INF INT_MAX
#define N 4

int cost[N][N] = {{0, 10, 15, 20},
                  {5, 0, 9, 10},
                  {6, 13, 0, 12},
                  {8, 8, 9, 0}};
int memo[1 << N][N];
void setup()
{
    for (int i = 0; i < 1 << N; i++)
    {
        for (int j = 0; j < N; j++)
            memo[i][j] = -1;
    }
}

int TSP(int bitmask, int pos)
{
    setup();
    int res = INF;
    if (bitmask == ((1 << N) - 1))
        return cost[pos][0]; //All vertices have been explored Cost to go back

    if (memo[bitmask][pos] != -1)
        return memo[bitmask][pos]; //If this has already been computed Just return the value, no need to recompute

    for (int i = 0; i < N; ++i)
    {
        if ((bitmask & (1 << i)) == 0)
        {
            //If the vertex has not been visited Visit the vertex
            res = min(res, TSP(bitmask | (1 << i), i) + cost[pos][i]);
            //  bitmask | (1 << i) sets the ith bit of bitmask to 1, which represents that the ith vertex has been visited
        }
    }
    memo[bitmask][pos] = res;
    return res;
}

int main()
{
    cout << TSP(0, 0);
    return 0;
}