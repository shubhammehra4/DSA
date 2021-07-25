#include <bits/stdc++.h>
using namespace std;

void findMaximumStr(string str, int k, string &max)
{
    if (k == 0)
        return;

    int n = str.length();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] < str[j])
            {
                swap(str[i], str[j]);

                if (str.compare(max) > 0)
                    max = str;

                findMaximumStr(str, k - 1, max);
                swap(str[i], str[j]);
            }
        }
    }
}

string maximalString(string A, int B)
{
    string max = A;
    findMaximumStr(A, B, max);

    return max;
}

int main()
{

    return 0;
}