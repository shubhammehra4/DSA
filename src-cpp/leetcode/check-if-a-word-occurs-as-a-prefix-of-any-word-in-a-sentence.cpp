#include <bits/stdc++.h>
using namespace std;

// pattern-search
int isPrefixOfWord(string sentence, string searchWord)
{
    string sent = " " + sentence;
    string word = " " + searchWord;
    int wordCnt = 0, j = 0;

    for (int i = 0; i < size(sent) && j < size(word); ++i)
    {
        wordCnt += sent[i] == ' ';

        if (sent[i] == word[j])
            ++j;
        else
            j = sent[i] == word[0] ? 1 : 0;
    }

    return j == size(word) ? wordCnt : -1;
}

// string-search stl
int isPrefixOfWord(string sentence, string searchWord)
{
    string sent = " " + sentence;
    string word = " " + searchWord;

    auto pos = sent.find(word);
    if (pos != string::npos)
        return count(begin(sent), begin(sent) + pos + 1, ' ');

    return -1;
}

// sliding-window
int isPrefixOfWord(string sentence, string searchWord)
{
    istringstream s(sentence);
    int n = size(searchWord);
    int wordCnt = 0;
    string word;

    while (!s.eof())
    {
        wordCnt++;
        getline(s, word, ' ');

        if (size(word) < n)
            continue;

        int i = 0, j = 0;
        for (; i < size(word) && j < n; i++, j++)
            if (word[i] != searchWord[j])
                break;

        if (j == n)
            return wordCnt;
    }

    return -1;
}