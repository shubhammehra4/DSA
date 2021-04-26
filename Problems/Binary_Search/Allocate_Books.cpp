#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define INF 2e18

bool isPossible(vector<int> arr, int m, int curr_min)
{
    int n = arr.size();
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > curr_min)
            return false;

        if (curr_sum + arr[i] > curr_min)
        {
            studentsRequired++;
            curr_sum = arr[i];

            if (studentsRequired > m)
                return false;
        }
        else
            curr_sum += arr[i];
    }
    return true;
}

int books(vector<int> &A, int B)
{
    int n = A.size();

    if (n < B)
        return -1;

    int sum = 0;
    for (int i = 0; i < A.size(); i++)
        sum += A[i];

    int start = 0, end = sum;
    int res = INT_MAX;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (isPossible(A, B, mid))
        {
            res = min(res, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return res;
}

int main()
{
    vector<int> a = {5, 7, 10, 17};
    int b = 3;

    cout << books(a, b);

    return 0;
}