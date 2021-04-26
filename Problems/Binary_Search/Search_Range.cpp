#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> arr, int x, int n, bool last)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            res = mid;
            if (last)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return res;
}

vector<int> searchRange(const vector<int> &A, int B)
{
    int n = A.size();
    int start = BinarySearch(A, B, n, false);
    int end = BinarySearch(A, B, n, true);

    vector<int> res;
    res.push_back(start);
    res.push_back(end);
    return res;
}

int main()
{
    vector<int> a = {5, 7, 7, 8, 8, 10};
    int b = 8;

    vector<int> ans = searchRange(a, b);
    cout << ans[0] << "-" << ans[1];

    return 0;
}