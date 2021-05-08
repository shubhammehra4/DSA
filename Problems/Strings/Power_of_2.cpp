#include <bits/stdc++.h>
using namespace std;

int powerOfTwo(string A)
{
    int N = A.size();
    long long int num = 0;

    if (N == 1 && A[N - 1] == '1') // odd
        return 0;

    while (N != 1 || A[N - 1] != '1')
    {
        if ((A[N - 1] - '0') % 2 == 1) // odd
            return 0;

        int i, j;
        // i is used to track index in current number.
        // j is used to track index for next iteration.
        for (i = 0, j = 0; i < N; i++)
        {
            num = num * 10 + A[i] - '0';
            if (num < 2)
            {
                // A[i]. E. g. 214 / 2 --> 107
                // ignore if first index 128 -> 064 is not required
                if (i != 0)
                    A[j++] = '0';

                continue;
            }
            A[j++] = (int)(num / 2) + '0';
            num = (num) - (num / 2) * 2;
        }
        A[j] = '\0';
        N = j;
    }

    return 1;
}

int main()
{
    string s1 = "12468462246684202468024";

    cout << powerOfTwo(s1);

    return 0;
}