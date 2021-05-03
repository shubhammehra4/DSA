#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &A, int B)
{
    if (A.size() < 3)
        return 0;

    sort(A.begin(), A.end());

    int i = 0;
    int sum, min = INT_MAX;

    for (int i = 0; i < A.size() - 2; i++)
    {
        int left = i + 1;
        int right = A.size() - 1;

        while (right > left)
        {
            int temp = A[i] + A[left] + A[right];
            int diff = abs(temp - B);

            if (diff == 0)
                return B;

            if (diff < min)
            {
                min = diff;
                sum = temp;
            }

            if (temp < B)
                left++;
            else
                right--;
        }
    }

    return sum;
}

int main()
{
    vector<int> A = {-1, 2, 1, -4};
    int B = 1;
    cout << threeSumClosest(A, B);

    return 0;
}