#include <bits/stdc++.h>
using namespace std;

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortInWaveNaive (int arr[], int n)
{
    sort (arr, arr + n);

    for (int i = 0; i < n - 1; i += 2)
        swap (&arr[i], &arr[i + 1]);
}

void sortInWave (int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i > 0 && arr[i - 1] > arr[i] )
            swap (&arr[i], &arr[i - 1]);

        if (i < n - 1 && arr[i] < arr[i + 1] )
            swap (&arr[i], &arr[i + 1]);
    }
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sortInWave (a, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}