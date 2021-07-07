#include <bits/stdc++.h>
using namespace std;

bool hotelBooking(vector<int> &arrive, vector<int> &depart, int K)
{
    vector<pair<int, int>> ans;
    int n = arrive.size();

    for (int i = 0; i < n; i++)
    {
        ans.push_back(make_pair(arrive[i], 1));
        ans.push_back(make_pair(depart[i], 0));
    }

    sort(ans.begin(), ans.end());
    int curr_active = 0, max_active = 0;

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].second == 1)
        {
            curr_active++;
            max_active = max(max_active, curr_active);
        }
        else
            curr_active--;
    }

    return (K >= max_active);
}

int main()
{
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 6, 8};

    if (hotelBooking(a, b, 1))
        cout << "Possible";
    else
        cout << "Not Possible";
}
