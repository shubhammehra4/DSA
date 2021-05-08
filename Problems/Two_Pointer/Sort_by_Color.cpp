#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &A)
{
    int red = 0, blue = A.size() - 1, color = 0;
    while (color <= blue)
    {
        if (A[color] == 0)
            swap(A[red++], A[color++]);
        else if (A[color] == 2)
            swap(A[blue--], A[color]);
        else
            color++;
    }
}

int main()
{
    vector<int> A = {0, 1, 2, 2, 2, 1, 1, 1, 0, 0, 0, 1};

    sortColors(A);
    for (auto i : A)
        cout << i;

    return 0;
}