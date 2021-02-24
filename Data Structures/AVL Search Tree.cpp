#include <bits/stdc++.h>
using namespace std;
#define COUNT 10

class AVLBST {
    private:
        int data;
        AVLBST *left, *right;
        int hieght;
    public:
        AVLBST() : data (0), left (NULL), right (NULL) {};
        AVLBST (int);
        AVLBST* Insert (AVLBST *, int);
        int NodeHeight (AVLBST *);
        int BalanceFactor (AVLBST *);
        AVLBST* LLRotation (AVLBST *);
        AVLBST* LRRotation (AVLBST *);
        AVLBST* RRRotation (AVLBST *);
        AVLBST* RLRotation (AVLBST *);
        AVLBST* Delete (AVLBST *, int);
        AVLBST* InPre (AVLBST *);
        AVLBST* InSucc (AVLBST *);
        void Inorder (AVLBST *);
        void Preorder (AVLBST *);
        void print2DUtil (AVLBST *, int );
        void print2D (AVLBST *);
        // int RecSearch (AVLBST*, int);
        // int IterSearch (AVLBST*, int);
}*root = NULL;

AVLBST :: AVLBST (int value)
{
    data = value;
    left = right = NULL;
    hieght = 1;
}

int AVLBST :: NodeHeight (AVLBST *p)
{
    int l, r;

    if (p == NULL)
        return 0;

    l = NodeHeight ( p->left );
    r = NodeHeight ( p->right );
    return l > r ? l + 1 : r + 1;
}

int AVLBST :: BalanceFactor (AVLBST *p)
{
    int l, r;

    if (p == NULL)
        return 0;

    l = NodeHeight ( p->left );
    r = NodeHeight ( p->right );
    return l - r;
}

AVLBST* AVLBST :: LLRotation (AVLBST* p)
{
    AVLBST *pl = p->left;
    AVLBST *plr = pl->right;
    pl->right = p;
    p->left = plr;
    p->hieght = NodeHeight (p);
    pl->hieght = NodeHeight (pl);

    if (p == root)
        root = pl;

    cout << "LL\n";
    return pl;
}

AVLBST* AVLBST :: RRRotation (AVLBST* p)
{
    AVLBST *pr = p->right;
    AVLBST *prl = pr->left;
    pr->left = p;
    p->right = prl;
    p->hieght = NodeHeight (p);
    pr->hieght = NodeHeight (pr);

    if (p == root)
        root = pr;

    cout << "RR\n";
    return pr;
}


AVLBST* AVLBST :: LRRotation (AVLBST* p)
{
    AVLBST *pl = p->left;
    AVLBST *plr = pl->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;
    p->hieght = NodeHeight (p);
    plr->hieght = NodeHeight (plr);
    pl->hieght = NodeHeight (pl);

    if (p == root)
        root = plr;

    cout << "LR\n";
    return plr;
}

AVLBST* AVLBST :: RLRotation (AVLBST* p)
{
    AVLBST *pr = p->right;
    AVLBST *prl = pr->left;
    pr->left = prl->right;
    p->right = prl->left;
    prl->right = pr;
    prl->left = p;
    p->hieght = NodeHeight (p);
    prl->hieght = NodeHeight (prl);
    pr->hieght = NodeHeight (pr);

    if (p == root)
        root = prl;

    cout << "RL\n";
    return prl;
}

AVLBST* AVLBST :: Insert (AVLBST *p, int value)
{
    if (!p)
        return new AVLBST (value);

    if (value > p->data)
        p->right = Insert (p->right, value);
    else
        p->left = Insert (p->left, value);

    p->hieght = NodeHeight (p);

    if (BalanceFactor (p) == 2 && BalanceFactor (p->left) == 1)     //LL
        return LLRotation (p);
    else if (BalanceFactor (p) == 2 && BalanceFactor (p->left) == -1) //LR
        return LRRotation (p);
    else if (BalanceFactor (p) == -2 && BalanceFactor (p->right) == -1) //RR
        return RRRotation (p);
    else if (BalanceFactor (p) == -2 && BalanceFactor (p->right) == 1) //Rl
        return RLRotation (p);

    return p;
}

AVLBST* AVLBST :: InPre (AVLBST *p)
{
    while (p && p->right != NULL)
        p = p->right;

    return p;
}

AVLBST* AVLBST :: InSucc (AVLBST *p)
{
    while (p && p->left != NULL)
        p = p->left;

    return p;
}

AVLBST* AVLBST :: Delete (AVLBST *p, int key)
{
    AVLBST *q;

    if (p == NULL)
        return NULL;

    if (p->left == NULL && p->right == NULL)
    {
        free (p);
        return NULL;
    }

    if (key < p->data)
        p->left = Delete (p->left, key);
    else if (key > p->data)
        p->right = Delete (p->right, key);
    else
    {
        if (NodeHeight (p->left) > NodeHeight (p->right) )
        {
            q = InPre (p->left); //Rightmost child of left sub-tree
            p->data = q->data;
            p->left = Delete (p->left, q->data);
        }

        else
        {
            q = InSucc (p->right); //leftmost child of right sub-tree
            p->data = q->data;
            p->right = Delete (p->right, q->data);
        }
    }

    p->hieght = NodeHeight (p);

    if (BalanceFactor (p) == 2 && (BalanceFactor (p->left) == 1 || BalanceFactor (p->left) == 0) )  //LL
        return LLRotation (p);
    else if (BalanceFactor (p) == 2 && BalanceFactor (p->left) == -1) //LR
        return LRRotation (p);
    else if (BalanceFactor (p) == -2 && (BalanceFactor (p->right) == -1 || BalanceFactor (p->right) == 0) ) //RR
        return RRRotation (p);
    else if (BalanceFactor (p) == -2 && BalanceFactor (p->right) == 1) //Rl
        return RLRotation (p);

    return p;
}

void AVLBST :: Inorder (AVLBST *p)
{
    if (!p)
        return;

    Inorder (p->left);
    cout << p->data << " ";
    Inorder (p->right);
}

void AVLBST :: Preorder (AVLBST *p)
{
    if (!p)
        return;

    cout << p->data << " ";
    Inorder (p->left);
    Inorder (p->right);
}

void AVLBST :: print2DUtil (AVLBST *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;
    print2DUtil (root->right, space);
    cout << endl;

    for (int i = COUNT; i < space; i++)
        cout << " ";

    cout << root->data << "\n";
    print2DUtil (root->left, space);
}

void AVLBST :: print2D (AVLBST *root)
{
    print2DUtil (root, 0);
}

int main()
{
    AVLBST b;
    root = b.Insert (root, 10);
    b.Insert (root, 20);
    b.Insert (root, 30);
    b.Insert (root, 25);
    b.Insert (root, 28);
    b.Insert (root, 27);
    b.Insert (root, 5);
    // b.Delete (root, 5);
    // b.Preorder (root);
    // cout << "\n";
    // b.Inorder (root);
    // cout << root->data;
    b.print2D (root);
    return 0;
}