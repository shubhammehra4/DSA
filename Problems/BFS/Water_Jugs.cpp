#include <bits/stdc++.h>
using namespace std;
/*
	The following operations could be done to a jug:
    1. Empty jug1 into jug2 (But there might be some left in jug1)
    2. Empty jug2 into jug1 (But there might be some left in jug2)
    3. Fill jug1 completely
    4. Fill jug2 completely
    5. Empty jug1 
    6. Empty jug2
*/

bool canMeasureWater(int jug1, int jug2, int target)
{
    if (jug1 + jug2 < target)
        return false;
    if (jug1 + jug2 == target)
        return true;
    //cannot measure odd capacity using even capacity jugs
    if (jug1 % 2 == 0 && jug2 % 2 == 0 && target % 2 != 0)
        return false;

    set<pair<int, int>> st;
    queue<pair<int, int>> q;
    st.insert({0, 0});
    q.push({0, 0});

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        int x = top.first, y = top.second;
        if (x + y == target)
            return true;

        int X, Y;
        //1
        X = x - min(x, jug2 - y);
        Y = y + min(x, jug2 - y);
        if (st.count({X, Y}) == 0)
        {
            st.insert({X, Y});
            q.push({X, Y});
        }
        //2
        Y = y - min(y, jug1 - x);
        X = x + min(y, jug1 - x);
        if (st.count({X, Y}) == 0)
        {
            st.insert({X, Y});
            q.push({X, Y});
        }
        //3
        X = jug1;
        Y = y;
        if (st.count({X, Y}) == 0)
        {
            st.insert({X, Y});
            q.push({X, Y});
        }
        //4
        X = x;
        Y = jug2;
        if (st.count({X, Y}) == 0)
        {
            st.insert({X, Y});
            q.push({X, Y});
        }
        //5
        X = 0;
        Y = y;
        if (st.count({X, Y}) == 0)
        {
            st.insert({X, Y});
            q.push({X, Y});
        }
        //6
        X = x;
        Y = 0;
        if (st.count({X, Y}) == 0)
        {
            st.insert({X, Y});
            q.push({X, Y});
        }
    }

    return false;
}

// Mathematical Soln
bool canMeasureWaterFast(int x, int y, int z)
{
    return z == 0 || (z - x <= y && z % std::__gcd(x, y) == 0);
}

int main()
{
    return 0;
}