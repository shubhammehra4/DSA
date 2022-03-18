#include <bits/stdc++.h>
using namespace std;

int countLessOrEqual(vector<vector<int>> &matrix, int x)
{
    int cnt = 0, c = matrix[0].size() - 1; // start with the rightmost column
    for (int r = 0; r < matrix.size(); ++r)
    {
        while (c >= 0 && matrix[r][c] > x)
            --c; // decrease column until matrix[r][c] <= x
        cnt += (c + 1);
    }
    return cnt;
}

// binary-search
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int left = matrix[0][0], right = matrix[m - 1][n - 1];

    while (left < right)
    {
        int mid = (left + right) >> 1;
        if (countLessOrEqual(matrix, mid) < k)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

// heap
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int m = matrix.size(), n = matrix[0].size();
    priority_queue<int> maxHeap;

    for (auto &row : matrix)
    {
        for (auto num : row)
        {
            maxHeap.push(num);

            if (maxHeap.size() > k)
                maxHeap.pop();
        }
    }

    return maxHeap.top();
}