//Divide & Conquer
//Stable
#include <bits/stdc++.h>
using namespace std;

void Merge (int a[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int temp[10005];

    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    for (; i <= mid; i++)
    {
        temp[k++] = a[i];
    }

    for (; j <= h; j++)
    {
        temp[k++] = a[j];
    }

    for (i = l; i <= h; i++)
    {
        a[i] = temp[i];
    }
}

void IMergeSort (int a[], int n)
{
    int mid, l, h, p;

    for (p = 2; p <= n; p *= 2)
    {
        for (int i = 0; i + p - 1 < n; i += p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge (a , l , mid , h);
        }
    }

    if (p / 2 < n)
    {
        Merge (a , 0 , p / 2 - 1 , n - 1);
    }
}

int main()
{
    int n = 10;
    int arr[n] = {1, 56, 23, 13, 45, 90, 76, 53, 24, 59};
    IMergeSort (arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}