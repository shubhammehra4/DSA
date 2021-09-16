/*
You are given a double-ended queue Q. Initially, it contains elements Q1,Q2,…,QM in this order. 
Each of these elements is an integer between 1 and N (inclusive) and each integer between 
1 and N (inclusive) occurs in the queue at least once.

We want to pop some (possibly zero) elements from the front of the queue and some 
(not necessarily the same number, possibly zero) elements from the back. Among all the popped 
elements, each integer between 1 and N (inclusive) should appear at least once. Find the 
smallest possible total number of elements we need to pop.

Approach-

Take the position of last occurance of every element in the queue 
and store in a set so they are sorted

Take the suffix as the initial answer (pop all from end)

Take prefix elements and if they are present remove their last index from the set 
and re-calculate the answer\
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<ll> v64;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

int main()
{

    fast_cin();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        unordered_map<ll, ll> last_ind;
        v64 arr(m);

        forn(i, m)
        {
            cin >> arr[i];
            last_ind[arr[i]] = i;
        }

        set<ll> st;
        for (auto [num, idx] : last_ind)
            st.insert(idx);

        ll ans = m - *st.begin(); // taking all sufix

        forn(i, m)
        {
            // If that ele is present is the set then erase that ele from the set
            if (st.count(last_ind[arr[i]]))
                st.erase(last_ind[arr[i]]);

            // i+1 - prefix length
            // m-*st.begin() - sufffix length
            if (!st.empty())
                ans = min(ans, i + 1 + m - *st.begin());
            else
                ans = min(ans, i + 1);
        }

        cout << ans << ln;
    }
    return 0;
}