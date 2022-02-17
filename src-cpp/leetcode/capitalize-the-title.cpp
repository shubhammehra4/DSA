#include <bits/stdc++.h>
using namespace std;

string capitalizeTitle(string title)
{
    int end = 0, n = title.size();

    while (end < n)
    {
        int start = end;

        while (end < n and title[end] != ' ')
            title[end] = tolower(title[end]), end++;

        if (end - start > 2)
            title[start] = toupper(title[start]);

        end++;
    }

    return title;
}

// Functional
// vector<string> split(string s)
// {
//     string acc = "";
//     vector<string> res;

//     for (auto i : s)
//     {
//         if (i == ' ')
//         {
//             res.push_back(acc);
//             acc = "";
//         }
//         else
//             acc += i;
//     }

//     if (acc != "")
//         res.push_back(acc);

//     return res;
// }

// string capitalizeTitleF(string title)
// {
//     vector<string> str = split(title);

//     for (auto &s : str)
//     {
//         if (s.size() < 3)
//             transform(s.begin(), s.end(), s.begin(), ::tolower);
//         else
//         {
//             s[0] = toupper(s[0]);
//             transform(s.begin() + 1, s.end(), s.begin() + 1, ::tolower);
//         }
//     }

//     return reduce(begin(str), end(str), std::string(""), [](auto a, auto b)
//                   { return a != "" ? a + " " + b : b; });
// }