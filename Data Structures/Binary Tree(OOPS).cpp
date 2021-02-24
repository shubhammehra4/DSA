#include <bits/stdc++.h>
using namespace std;

class BT
{
    int data;
    BT *left, *right;
public:
    BT() : data(0), left(NULL), right(NULL){};
    BT(int);
    BT* Insert(BT *,int);
    
};
BT :: BT(int value)
{
    int data=value;
    left=right=NULL;
}

BT* BT::Insert(BT* root,int value)
{
    if(root==NULL)
    {
        return new BT(value);
    }
    if(value>root->data)
        root->right=Insert(root->right,value);
    else
        root->left=Insert(root->left,value);
        
    return root;        
}