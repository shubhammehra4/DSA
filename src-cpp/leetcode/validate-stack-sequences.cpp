#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    int n = pushed.size();
    stack<int> st;
    int idx = 0;

    for (auto num : pushed)
    {
        st.push(num);

        while (!st.empty() && st.top() == popped[idx])
        {
            st.pop();
            idx++;
        }
    }

    return st.empty();
}