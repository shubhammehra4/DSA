#include <bits/stdc++.h>
using namespace std;

void swap (int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MaxHeap {
        int *harr;
        int capacity;
        int heap_size;
    public:
        MaxHeap (int capacity);

        void MaxHeapify (int i);
        int parent (int i) { return (i - 1) / 2; }
        int left (int i) { return (2 * i + 1); }
        int right (int i) { return (2 * i + 2); }

        int popMax();
        void increaseKey (int i, int val);
        int getMax() {return harr[0];}

        void deleteKey (int i);
        void insertKey (int k);
};

MaxHeap::MaxHeap (int cap)
{
    heap_size = 0;
    int capacity = cap;
    harr = new int[cap];
}

int MaxHeap::popMax()
{
    if (heap_size <= 0)
        return INT_MIN;

    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MaxHeapify (0);
    return root;
}

void MaxHeap::MaxHeapify (int i)
{
    int l = left (i);
    int r = right (i);
    int greatest = i;

    if (l < heap_size && harr[l] > harr[i])
        greatest = l;

    if (r < heap_size && harr[r] > harr[i])
        greatest = r;

    if (greatest != i)
    {
        swap (&harr[i], &harr[greatest]);
        MaxHeapify (greatest);
    }
}

void MaxHeap::increaseKey (int i, int new_val)
{
    harr[i] = new_val;

    while (i != 0 && harr[parent (i)] < harr[i])
    {
        swap (&harr[i], &harr[parent (i)]);
        i = parent (i);
    }
}

void MaxHeap::deleteKey (int i)
{
    increaseKey (i, INT_MAX);
    popMax();
}

void MaxHeap::insertKey (int key)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not Insert Key\n";
        return;
    }

    harr[heap_size++] = key;
    int i = heap_size - 1;

    while (i != 0 && harr[parent (i)] < harr[i])
    {
        swap (&harr[i], &harr[parent (i)]);
        i = parent (i);
    }
}

int main()
{
    MaxHeap h (11);
    h.insertKey (3);
    h.insertKey (4);
    h.insertKey (5);
    h.insertKey (6);
    h.insertKey (8);
    cout << h.getMax();
    return 0;
}