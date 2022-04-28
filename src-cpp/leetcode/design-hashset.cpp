#include <bits/stdc++.h>
using namespace std;

class MyHashSet
{
private:
    int prime;
    vector<list<int>> table;

    int hash(int key)
    {
        return key % prime;
    }

    list<int>::iterator search(int key)
    {
        int h = hash(key);
        return find(begin(table[h]), end(table[h]), key);
    }

public:
    MyHashSet() : prime(10007), table(prime) {}

    void add(int key)
    {
        int h = hash(key);
        if (!contains(key))
            table[h].push_back(key);
    }

    void remove(int key)
    {
        int h = hash(key);
        auto it = search(key);
        if (it != end(table[h]))
            table[h].erase(it);
    }

    bool contains(int key)
    {
        int h = hash(key);
        return search(key) != end(table[h]);
    }
};