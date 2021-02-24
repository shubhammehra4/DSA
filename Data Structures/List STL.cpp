#include<bits/stdc++.h>
using namespace std;

void showlist(list <int> g)
{
    list <int> :: iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

int main()
{
    list<int> a, b;
    list<char>c;
    for (int i = 0; i < 10; i++)
    {
        a.push_back(i * i);
        b.push_front(i * 2);
    }
    cout << "List 1 looks like: "
         showlist(a);
    cout << "List 2 looks like: "
         showlist(b);
    cout << "front of a is " << a.front() << endl;
    cout << "back of a is " << a.back() << endl;
    cout << "\na.pop_front() : ";
    a.pop_front();
    showlist(a);
    b.sort();
    return 0;
}
