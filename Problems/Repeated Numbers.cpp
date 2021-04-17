#include <bits/stdc++.h>
using namespace std;

int repeatedNumber (const vector<int> &A) //onnly works if there is one duplicate
{
    int n = A.size();
    long long int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }

    long long int m = n - 1;
    long long int total = (m * (m + 1) ) / 2;
    return sum - total;
}

int repeatedNumberAlter (const vector<int> &A)
{
    int slow = A[0];
    int fast = A[A[0]];

    while (slow != fast)
    {
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;

    while (slow != fast)
    {
        slow = A[slow];
        fast = A[fast];
    }

    if (slow == 0) return -1;

    return slow;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 3, 4};
    cout << repeatedNumber (arr);
    cout << repeatedNumberAlter (arr);
    return 0;
}
