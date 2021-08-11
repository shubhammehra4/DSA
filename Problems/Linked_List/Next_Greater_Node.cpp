#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nextLargerNodes(ListNode *h)
{
    vector<int> res, stack;
    for (auto p = h; p != nullptr; p = p->next)
        res.push_back(p->val);

    for (int i = res.size() - 1; i >= 0; --i)
    {
        auto val = res[i];
        //remove all smaller than current
        while (!stack.empty() && stack.back() <= val)
            stack.pop_back();

        res[i] = stack.empty() ? 0 : stack.back();
        stack.push_back(val);
    }

    return res;
}

int main()
{

    return 0;
}