#include <bits/stdc++.h>
using namespace std;

/*
   Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
   If the array is already sorted, then the inversion count is 0, but if the array is sorted 
   in the reverse order, the inversion count is the maximum. 
   Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
*/

int merge(int arr[], int l, int mid, int r)
{
    int i = l, k = l, j = mid;
    int inv_count = 0;

    while ((i <= mid - 1) && (j <= r))
    {
        if (arr[i] <= arr[j])
            i++;
        else
            j++, inv_count += mid - i;
    }

    return inv_count;
}

// Merge Sort
int countInversion(int arr[], int l, int r)
{
    int inv_count = 0, mid;

    if (l < r)
    {
        mid = (r + l) / 2;
        inv_count += countInversion(arr, l, mid);
        inv_count += countInversion(arr, mid + 1, r);
        inv_count += merge(arr, l, mid + 1, r);
    }

    return inv_count;
}

// Naive
int countInversionNaive(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {5, 4, 3, 2, 1};
    int n = sizeof(b) / sizeof(b[0]);

    int ans = countInversion(b, 0, n - 1);
    cout << "Number of Inversions are " << ans;
    return 0;
}