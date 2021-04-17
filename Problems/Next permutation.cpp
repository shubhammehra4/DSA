#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation (vector<int> &a)
{
    int n = a.size();
    int i, j;

    for (i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
            break;
    }

    if (i == -1)
    {
        reverse (a.begin(), a.end() );
        return a;
    }
    else
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] <= a[i])
                break;
        }

        swap (a[i], a[j - 1]);
        sort (a.begin() + i + 1, a.end() );
        return a;
    }
}

int main()
{
    vector<int> v = {251, 844, 767, 778, 658, 337, 10, 252, 632, 262,
                     707, 506, 701, 475, 410, 696, 631, 903, 516, 149,
                     344, 101, 42, 891, 991
                    };
    vector<int> A = nextPermutation (v);

    for (auto &i : A)
        cout << i << " ";

    return 0;
}

