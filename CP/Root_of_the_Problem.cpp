#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ul unsigned long long
#define vt vector
#define vi vector<ll>
#define vb vector<bool>
#define pii pair<ll, ll>
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define ump unordered_map
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define loop(i, a, b) for (ll i = a; i < b; ++i)
#define rloop(i, a, b) for (ll i = a; i >= b; --i)
#define cn continue;
#define ln "\n"
#define out(x) cout << x << '\n';
#define log(x) cout << #x << ": " << x << " " << '\n';
static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    ll n;
    cin >> n;
    ll id, sum;
    ll root = 0;

    loop(i, 0, n)
    {
        cin >> id >> sum;
        // Every node appears once as an id, and
        // every node except for the root appears
        // once in a sum.  So if we subtract all
        // the sums from all the ids, we're left
        // with the root id.
        root += id - sum;
    }

    out(root);
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll tc = 1;
    cin >> tc;

    while (tc--)
        solve();

#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif

    return 0;
}
