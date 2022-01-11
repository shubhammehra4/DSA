#include <bits/stdc++.h>
using namespace std;

// #define int long long int
#define ll long long int
#define ul unsigned long long
const int mod = 1e9 + 7;
#define vt vector
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vi, greater<int>>
#define ump unordered_map
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define loop(i, a, b) for (int i = a; i < b; ++i)
#define rloop(i, a, b) for (int i = a; i >= b; --i)
#define cn continue;
#define ln "\n"
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define bs(v, a) binary_search(all(v), a)
#define uprb(v, a) upper_bound(v.begin(), v.end(), a)
#define lowb(v, a) lower_bound(v.begin(), v.end(), a)
#define mx(v) *max_element(all(v))
#define mn(v) *min_element(all(v))
#define all(x) x.begin(), x.end()
#define sz(x) (int)((x).size())
#define range(a, b) substr(a, b - a + 1)
#define out(x) cout << x << '\n';
#define log(x) cout << #x << ": " << x << " " << '\n';
#define LOG(x)            \
    for (auto &i : x)     \
        cout << i << " "; \
    cout << '\n';
#define graph(adj, e)  \
    loop(i, 0, e)      \
    {                  \
        int u, v;      \
        cin >> u >> v; \
        adj[u].pb(v);  \
        adj[v].pb(u);  \
    }
#define lcm(a, b) ((a) * (b)) / __gcd((a), (b))
#define gcd(a, b) (__gcd((a), (b)))
#define setbits(n) __builtin_popcountll(n)
#define zerobits(n) __builtin_ctzll(n)
#define countbits(n) (int)log2(n) + 1
static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
bool isprime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0 and n != 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

/*------------------------------------------------------------------------------------------------------*/

template <typename A>
ostream &operator<<(ostream &cout, vt<A> const &v);
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) { return cout << p.ff << " " << p.ss; }
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v)
{
    loop(i, 0, sz(v)) { cout << v[i] << " "; }
    return cout << "\n";
}
template <typename A, typename B>
istream &operator>>(istream &cin, pair<A, B> &p)
{
    cin >> p.first;
    return cin >> p.second;
}
template <typename A>
istream &operator>>(istream &cin, vt<A> &v)
{
    for (auto &x : v)
        cin >> x;
    return cin;
}

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vb v)
{
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); ++i)
    {
        if (!first)
        {
            res += ",";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for (size_t i = 0; i < N; ++i)
    {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ",";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) +
                                        +to_string(p.second) + ")"; }
void dbg_out() { cout << "\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cout << " " << to_string(H);
    dbg_out(T...);
}
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: ", dbg_out(__VA_ARGS__)

/*------------------------------------------------------------------------------------------------------*/

void solve()
{
    int n;
    cin >> n;
    vi b(n);
    cin >> b;
    ump<int, int> m;
    vi res(n);

    loop(i, 0, n)
    {
        int a = 0;
        cout << m[a % b[i]] << ln;

        while (m[a % b[i]] != 0)
        {
            a++;
            cout << "hello";
        }
        m[a % b[i]]++;

        // m[a % b[i]]++;
        // res[i] = a;
    }
    // for (auto it : m)
    //     cout << it.first << "-" << it.second << " ";

    // cout << ln << res;
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

#ifndef ONLINE_JUDGE
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#endif

    return 0;
}
