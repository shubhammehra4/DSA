#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Similar to Allocate Books

bool canBeAlloted(int K, vector<int> &L, int threshold)
{
    ll board_length = 0, painter = 1;
    int n = L.size();

    for (int i = 0; i < n; i++)
    {
        if (L[i] > threshold)
            return false;

        board_length += long(L[i]);

        if (board_length > threshold)
        {
            board_length = 0;
            painter++;
            i--;
            if (painter > K)
                return false;
        }
    }
    return true;
}

int paint(int K, int T, vector<int> &L)
{
    ll l = 0, r = 0, mid, ans = 0, s = 0;
    int n = L.size();
    for (int i = 0; i < n; i++)
    {
        r += long(L[i]);
        ans = max(ans, (1ll) * L[i]);
    }

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (canBeAlloted(K, L, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return (ans * long(T)) % 10000003;
}
int main()
{
    cout << (1ll);

    return 0;
}