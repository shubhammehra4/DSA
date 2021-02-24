#include <bits/stdc++.h>
using namespace std;

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort (int a[], int n)
{
    int k;

    for (int i = 0; i < n; i++)
    {
        k = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[k])
                k = j;
        }

        swap (a[i], a[k]);
    }
}

int main()
{
    int n = 10;
    int a[n] = {1, 56, 23, 13, 45, 90, 76, 55, 23, 56};
    SelectionSort (a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}