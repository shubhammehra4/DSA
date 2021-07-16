#include <bits/stdc++.h>
using namespace std;

int main()
{
	stack<int> s1;
	stack<int> s2;
	stack<char> s3;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s2.pop();
	s2.pop();
	s2.pop();
	s2.pop();
	s3.push('c');
	s3.push('h');

	s1.pop();
	s1.emplace(54);

	s1.swap(s2);
	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	return 0;
}
