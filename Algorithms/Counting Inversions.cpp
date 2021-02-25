#include <bits/stdc++.h>
using namespace std;

int Merge (int arr[], int temp[], int l, int mid, int r)
{
    int i = l, j = mid, k = l;
    int inv_count = 0;

    while ( (i <= mid - 1) && (j <= r) )
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++], inv_count = inv_count + (mid - i);
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l; i <= r; i++)
        arr[i] = temp[i];

    return inv_count;
}

int mergeSort (int arr[], int temp[], int l, int r)
{
    int mid, inv_count = 0;

    if (r > l)
    {
        mid = (r + l) / 2;
        inv_count += mergeSort (arr, temp, l, mid);
        inv_count += mergeSort (arr, temp, mid + 1, r);
        inv_count += Merge (arr, temp, l, mid + 1, r);
    }

    return inv_count;
}


int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = { 2, 4, 3, 1, 5 };
    int n = sizeof (b) / sizeof (b[0]);
    int temp[n];
    int ans = mergeSort (b, temp, 0, n - 1);
    cout << " Number of Inversions are " << ans;
    return 0;
}