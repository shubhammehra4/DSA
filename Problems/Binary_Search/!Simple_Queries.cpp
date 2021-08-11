#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100010
#define mod 1000000007

ll prod[MAX];

void preCompute()
{
    if (prod[1] != 0)
        return;

    for (ll i = 1; i < MAX; i++)
        prod[i] = i;

    for (ll i = 2; i < MAX; i++)
    {
        for (ll j = 2 * i; j < MAX; j += i)
            prod[j] = (prod[j] * i) % mod;
    }
}

vector<int> solve(vector<int> &a, vector<int> &b)
{
    preCompute();
    ll i, j, k, n = a.size(), m = 1e9 + 7;
    vector<ll> freq(n);
    stack<ll> st;
    st.push(0);

    for (ll i = 1; i < n; i++)
    {
        while (!st.empty() && a[st.top()] <= a[i])
        {
            ll index = st.top();
            st.pop();
            ll left = index + 1;
            ll right = (i - index);

            if (!st.empty())
                left = index - st.top();

            freq[index] = left * right;
        }

        st.push(i);
    }

    while (!st.empty())
    {
        ll index = st.top();
        st.pop();
        ll left = index + 1;
        ll right = (n - index);

        if (!st.empty())
            left = index - st.top();

        freq[index] = left * right;
    }

    vector<pair<ll, ll>> store(n);

    for (i = 0; i < n; i++)
    {
        ll x = prod[a[i]];
        store[i] = make_pair(prod[a[i]], freq[i]);
    }

    sort(store.begin(), store.end());
    reverse(store.begin(), store.end());

    for (i = 1; i < n; i++)
        store[i].second = store[i - 1].second + store[i].second;

    vector<int> ans(b.size());

    for (i = 0; i < b.size(); i++)
    {
        int l = 1, r = n - 1;

        if (store[0].second >= b[i])
        {
            ans[i] = store[0].first;
            continue;
        }

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (store[mid].second >= b[i] && store[mid - 1].second < b[i])
            {
                ans[i] = store[mid].first;
                break;
            }
            else if (store[mid].second < b[i])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    return ans;
}

int main()
{
    return 0;
}