#include <bits/stdc++.h>
using namespace std;

// int bitmask(const string &word)
// {
//     bitset<26> mask;
//     for (auto c : word)
//         mask.set(c - 'a');

//     return (int)(mask.to_ulong());
// }
int bitmask(const string &word)
{
    int mask = 0;
    for (char letter : word)
        mask |= 1 << (letter - 'a');

    return mask;
}

// Approach: Hashing
vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
{
    unordered_map<int, int> wordCount;
    for (auto &word : words)
        wordCount[bitmask(word)]++;

    vector<int> result;

    for (auto &puzzle : puzzles)
    {
        int first = 1 << (puzzle[0] - 'a');
        int count = wordCount[first];

        // mask - a bitmask that represents a set of all possible subsets
        // ignore the first char as it's should always be present in any subset
        int mask = bitmask(puzzle.substr(1));

        // we can use a simple trick to find all possible subsets of mask
        // rather than using submask = submask-1 we do submask = (submask - 1) & mask
        // to ensure that the submask is a valid subset of mask
        for (int submask = mask; submask >= 0; submask = (submask - 1) & mask)
            count += wordCount[submask | first]; // add the first char as it is mandatory

        result.push_back(count);
    }

    return result;
}

// Approach: Trie
vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
{
    const int SIZE = 26;
    vector<vector<int>> trie = {vector<int>(SIZE)}; // we use vector to mimic the trie tree
    vector<int> count = {0};                        // the number of words ending at node i

    for (auto word : words)
    {
        sort(begin(word), end(word));
        word.erase(unique(begin(word), end(word)), end(word));

        if (word.size() <= 7)
        { // longer words are never valid
            // insert into trie
            int node = 0;
            for (char &letter : word)
            {
                int i = letter - 'a';
                if (trie[node][i] == 0)
                { // push empty node
                    trie.push_back(vector<int>(SIZE));
                    count.push_back(0);
                    trie[node][i] = trie.size() - 1;
                }
                node = trie[node][i];
            }
            count[node]++;
        }
    }
    // search for valid words
    function<int(int, bool, string &)> dfs = [&](int node, bool hasFirst, string &puzzle)
    {
        int total = hasFirst ? count[node] : 0;
        for (char &letter : puzzle)
        {
            int i = letter - 'a';
            if (trie[node][i])
            {
                total += dfs(trie[node][i], hasFirst || (letter == puzzle[0]), puzzle);
            }
        }
        return total;
    };
    vector<int> result;
    for (string &puzzle : puzzles)
    {
        result.push_back(dfs(0, false, puzzle));
    }
    return result;
}
