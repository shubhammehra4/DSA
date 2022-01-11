// POSITIONAL_SUBSTITUTION

#include <bits/stdc++.h>
using namespace std;

void solve() {
    string key;
    string msg;
    cin >> key >> msg;
    int n = msg.size();
    string ans = "";

    for (int i=0,x=0; i<n; i += 2,x++) {
      int val = 0;

      if (msg[i] >= '0' && msg[i] <= '9') {
        val = msg[i] - '0';
      } else {
        val = msg[i] - 'a' + 10;
      }

      val *= 16;
      
      if (msg[i + 1] >= '0' && msg[i + 1] <= '9') {
        val += msg[i + 1] - '0';
      } else {
        val += msg[i + 1] - 'a' + 10;
      }


      int xr = key[x % key.size()] - 'A';
      int res = val ^ xr;
      ans.push_back((char)(res % 26 + 'A'));
    }

    cout << ans << endl;
}

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}