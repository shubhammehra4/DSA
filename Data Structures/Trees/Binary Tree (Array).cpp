#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	Node* left, * right; 
}; 

Node* newNode(int data) 
{ 
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

Node* insertLevelOrder(int arr[], Node* root, int i, int n) 
{
	if (i < n) 
	{ 
		Node* temp = newNode(arr[i]); 
		root = temp; 

		// insert left child 
		root->left = insertLevelOrder(arr, 
				root->left, 2 * i + 1, n); 

		// insert right child 
		root->right = insertLevelOrder(arr, 
				root->right, 2 * i + 2, n); 
	} 
	return root; 
} 

void inOrder(Node* root) 
{ 
	if (root != NULL) 
	{ 
		inOrder(root->left); 
		cout << root->data <<" "; 
		inOrder(root->right); 
	} 
}

void preOrder(Node *root)
{
    if(root!=NULL)
    {
        cout << root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
} 

void postOrder(Node *root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data<<" ";
    }
}

int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node* root = insertLevelOrder(arr, root, 0, n); 
    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    
    return 0;
} 
