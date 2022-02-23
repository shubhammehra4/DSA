#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int left = 0;
    int right = (n * m) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int ele = matrix[mid / n][mid % n];

        if (target == ele)
            return true;

        if (ele < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

// modified for less operations
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int left = 0;
    int right = (n * m) - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int ele = matrix[mid / n][mid % n];

        if (ele < target)
            left = mid + 1;
        else
            right = mid;
    }

    return matrix[left / n][left % n] == target;
}
