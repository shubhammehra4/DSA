#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int

bool isOdd(lli a)
{
    return a & 1;
}

int main()
{
    lli n;
    cin >> n;

    lli sum = n * (n + 1) / 2;

    if (isOdd(sum))
        cout << "NO";
    else
    {
        cout << "YES\n";
        vector<lli> arr1, arr2;
        lli target = sum / 2LL;

        while (n)
        {
            if (target - n >= 0)
            {
                arr1.push_back(n);
                target -= n;
            }
            else
                arr2.push_back(n);

            n--;
        }

        cout << arr1.size() << endl;
        for (li ele : arr1)
            cout << ele << " ";
        cout << endl;

        cout << arr2.size() << endl;
        for (li ele : arr2)
            cout << ele << " ";
    }
    return 0;
}