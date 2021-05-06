#include <bits/stdc++.h>
using namespace std;

class Hash
{
    int BUCKET;
    list<int> *hash_table;

public:
    Hash(int V);

    void insertItem(int x);
    void deleteItem(int key);
    bool searchItem(int key);
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }
    void displayHash();
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    hash_table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    hash_table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    int index = hashFunction(key);

    list<int>::iterator i;
    for (i = hash_table[index].begin(); i != hash_table[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    if (i != hash_table[index].end())
        hash_table[index].erase(i);
}

bool Hash::searchItem(int key)
{
    // can be improved if sets are used and BinarySearch is implemented
    int index = hashFunction(key);
    list<int>::iterator i;
    for (i = hash_table[index].begin(); i != hash_table[index].end(); i++)
    {
        if (*i == key)
            return true;
    }

    return false;
}

void Hash::displayHash()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i;
        for (auto x : hash_table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a) / sizeof(a[0]);

    Hash h(7);
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    h.deleteItem(12);
    h.displayHash();

    return 0;
}
