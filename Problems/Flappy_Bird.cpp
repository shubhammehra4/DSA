#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair<lli, lli> p64;
#define forn(i, e) for (lli i = 0; i < e; i++)
#define ln "\n"
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

/*
Chef is playing a noob version of the game Flappy Bird with the following rules:

 The bird starts at a height H at x=0.
 
 There are N obstacles (numbered 1 through N). For each valid i, the i-th obstacle 
 is at a position xi and it has a height hi.
 
 For each integer i (0≤i<xN), Chef has the option to click once when the bird is at x=i. 
 Let's denote the bird's height (y-coordinate) at that point by j. If he clicks, the bird moves to x=i+1 and y=j+1. Otherwise, the bird moves to x=i+1 and y=j−1.
 
 There is no ceiling and all the obstacles extend upwards from the bottom and not the other way around.
 
 For each valid i, the bird crosses the i-th obstacle successfully if the bird's 
 height at x=xi is strictly greater than hi.
 
 At any point before x=xN, the bird's height should remain non-negative, otherwise it will drown.

 If the bird crosses the N-th obstacle successfully, Chef wins the game.

Can you tell Chef if he can win the game (get the bird to cross all the obstacles) and the 
minimum number of clicks required to win in such a case?

Approach 

    hi -> modified height after subtracting H.
    For all pairs of (xi,hi) xi<=hi as it won't be possible to win otherwise

    the total no. of moves will depend on that most difficult obstacle
    
    Difficulty -> x+h (denotes the postion on x-axis were we land if we win)

    To pass this obstacle we take
        (x+h+2)/2 (+2 to ensure we don't touch the obstacle) 
*/

int main()
{

    fast_cin();
    lli t;
    cin >> t;
    while (t--)
    {
        lli n, H;
        cin >> n >> H;
        vector<pair<lli, lli>> pos(n);

        forn(i, n)
        {
            cin >> pos[i].first;
        }

        forn(i, n)
        {
            cin >> pos[i].second;
            pos[i].second -= H;
        }

        bool isPossible = true;
        lli moves = 0;

        for (auto [x, h] : pos)
        {
            if (x <= h)
            {
                isPossible = false;
                break;
            }

            moves = max(moves, (x + h + 2) / 2);
        }

        if (!isPossible)
            cout << "-1" << ln;
        else
            cout << moves << ln;
    }
    return 0;
}