#include <bits/stdc++.h>
using namespace std;

string convertToZigZag(string A, int B)
{
    int N = A.length();
    vector<string> arr(B);
    int row = 0;
    bool down;

    if (B == 1)
        return A;

    for (int i = 0; i < N; ++i)
    {
        arr[row].push_back(A[i]);

        if (row == B - 1)
            down = false;
        else if (row == 0)
            down = true;

        (down) ? (row++) : (row--);
    }
    string res;
    for (auto i : arr)
        res += i;

    return res;
}

int main()
{
    string A = "PAYPALISHIRING";
    int B = 3;
    cout << convertToZigZag(A, B);

    return 0;
}