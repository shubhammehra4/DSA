#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size = 15;
    vector<int> parent(size);
    iota(begin(parent), end(parent), 0);
    vector<int> sz(size, 1);
    int numComponents = size;

    auto find = [&parent](int p) -> int
    {
        int root = p;
        while (root != parent[root])
            root = parent[root];

        while (p != root) // path compression
        {
            int next = parent[p];
            parent[p] = root;
            p = next;
        }
        return root;
    };

    auto connected = [&find](int p, int q) -> bool
    { return find(p) == find(q); };

    auto componentSize = [&find, &sz](int p) -> int
    { return sz[find(p)]; };

    auto unify = [&sz, &find, &parent, &numComponents](int p, int q) -> void
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

        numComponents--;
    };
}