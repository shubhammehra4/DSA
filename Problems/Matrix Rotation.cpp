#include <bits/stdc++.h>
using namespace std;

void rotate90Clockwise (vector<vector<int> > &A, int n)
{
    int m = n - 1;
    int temp;

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < m - i; j++)
        {
            temp = A[i][j];
            A[i][j] = A[m - j][i];
            A[m - j][i] = A[m - i][m - j];
            A[m - i][m - j] = A[j][m - i];
            A[j][m - i] = temp;
        }
    }
}

int main()
{
    vector<vector<int> > arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    rotate90Clockwise (arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }
}