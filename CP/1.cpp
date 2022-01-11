#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define sep(i, a, b) for (int i = a; i >= b; --i)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define db double
#define lb lower_bound
#define ub upper_bound
#define mp(x, y) make_pair(x, y)
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define fr first
#define sc second
#define pii pair<int, int>
#define pi 3.14159265358979323846

const int mod = 1000000007;
const int MAX = 8000000000000000064LL;
const int MIN = -8000000000000000064LL;
int add(int x, int y)
{
    int res = x + y;
    return (res >= mod ? res - mod : res);
}
int mul(int x, int y)
{
    int res = x * y;
    return (res >= mod ? res % mod : res);
}
int sub(int x, int y)
{
    int res = x - y;
    return (res < 0 ? res + mod : res);
}
int power(int x, int y)
{
    int res = 1;
    x %= mod;
    while (y)
    {
        if (y & 1)
            res = mul(res, x);
        y >>= 1;
        x = mul(x, x);
    }
    return res;
}
int mod_inv(int x) { return power(x, mod - 2); }
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int x, int y)
{
    int res = x / gcd(x, y);
    return (res * y);
}
// int nCr(int n,int r){int ans=fact[n]; ans*=mod_inv(fact[n-r]);ans%=mod; ans*=mod_inv(fact[r]);ans%=mod; return ans;}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void solve()
{
    int n, m, c, k;
    int ans = INT_MAX;
    cin >> n >> m >> c >> k;
    vector<vector<int>> cost(n, vector<int>(m, 0));

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> cost[i][j];
        }
    }
    set<pair<int, int>> S;
    rep(i, 0, k)
    {
        int u, v;
        cin >> u >> v;
        S.insert(mp(u, v));
    }

    // Direct bfs without special points
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> mnheap;
    mnheap.push({cost[0][0], 0, 0});
    while (!mnheap.empty())
    {
        vector<int> cur = mnheap.top();
        mnheap.pop();

        if (cur[1] == n - 1 && cur[2] == m - 1)
        {
            ans = cur[0];
            break;
        }

        rep(i, 0, 4)
        {
            int new_u = cur[1] + dx[i];
            int new_y = cur[2] + dy[i];

            if (new_u >= 0 && new_u < n && new_y >= 0 && new_y < m)
            {
                mnheap.push({cur[0] + cost[new_u][new_y], new_u, new_y});
            }
        }
    }

    if (k > 1)
    {
        // bfs to find min cost from (0, 0) to special points
        int min_dis1 = INT_MAX;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> mnheap1;
        mnheap1.push({cost[0][0], 0, 0});
        while (!mnheap1.empty())
        {
            vector<int> cur = mnheap1.top();
            mnheap1.pop();

            pair<int, int> spl;
            spl.fr = cur[1];
            spl.sc = cur[2];
            if (S.find(spl) != S.end())
            {
                min_dis1 = cur[0];
                break;
            }

            rep(i, 0, 4)
            {
                int new_u = cur[1] + dx[i];
                int new_y = cur[2] + dy[i];

                if (new_u >= 0 && new_u < n && new_y >= 0 && new_y < m)
                {
                    mnheap1.push({cur[0] + cost[new_u][new_y], new_u, new_y});
                }
            }
        }

        // bfs to find min cost from (n-1, m-1) to special points
        int min_dis2 = INT_MAX;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> mnheap2;
        mnheap2.push({cost[n - 1][m - 1], n - 1, m - 1});
        while (!mnheap2.empty())
        {
            vector<int> cur = mnheap2.top();
            mnheap2.pop();

            pair<int, int> spl;
            spl.fr = cur[1];
            spl.sc = cur[2];
            if (S.find(spl) != S.end())
            {
                min_dis2 = cur[0];
                break;
            }

            rep(i, 0, 4)
            {
                int new_u = cur[1] + dx[i];
                int new_y = cur[2] + dy[i];

                if (new_u >= 0 && new_u < n && new_y >= 0 && new_y < m)
                {
                    mnheap2.push({cur[0] + cost[new_u][new_y], new_u, new_y});
                }
            }
        }
        int ans2 = min_dis1 + min_dis2 + c;
        ans = min(ans, ans2);
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    rep(i, 0, t)
    {
        // cout << "Case #" << i + 1 << ": "
        solve();
    }
    return 0;
}