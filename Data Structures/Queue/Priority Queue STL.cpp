#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

void showpq (priority_queue <int> gq)
{
    priority_queue <int> g = gq;

    while (!g.empty() )
    {
        cout << '\t' << g.top();
        g.pop();
    }

    cout << '\n';
}

int main ()
{
    priority_queue <int> pq;
    pq.push (10);
    pq.push (30);
    pq.push (20);
    pq.push (5);
    pq.push (1);
    cout << "The priority queue pq is : ";
    showpq (pq);
    cout << "pq.size() : " << pq.size();
    cout << "\npq.top() : " << pq.top();
    cout << "\npq.pop() : ";
    pq.pop();
    showpq (pq);
    // Min - Heap
    priority_queue< iPair, vector <iPair> , greater<iPair> > minHeap;
    minHeap.push ({10, 2});
    minHeap.push ({30, 3});
    minHeap.push ({20, 5});
    minHeap.push ({5, 1});
    minHeap.push ({6, 8});
    cout << endl;
    cout << "The priority queue minHeap is : ";
    cout << "\nminHeap.top() : " << minHeap.top().first << " - " << minHeap.top().second;
    cout << "\nminHeap.size() : " << minHeap.size();
    cout << endl;

    while (!minHeap.empty() )
    {
        cout << minHeap.top().first << " - " << minHeap.top().second << endl;
        minHeap.pop();
    }

    // Max-Heap
    priority_queue <iPair> maxHeap;
    maxHeap.push ({10, 2});
    maxHeap.push ({30, 3});
    maxHeap.push ({20, 5});
    maxHeap.push ({5, 1});
    maxHeap.push ({6, 8});
    cout << endl;
    cout << "The priority queue maxHeap is : ";
    cout << "\nmaxHeap.top() : " << maxHeap.top().first << " - " << maxHeap.top().second;
    cout << "\nmaxHeap.size() : " << maxHeap.size();
    cout << endl;

    while (!maxHeap.empty() )
    {
        cout << maxHeap.top().first << " - " << maxHeap.top().second << endl;
        maxHeap.pop();
    }

    return 0;
}

