// Search a value/node in Binary Search Tree
// TC - O(log N)
// SC - O(1)

// if value is less than node then go left else go right -> binary search concept

#include<bits/stdc++.h>
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

Node* search(Node *root, int val)
{
    while(root != NULL && root->data != val)
        root = val < root->data ? root->left : root->right;
    return root;
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left = new Node(2);
    root->left->left->right = new Node(3);
    root->right = new Node(9);
    root->right->right = new Node(10);
    root->right->left = new Node(8);

    Node *found = search(root, 7);
    if(found == NULL)
        cout<<"Not found\n";
    else
        cout<<found->data<<'\n';

    return 0;
}