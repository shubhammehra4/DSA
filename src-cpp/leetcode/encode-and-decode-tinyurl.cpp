#include <bits/stdc++.h>
using namespace std;

// @ref - Fowler–Noll–Vo hash function
uint64_t hash_function(const string &str)
{
    uint64_t hash = 0x811c9dc5;
    uint64_t prime = 0x1000193;

    for (int i = 0; i < str.size(); ++i)
    {
        uint8_t value = str[i];
        hash = hash ^ value;
        hash *= prime;
    }

    return hash;
}

unordered_map<string, string> shortToLong;

// Encodes a URL to a shortened URL.
string encode(string longUrl)
{
    auto encodedUrl = "http://tinyurl.com/" + to_string(hash_function(longUrl));
    shortToLong[encodedUrl] = longUrl;
    return encodedUrl;
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl)
{
    return shortToLong[shortUrl];
}