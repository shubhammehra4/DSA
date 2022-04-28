#include <bits/stdc++.h>
using namespace std;

// chain-hashing
struct Node
{
public:
    int key, val;
    Node *next;
    Node(int k, int v, Node *_next)
    {
        key = k;
        val = v;
        next = _next;
    }
};
class MyHashMap
{
    const static int size = 19997;         // prime
    const static int multiplier = 1e7 + 7; // prime

    vector<Node *> data;

    int hash(int key)
    {
        return (int)((long)key * multiplier % size);
    }

public:
    MyHashMap()
    {
        data.resize(size, nullptr);
    }

    void put(int key, int val)
    {
        remove(key);
        int h = hash(key);
        auto node = new Node(key, val, data[h]); // new head
        data[h] = node;
    }

    int get(int key)
    {
        int h = hash(key);
        auto node = data[h];

        while (node != nullptr)
        {
            if (node->key == key)
                return node->val;

            node = node->next;
        }

        return -1;
    }

    void remove(int key)
    {
        int h = hash(key);
        auto node = data[h];

        if (node == nullptr)
            return;

        if (node->key == key)
        {
            auto delNode = data[h];
            data[h] = node->next;
            delete (delNode);
        }
        else
        {
            while (node != nullptr && node->next != nullptr)
            {
                if (node->next->key == key)
                {
                    auto delNode = node->next;
                    node->next = node->next->next;
                    delete (delNode);
                }
                node = node->next;
            }
        }
    }
};

// chain-hashing alter
class MyHashMap
{
    vector<list<pair<int, int>>> data;
    int size = 19997;

    int hash(int key)
    {
        return key % size;
    }

public:
    MyHashMap()
    {
        data.resize(size);
    }

    void put(int key, int value)
    {
        int h = hash(key);
        auto &list = data[h];

        // check if key already exists
        for (auto &i : list)
        {
            if (i.first == key)
            {
                i.second = value;
                return;
            }
        }

        list.push_back({key, value});
    }

    int get(int key)
    {
        int h = hash(key);
        auto &list = data[h];

        for (auto i : list)
            if (i.first == key)
                return i.second;

        return -1;
    }

    void remove(int key)
    {
        int h = hash(key);
        auto &list = data[h];

        for (auto i : list)
        {
            if (i.first == key)
            {
                list.remove(i);
                return;
            }
        }
    }
};

// brute-force
class MyHashMap
{
    vector<int> m;

public:
    MyHashMap()
    {
        m.resize(1000000, -1);
    }

    void put(int key, int value)
    {
        m[key] = value;
    }

    int get(int key)
    {
        return m[key];
    }

    void remove(int key)
    {
        m[key] = -1;
    }
};