#include <bits/stdc++.h>

using namespace std; 

int main() 
{ 
	vector<int> g1; 

	for (int i = 1; i <= 5; i++) 
		g1.push_back(i); 

	cout << "Output of begin and end: "; 
	for (auto i = g1.begin(); i != g1.end(); ++i) 
		cout << *i << " "; 

	cout << "\nOutput of cbegin and cend: "; 
	for (auto i = g1.cbegin(); i != g1.cend(); ++i) 
		cout << *i << " "; 

	cout << "\nOutput of rbegin and rend: "; 
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir) 
		cout << *ir << " "; 

	cout << "\nOutput of crbegin and crend : "; 
	for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir) 
		cout << *ir << " "; 

	cout << "Size : " << g1.size(); 
    cout << "\nCapacity : " << g1.capacity(); 
    cout << "\nMax_Size : " << g1.max_size(); 

	// resizes the vector size to 4 
    g1.resize(4);
    // Shrinks to the size 
    // till which elements are 
    // destroys the elements after 5 
    v.shrink_to_fit();
    
    v.insert(v.begin(), 5); 
    
    // inserts at the beginning 
    v.emplace(v.begin(), 5); 
    
    // Inserts 20 at the end 
    v.emplace_back(20);
    
    if (g1.empty() == false) 
        cout << "\nVector is not empty"; 
    else
        cout << "\nVector is empty"; 
	return 0; 
} 

