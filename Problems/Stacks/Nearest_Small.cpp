#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A)
{
    int n = A.size();
    vector<int> res(n, -1);

    stack<int> leftMin;
    leftMin.push(0);
    res[0] = -1;
    for (int i = 1; i < n; i++)
    {
        while (!leftMin.empty())
        {
            if (A[leftMin.top()] < A[i])
                break;
            leftMin.pop();
        }
        res[i] = (leftMin.empty()) ? -1 : A[leftMin.top()];
        leftMin.push(i);
    }

    return res;
}

int main()
{

    return 0;
}