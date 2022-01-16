#include <bits/stdc++.h>
#define ll long long unsigned int
using namespace std;

int hash1(string s, int size)
{
    int hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash + ((int)s[i]));
        hash = hash % size;
    }
    return hash;
}

int hash2(string s, int size)
{
    int hash = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash = hash + pow(19, i) * s[i];
        hash = hash % size;
    }
    return hash % size;
}

int hash3(string s, int size)
{
    int hash = 7;
    for (int i = 0; i < s.size(); i++)
        hash = (hash * 31 + s[i]) % size;

    return hash % size;
}

int hash4(string s, int size)
{
    ll hash = 3;
    int p = 7;
    for (int i = 0; i < s.size(); i++)
    {
        hash += hash * 7 + s[0] * pow(p, i);
        hash = hash % size;
    }
    return (int)hash;
}

auto setKthBit = [](ll num, int k)
{
    return ((1 << k) | num);
};

auto getKthBit = [](ll num, int k)
{
    return (num & (1 << k)) == 0 ? 0 : 1;
};

bool lookup(ll bloomFilter, int size, string s)
{
    int a = getKthBit(bloomFilter, hash1(s, size));
    int b = getKthBit(bloomFilter, hash2(s, size));
    int c = getKthBit(bloomFilter, hash3(s, size));
    int d = getKthBit(bloomFilter, hash4(s, size));

    if (a && b && c && d)
        return true;
    else
        return false;
}

ll insert(ll bloomFilter, int size, string s)
{
    if (lookup(bloomFilter, size, s))
        return bloomFilter;

    bloomFilter = setKthBit(bloomFilter, hash1(s, size));
    bloomFilter = setKthBit(bloomFilter, hash2(s, size));
    bloomFilter = setKthBit(bloomFilter, hash3(s, size));
    bloomFilter = setKthBit(bloomFilter, hash4(s, size));

    return true;
}

int main()
{
    ll bloomFilter = 0b0;
    int size = 25;

    string strArr[18] = {
        "abound",
        "abounds",
        "abundance",
        "abundant",
        "bonny",
        "bonus",
        "bonuses",
        "coherent",
        "cohesive",
        "comfort",
        "gems",
        "generosity",
        "generous",
        "generously",
        "hate",
        "war",
        "humanity",
        "racism",
    };

    for (auto s : strArr)
        bloomFilter = insert(bloomFilter, size, s);

    return 0;
}
