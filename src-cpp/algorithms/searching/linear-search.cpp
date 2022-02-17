#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == target)
            return i;

    return -1;
}

int *linearSearchPtr(vector<int> &arr, int target)
{
    for (auto &num : arr)
        if (num == target)
            return &num;

    return nullptr;
}

int rangedLinearSearch(vector<int> &arr, int target, int start, int end)
{
    if (start < 0 || end >= arr.size())
        throw invalid_argument("Invalid Range");

    for (int i = start; i < end; i++)
        if (arr[i] == target)
            return i;

    return -1;
}

vector<int> linearSearchAll(vector<int> &arr, int target)
{
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == target)
            res.push_back(i);

    return res;
}

void linearSearchAllRef(vector<int> &arr, int target, vector<int> &res)
{
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == target)
            res.push_back(i);
}