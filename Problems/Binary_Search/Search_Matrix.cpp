#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
        return false;

    int n = matrix.size(), m = matrix[0].size();
    int start = 0, end = n * m - 1, mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        int e = matrix[mid / m][mid % m]; // Coverting 2d into 1d

        if (target < e)
            end = mid - 1;
        else if (target > e)
            start = mid + 1;
        else
            return true;
    }

    return false;
}

int main()
{
    return 0;
}