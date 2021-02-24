#include <bits/stdc++.h>
using namespace std;

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Insertionsort (int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;

        while (j > 0 && a[j] < a[j - 1] )
        {
            swap (a[j], a[j - 1]);
            j--;
        }
    }
}

int main()
{
    int n = 10;
    int arr[n] = {2, 67, 89, 4, 34, 25, 67, 90, 32, 4};
    Insertionsort (arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}