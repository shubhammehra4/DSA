#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int id;
    vector<TreeNode *> children;
    TreeNode(int _id) : id(_id), children(vector<TreeNode *>()) {}
};

auto createMinSparseTable(vector<int> &nums)
{
    int n = nums.size();
    int P = floor(log2(n));

    vector<int> log2Lookup(n + 1, 0);
    for (int i = 2; i <= n; i++)
        log2Lookup[i] = log2Lookup[i / 2] + 1;

    vector<vector<int>> sparseTable(P + 1, vector<int>(n, INT_MIN));
    vector<vector<int>> indexTable(P + 1, vector<int>(n, INT_MIN)); // index of the min ele

    for (int i = 0; i < n; i++)
    {
        sparseTable[0][i] = nums[i];
        indexTable[0][i] = i;
    }

    for (int p = 1; p <= P; p++)
    {
        for (int i = 0; i + (1 << p) <= n; i++)
        {
            int left = sparseTable[p - 1][i];
            int right = sparseTable[p - 1][i + (1 << (p - 1))];

            sparseTable[p][i] = min(left, right);

            if (left <= right)
                indexTable[p][i] = indexTable[p - 1][i];
            else
                indexTable[p][i] = indexTable[p - 1][i + (1 << (p - 1))];
        }
    }

    auto minIndexQuery = [&sparseTable, &indexTable, &log2Lookup](int l, int r) -> int
    {
        int len = r - l + 1;
        int p = log2Lookup[len];
        int k = 1 << p;

        int left = sparseTable[p][l];
        int right = sparseTable[p][r - k + 1];

        if (left <= right)
            return indexTable[p][l];
        return indexTable[p][r - k + 1];
    };

    return minIndexQuery;
}

void init(int n, TreeNode *root)
{
    vector<TreeNode *> nodeOrder((2 * n) - 1);
    vector<int> depth((2 * n) - 1);
    vector<int> lastOcccurunce(n);
    int tourIndex = 0;

    // Visit a Node in the tour
    auto visit = [&nodeOrder, &depth, &lastOcccurunce, &tourIndex](TreeNode *node, int nodeDepth) -> void
    {
        nodeOrder[tourIndex] = node;
        depth[tourIndex] = nodeDepth;
        lastOcccurunce[node->id] = tourIndex;
        tourIndex += 1;
    };

    // dfs
    function<void(TreeNode *, int)> eulerianTour =
        [&visit, &eulerianTour](TreeNode *node, int nodeDepth = 0) -> void
    {
        if (node == nullptr)
            return;

        visit(node, nodeDepth);
        for (auto child : node->children)
        {
            eulerianTour(child, nodeDepth + 1);
            visit(node, nodeDepth); // after visiting the sub tree revisit the node
        }
    };

    eulerianTour(root, 0);
    auto depthQueryIndex = createMinSparseTable(depth);

    auto lowestCommonAncestor = [&nodeOrder, &depthQueryIndex, &lastOcccurunce](int index1, int index2) -> TreeNode *
    {
        auto l = min(lastOcccurunce[index1], lastOcccurunce[index2]);
        auto r = max(lastOcccurunce[index1], lastOcccurunce[index2]);

        int i = depthQueryIndex(l, r);

        return nodeOrder[i];
    };
}