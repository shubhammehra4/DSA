#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int compareVersion(string A, string B)
{
    unsigned long long vnum1 = 0, vnum2 = 0;
    int n = A.size(), m = B.size();

    for (int i = 0, j = 0; (i < n || j < m);)
    {
        while (i < n && A[i] != '.')
        {
            vnum1 = vnum1 * 10 + (A[i] - '0');
            i++;
        }
        while (j < m && B[j] != '.')
        {
            vnum2 = vnum2 * 10 + (B[j] - '0');
            j++;
        }

        if (vnum1 > vnum2)
            return 1;
        if (vnum1 < vnum2)
            return -1;

        vnum1 = vnum2 = 0;
        i++, j++;
    }

    return 0;
}

int main()
{
    string v1 = "888.80", v2 = "888.7";

    cout << compareVersion(v1, v2);

    return 0;
}