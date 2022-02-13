// Find the Least Common Ancestor of given two nodes in Binary Search Tree
// TC - O(H)
// SC - O(1)   or ASC - O(H)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    // constructor
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* lca(Node* root, Node* p, Node* q)
{
    if(root == NULL)
        return NULL;
    int cur = root->data;
    if(p->data < cur && q->data < cur)
        return lca(root->left, p, q);
    if(p->data > cur && q->data > cur)
        return lca(root->right, p, q);
    return root;
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->left->right = new Node(7);
    root->left->left = new Node(2);
    root->left->left->right = new Node(3);
    root->right = new Node(9);
    root->right->right = new Node(10);
    root->right->left = new Node(5);

    Node* l = lca(root, root->left->left, root->right->right);
    cout<<"LCA of given nodes is "<<l->data<<'\n';

    return 0;
}