#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
#define forn(i, e) for (lli i = 0; i < e; i++)
#define forsn(i, s, e) for (lli i = s; i < e; i++)
#define rforn(i, s) for (lli i = s; i >= 0; i--)
#define rforsn(i, s, e) for (lli i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
lli MOD = 998244353;
double eps = 1e-12;
#define INF 2e18
/*
You are given N binary strings of length N each. You need to find a binary string of 
length N which is different from all of the given strings.

Note:
A binary string is defined as a string consisting only of '0' and '1'.
A string is considered different from another string when they have different lengths, 
or when they differ in at least one position.
*/

int main()
{

    fast_cin();
    lli t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        set<string> st;
        string temp;
        // Store the input binary string in a set
        forn(i, n)
        {
            cin >> temp;
            st.insert(temp);
        }
        // Convert 0-n numbers to binary strings of length n
        // as they will result in n+1 binary string we can check which one in not
        // present in the set and print that

        forn(i, n + 1)
        {
            int num = i;
            string bin = "";
            while (num)
            {
                bin += to_string(num % 2);
                num /= 2;
            }
            reverse(all(bin));

            int currLen = bin.size();
            string res = string(n - currLen, '0');
            res += bin;

            if (st.find(res) == st.end())
            {
                cout << res << ln;
                break;
            }
        }
    }
    return 0;
}