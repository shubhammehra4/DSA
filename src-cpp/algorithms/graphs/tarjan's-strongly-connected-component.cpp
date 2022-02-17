#include <bits/stdc++.h>
using namespace std;
const int UNVISITED = -1;

auto trajanStronglyConnectedComponents(vector<vector<int>> &adjLists)
{
    int n = adjLists.size();
    int id = 0;
    int sccCount = 0;

    vector<int> ids(n, UNVISITED);
    vector<int> lowLink(n, 0);
    vector<bool> onStack(n, false);
    stack<int> st;

    function<void(int)> dfs = [&](int at) -> void
    {
        st.push(at);
        onStack[at] = true;
        ids[at] = lowLink[at] = id++;

        for (auto to : adjLists[at])
        {
            if (ids[to] == UNVISITED)
                dfs(to);
            if (onStack[to])
                lowLink[at] = min(lowLink[at], lowLink[to]);
        }

        if (ids[at] == lowLink[at]) // to check if we are the start of a scc
        {
            while (!st.empty())
            {
                auto node = st.top();
                st.pop();
                onStack[node] = false;
                lowLink[node] = ids[at];
                if (node == at)
                    break;
            }
            sccCount += 1;
        }
    };

    for (int i = 0; i < n; i++)
        if (ids[i] == UNVISITED)
            dfs(i);

    return lowLink;
}