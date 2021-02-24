#include <bits/stdc++.h>
using namespace std;

#define V 5

int minKey (int cost[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && cost[v] < min)
            min = cost[v], min_index = v;

    return min_index;
}

void printMST (int mstFinal[], int graph[V][V])
{
    cout << "Edge \tCost\n";

    for (int i = 1; i < V; i++)
        cout << mstFinal[i] << " - " << i << " \t" << graph[i][mstFinal[i]] << " \n";
}

void primMST (int graph[V][V])
{
    int mstFinal[V];
    int cost[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        cost[i] = INT_MAX, mstSet[i] = false;

    cost[0] = 0;
    mstFinal[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey (cost, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < cost[v])
                mstFinal[v] = u, cost[v] = graph[u][v];
        }
    }

    printMST (mstFinal, graph);
}

int main()
{
    int graph[V][V] =
    {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }
    };
    primMST (graph);
    return 0;
}