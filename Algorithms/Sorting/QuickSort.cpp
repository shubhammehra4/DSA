// Divide & Conquer
// Unstable
#include <bits/stdc++.h>
using namespace std;

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort (int a[], int l, int r)
{
    if (r - l <= 1) return;

    int lower = l + 1;

    for (int upper = l + 1; upper < r; upper++)
    {
        if (a[upper] < a[l])
        {
            swap (a[lower], a[upper]);
            lower++;
        }
    }

    swap (a[l], a[lower - 1]);
    QuickSort (a, l, lower);
    QuickSort (a, l + 1, r);
}

int main()
{
    int n = 10;
    int arr[n] = {1, 3, 45, 7, 34, 90, 23, 88, 9, 10};
    QuickSort (arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}