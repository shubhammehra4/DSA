#include <bits/stdc++.h>
using namespace std;
struct greaters
{
    bool operator()(const long &a, const long &b) const
    {
        return a > b;
    }
};

int main()
{
    // initializing vector;
    vector<int> vi = {4, 6, 7, 9, 11, 4};

    // using make_heap() to transform vector into
    // a max heap
    make_heap(vi.begin(), vi.end());

    //checking if heap using
    // front() function
    cout << "The maximum element of heap is : ";
    cout << vi.front() << endl;

    // initializing vector;
    vector<int> vi2 = {15, 6, 7, 9, 11, 45};

    // using make_heap() to transform vector into
    // a min heap
    make_heap(vi2.begin(), vi2.end(), greaters());

    // checking if heap using
    // front() function
    cout << "The minimum element of heap is : ";
    cout << vi2.front() << endl;

    return 0;
}