#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define INF 2e18

int removeElementNaive(vector<int> &A, int B)
{
    int n = A.size();
    int res = 0;
    vector<int> newRes;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != B)
        {
            res++;
            newRes.push_back(A[i]);
        }
    }
    A = newRes;
    return res;
}

// Space Effecient
int removeElement(vector<int> &A, int B)
{
    int cnt = 0;
    for (int j = 0; j < A.size(); j++)
    {
        if (A[j] != B)
        {
            A[cnt] = A[j];
            cnt++;
        }
    }
    return cnt;
}

int main()
{

    return 0;
}