#include <iostream> 
#include <unordered_map> 
using namespace std; 

int main() 
{ 
    unordered_map<string, int> umap; 

    // inserting values by using [] operator 
    umap["GeeksforGeeks"] = 10; 
    umap["Practice"] = 20; 
    umap["Contribute"] = 30; 

    // Traversing an unordered map 
    for (auto x : umap) 
    cout << x.first << " " << x.second << endl; 

} 
