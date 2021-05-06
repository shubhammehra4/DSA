#include <bits/stdc++.h>
using namespace std;
#define PRIME 7

class DoubleHash
{
    int N;
    int *hashTable;
    int curr_size;

public:
    bool isFull()
    {
        return (curr_size == N);
    }

    int hash1(int key)
    {
        return (key % N);
    }

    int hash2(int key)
    {
        return (PRIME - (key % PRIME));
    }

    DoubleHash(int N)
    {
        this->N = N;
        hashTable = new int[N];
        curr_size = 0;
        for (int i = 0; i < N; i++)
            hashTable[i] = -1;
    }

    void insertHash(int key)
    {
        if (isFull())
            return;

        int index = hash1(key);

        if (hashTable[index] != -1)
        {
            int index2 = hash2(key);
            int i = 1;
            while (1)
            {
                int newIndex = (index + i * index2) % N;

                if (hashTable[newIndex] == -1)
                {
                    hashTable[newIndex] = key;
                    break;
                }
                i++;
            }
        }
        else
            hashTable[index] = key;
        curr_size++;
    }

    int search(int key)
    {
        int index1 = hash1(key);
        int index2 = hash2(key);
        int i = 0;
        while (hashTable[(index1 + i * index2) % N] != key)
        {
            if (hashTable[(index1 + i * index2) % N] == -1)
            {
                cout << key << " does not exist" << endl;
                return -1;
            }
            i++;
        }
        cout << key << " found" << endl;
        return (index1 + i * index2) % N;
    }

    void deleteHash(int key)
    {
        int index = search(key);
        if (index != -1)
            hashTable[index] = -1, curr_size--;
    }

    void displayHash()
    {
        for (int i = 0; i < N; i++)
        {
            if (hashTable[i] != -1)
                cout << i << " --> " << hashTable[i] << endl;
            else
                cout << i << endl;
        }
    }
};

int main()
{
    int a[] = {19, 27, 36, 10, 64};
    int n = sizeof(a) / sizeof(a[0]);

    DoubleHash h(10);
    for (int i = 0; i < n; i++)
    {
        h.insertHash(a[i]);
    }
    h.search(36);
    h.search(100);
    h.deleteHash(10);
    h.displayHash();

    return 0;
}
