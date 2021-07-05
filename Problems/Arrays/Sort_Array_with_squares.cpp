#include <bits/stdc++.h>
using namespace std;

vector<int> solve (vector<int> &A)
{
    int n = A.size();
    vector<int> ans (n, 0);
    int i = 0, j = n - 1;
    int k = n - 1;

    while (i <= j)
    {
        if (abs (A[i]) > abs (A[j]) )
        {
            ans[k--] = A[i] * A[i];
            i++;
        }
        else
        {
            ans[k--] = A[j] * A[j];
            j--;
        }
    }

    return ans;
}

int main()
{
    vector<int> v = { -20, -6, -1, 2, 3, 9, 15};
    vector<int> res = solve (v);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}
