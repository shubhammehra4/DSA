// Substitution Cipher

#include <bits/stdc++.h>
using namespace std;

int triangulation (int val) {

    int ans = 0;

    int arr[7] = {0};
    for (int i=6; i>=0; --i) {
        if (val & (1 << i))
            arr[i] = 1;
        else
            arr[i] = 0;
    }

    for (int i=6; i>=0; --i) {
        ans = ans | (arr[i] << i);

        for (int j=0; j<i; ++j) {
            arr[j] = arr[j] ^ arr[j + 1];
        }
    }

    return ans;
}

void solve() {

    // input of PLAINTEXT
    string s;
    cin >> s;

    // input of key
    long long int k;
    cin >> k;
    k %= 26;

    int n = s.size();

    for (int i=0; i<n; ++i) {

        // ascii value of each character = int(s[i])
        int asc = int(s[i]);

        // perform triangulation on each digit
        int new_val = triangulation(asc);

        // removing the key from new_val
        int chr = new_val - 65;
        chr = (chr - k + 26) % 26;
        char fnl_chr = char(chr + 65);

        // output deciphered character
        cout << fnl_chr;
    }
}

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}