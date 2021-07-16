#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

public:
    MinHeap(int capacity);

    void insertKey(int k);
    void updateKey(int i, int new_val);
    void MinHeapify(int);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    int popMin();
    int getMin() { return harr[0]; }
    void deleteKey(int i);
};

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not Insert Key\n";
        return;
    }

    harr[heap_size++] = k;
    int i = heap_size - 1;

    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::updateKey(int i, int new_val)
{
    harr[i] = new_val;

    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::popMin()
{
    if (heap_size <= 0)
        return INT_MAX;

    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return root;
}

void MinHeap::deleteKey(int i)
{
    updateKey(i, INT_MIN); // replace it with -inf
    popMin();              // delete -inf
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i])
        smallest = l;

    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.popMin() << " ";
    cout << h.getMin() << " ";
    h.updateKey(2, 1);
    cout << h.getMin();
    return 0;
}
