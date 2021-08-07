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

int length(ListNode *node)
{
    int l = 0;
    while (node)
    {
        node = node->next;
        l++;
    }
    return l;
}

ListNode *reverse(ListNode *list)
{
    ListNode *curr = list, *prev = NULL, *next_node = NULL;
    while (curr)
    {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    return prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int len1 = length(l1), len2 = length(l2);
    if (len1 < len2)
        swap(l1, l2);

    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode *li1 = l1;
    int carry = 0, sum;
    ListNode *before = li1;
    while (li1 && l2)
    {
        sum = li1->val + l2->val + carry;
        li1->val = (sum % 10);
        carry = sum / 10;
        before = li1;
        li1 = li1->next;
        l2 = l2->next;
    }

    while (li1)
    {
        sum = (li1->val + carry);
        li1->val = sum % 10;
        carry = sum / 10;
        before = li1;
        li1 = li1->next;
    }

    if (carry)
    {
        ListNode *last = new ListNode(carry % 10);
        carry /= 10;
        before->next = last;
        before = before->next;
    }

    l1 = reverse(l1);
    return l1;
}

// Using Stack
ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2)
{
    stack<int> st1, st2;
    ListNode *ans = new ListNode(0);
    while (l1)
    {
        st1.push(l1->val);
        l1 = l1->next;
    }
    while (l2)
    {
        st2.push(l2->val);
        l2 = l2->next;
    }
    int sum = 0;
    while (!st1.empty() || !st2.empty())
    {
        if (!st1.empty())
        {
            sum += st1.top();
            st1.pop();
        }
        if (!st2.empty())
        {
            sum += st2.top();
            st2.pop();
        }
        ans->val = sum % 10;
        sum /= 10;
        ListNode *head = new ListNode(sum);
        head->next = ans;
        ans = head;
    }
    return ans->val == 0 ? ans->next : ans;
}

int main()
{

    return 0;
}