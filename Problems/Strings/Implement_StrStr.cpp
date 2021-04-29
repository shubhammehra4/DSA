#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define INF 2e18

int strStr(const string A, const string B)
{
    int start = 0, temp_start = start, j = 0;
    while (temp_start < A.size() && j < B.size())
    {
        if (A[temp_start] == B[j])
            temp_start++, j++;
        else
            j = 0, temp_start = ++start;

        if (j == B.size())
            return start;
    }
    return -1;
}

int main()
{
    string s = "hellogeekhello";
    string s2 = "geek";

    cout << strStr(s, s2);

    return 0;
}