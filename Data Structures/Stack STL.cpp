#include <bits/stdc++.h>
#define ll long long
#define db double 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define fin(i,n) for(auto &i : n)
#define pb push_back
#define pob pop_back
#define F first
#define S second
#define MOD 1000000007
#define endl "\n"
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main()
{ 
	quick;
	stack<int> s1;
	stack<int> s2;
	stack<char> s3;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);	
	s2.pop(9);
	s2.pop(8);
	s2.pop(7);
	s2.pop(6);
	s3.('c');
	s3.('h');
	
	s1.pop();
	s1.emplace(54);
	
	s1.swap(s2);
	while (!s1.empty()) { 
        cout<<s1.top()<<" "; 
        s1.pop(); 
    }
	return 0;
}
