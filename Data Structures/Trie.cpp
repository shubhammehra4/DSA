#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

// **** Space Effecient Approach
class TrieNode
{
public:
    char content;                // the char present at the node
    bool isWordEnd;              // if the node is the end of a word
    int shared;                  // the number of the node shared ,convenient to implement delete(string key)
    vector<TrieNode *> children; // the children of the node

    TrieNode() : content(' '), isWordEnd(false), shared(0) {}
    TrieNode(char ch) : content(ch), isWordEnd(false), shared(0) {}

    TrieNode *findChild(char ch)
    {
        if (!children.empty())
        {
            for (auto child : children)
            {
                if (child->content == ch)
                    return child;
            }
        }
        return nullptr;
    }

    ~TrieNode()
    {
        for (auto child : children)
            delete child;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie() : root(new TrieNode()) {}

    /** Inserts a word into the trie */
    void insert(string s)
    {
        if (search(s))
            return;

        TrieNode *curr = root;
        for (auto ch : s)
        {
            TrieNode *child = curr->findChild(ch);
            if (child != nullptr)
                curr = child;
            else
            {
                TrieNode *newNode = new TrieNode(ch);
                curr->children.push_back(newNode);
                curr = newNode;
            }
            ++curr->shared;
        }
        curr->isWordEnd = true;
    }

    /** Returns true if the word is in the trie */
    bool search(string key)
    {
        TrieNode *curr = root;
        for (auto ch : key)
        {
            curr = curr->findChild(ch);
            if (curr == nullptr)
                return false;
        }
        return curr->isWordEnd == true;
    }

    /** Returns true if there is any word in the trie that starts with the given prefix */
    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (auto ch : prefix)
        {
            curr = curr->findChild(ch);
            if (curr == nullptr)
                return false;
        }
        return true;
    }
    ~Trie()
    {
        delete root;
    }
};

// Time Effecient

// class TrieNode
// {
// public:
//     TrieNode *children[26];
//     bool isWordEnd;

//     TrieNode()
//     {
//         isWordEnd = false;
//         for (int i = 0; i < 26; i++)
//             children[i] = nullptr;
//     }
// };

// class Trie
// {
// private:
//     TrieNode *root;

// public:
//     Trie() : root(new TrieNode()) {}

//     void insert(string key)
//     {
//         if (search(key))
//             return;

//         TrieNode *pCrawl = root;

//         for (auto ch : key)
//         {
//             int index = ch - 'a';
//             if (!pCrawl->children[index])
//                 pCrawl->children[index] = new TrieNode();

//             pCrawl = pCrawl->children[index];
//         }

//         pCrawl->isWordEnd = true;
//     }

//     bool search(string key)
//     {
//         TrieNode *pCrawl = root;

//         for (auto ch : key)
//         {
//             int index = ch - 'a';
//             if (!pCrawl->children[index])
//                 return false;

//             pCrawl = pCrawl->children[index];
//         }

//         return (pCrawl->isWordEnd);
//     }

//     bool startsWith(string prefix)
//     {
//         TrieNode *node = root;
//         for (char ch : prefix)
//         {
//             int index = ch - 'a';
//             if (!node->children[index])
//             {
//                 return false;
//             }
//             node = node->children[index];
//         }
//         return true;
//     }
// };