#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int p[], int n)
{
    int m[n][n] = {0};
    int s[n][n] = {0};

    int j, q, min;

    for (int d = 1; d < n - 1; d++)
    {
        for (int i = 1; i < n - d; i++)
        {
            j = i + d;
            min = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
    return m[1][n - 1];
}

int main()
{
    int arr[] = {1, 2, 3, 4}; // dimensions of matrices ((1, 2) * (2, 3) * (3, 4))
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, size) << endl;

    int arr2[] = {5, 4, 6, 2, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr2, size2);

    return 0;
}