#include <bits/stdc++.h>
using namespace std;

// O(log(min(n,m)))
double findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    if (A.empty() && B.empty())
        return -1;

    int n = A.size(), m = B.size();

    if (m < n)
        return findMedianSortedArrays(B, A);

    int l = 0, r = n, half = (n + m + 1) / 2;

    while (l <= r)
    {
        int m1 = (r + l) / 2;
        int m2 = half - m1;

        if (m1 < n && A[m1] < B[m2 - 1])
            l = m1 + 1;
        else if (0 < m1 && B[m2] < A[m1 - 1])
            r = m1;
        else
        {
            int maxleft = m1 == 0 ? B[m2 - 1] : m2 == 0 ? A[m1 - 1]
                                                        : max(A[m1 - 1], B[m2 - 1]);

            if ((n + m) & 1)
                return maxleft;

            int minright = m1 == n ? B[m2] : m2 == m ? A[m1]
                                                     : min(A[m1], B[m2]);
            return (maxleft + minright) / 2.0;
        }
    }

    return -1;
}

int main()
{
    return 0;
}