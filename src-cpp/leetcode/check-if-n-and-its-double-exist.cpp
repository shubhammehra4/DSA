#include <bits/stdc++.h>
using namespace std;

// hash set
bool checkIfExist(vector<int> &arr)
{
    unordered_set<int> st;
    for (auto num : arr)
    {
        if (st.count(num * 2) || (num % 2 == 0 && st.count(num / 2)))
            return true;

        st.insert(num);
    }

    return false;
}

// sorting
bool checkIfExist(vector<int> &arr)
{
    int n = size(arr);
    sort(begin(arr), end(arr));

    for (int i = 0; i < n; i++)
    {
        int target;
        if (arr[i] < 0 && (arr[i] % 2 == 0))
            target = arr[i] / 2;
        else
            target = arr[i] * 2;

        if (binary_search(begin(arr) + i + 1, end(arr), target))
            return true;
    }

    return false;
}