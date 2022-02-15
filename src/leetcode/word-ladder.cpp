#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    if (find(begin(wordList), end(wordList), endWord) == end(wordList))
        return 0;

    unordered_set<string> wordSet(begin(wordList), end(wordList));

    queue<string> q;
    q.push(beginWord);

    int level = 0;

    while (!q.empty())
    {
        level++;
        int levelSize = q.size();

        while (levelSize--)
        {
            auto word = q.front();
            q.pop();

            for (int i = 0; i < word.size(); i++)
            {
                auto temp = word;

                // checking out each possibility of alphabet
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (word[i] == c)
                        continue;

                    temp[i] = c;

                    if (temp.compare(endWord) == 0)
                        return level + 1;

                    if (wordSet.find(temp) != wordSet.end()) // if present in word set
                    {
                        q.push(temp);
                        wordSet.erase(temp);
                    }
                }
            }
        }
    }

    return 0;
}