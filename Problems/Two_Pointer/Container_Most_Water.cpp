#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxArea(vector<int> &A)
{
    int n = A.size();
    long long int i = 0, j = n - 1;
    long long int area = 0;

    while (i < j)
    {
        area = max(area, (min(A[i], A[j]) * (j - i)));

        if (A[i] < A[j])
            i++;
        else
            j--;
    }

    return area;
}

int main()
{

    return 0;
}