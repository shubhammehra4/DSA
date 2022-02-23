#include <bits/stdc++.h>
using namespace std;

struct WeightedDirectedEdge
{
    int from;
    int to;
    int weight; // cost to reach
};
auto comparator = [](const WeightedDirectedEdge &a, const WeightedDirectedEdge &b) -> bool
{
    return a.weight > b.weight;
};

auto comparator = [](const WeightedDirectedEdge &a, const WeightedDirectedEdge &b) -> bool
{
    return a.weight > b.weight;
};

auto kruskalsMinimumSpannigTree(vector<WeightedDirectedEdge> edgeLists)
{
    int n = edgeLists.size();

    // ---> union-find
    vector<int> parent(n);
    iota(begin(parent), end(parent), 0);
    vector<int> sz(n, 1);
    vector<WeightedDirectedEdge> mstEdges;

    auto find = [&parent](int p) -> int
    {
        int root = p;
        while (root != parent[root])
            root = parent[root];

        while (p != root)
        {
            int next = parent[p];
            parent[p] = root;
            p = next;
        }
        return root;
    };

    auto connected = [&find](int p, int q) -> bool
    { return find(p) == find(q); };

    auto unify = [&sz, &find, &parent](int p, int q) -> void
    {
        int root1 = find(p);
        int root2 = find(q);

        if (root1 == root2)
            return;

        if (sz[root1] < sz[root2])
        {
            sz[root2] += sz[root1];
            parent[root1] = root2;
        }
        else
        {
            sz[root1] += sz[root2];
            parent[root2] = root1;
        }
    };
    // <--- union-find

    sort(begin(edgeLists), end(edgeLists), comparator);

    for (auto edge : edgeLists)
    {
        if (!connected(edge.from, edge.to))
        {
            mstEdges.push_back(edge);
            unify(edge.from, edge.to);
        }
    }

    return mstEdges;
}
