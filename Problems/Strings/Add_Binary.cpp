#include <bits/stdc++.h>
using namespace std;

string addBinary(string A, string B)
{
    string res = "";
    int s = 0;
    int i = A.size() - 1, j = B.size() - 1;

    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0) ? A[i] - '0' : 0);
        s += ((j >= 0) ? B[j] - '0' : 0);

        res += char(s % 2 + '0');
        s /= 2;
        i--, j--;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string a = "100", b = "11";

    cout << addBinary(a, b);

    return 0;
}