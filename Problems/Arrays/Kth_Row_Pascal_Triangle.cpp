#include <bits/stdc++.h>
using namespace std;

vector<int> getRowNaive(int N) // Can be used to generate full triangle
{
    vector<int> result;
    result.push_back(1);

    if (N == 0)
        return result;

    vector<int> prev = getRowNaive(N - 1);

    for (int i = 1; i < prev.size(); i++)
    {
        int curr = prev[i - 1] + prev[i];
        result.push_back(curr);
    }

    result.push_back(1);
    return result;
}

vector<int> getRow(int N)
{
    vector<int> result;
    int prev = 1;
    result.push_back(prev);

    for (int i = 1; i <= N; i++)
    {
        int curr = (prev * (N - i + 1)) / i;
        result.push_back(curr);
        prev = curr;
    }

    return result;
}

vector<vector<int>> PascalTriangle(int A)
{
    vector<vector<int>> v;

    for (int t = 0; t < A; t++)
    {
        vector<int> ans;
        int i = t + 1, c = 1;

        for (int j = 1; j <= i; j++)
        {
            ans.push_back(c);
            c = c * (i - j) / j;
        }

        v.push_back(ans);
    }

    return v;
}

void display(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    vector<int> v1 = getRowNaive(9);
    vector<int> v2 = getRow(9);
    display(v1);
    display(v2);
    vector<vector<int>> res = PascalTriangle(5);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";

        cout << endl;
    }

    return 0;
}