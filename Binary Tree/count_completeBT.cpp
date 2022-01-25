// Counting total node in a complete binary tree in less than O(N) time complexity

// TC - O(logN * logN)
// SC - O(logN)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int heightLeft(Node* root)
{
    int h = 0;
    while(root)
    {
        h++;
        root = root->left;
    }
    return h;
}

int heightRight(Node* root)
{
    int h = 0;
    while(root)
    {
        h++;
        root = root->right;
    }
    return h;
}

int countNodes(Node* root)
{
    if(!root)
        return 0;
    
    int count = 0;
    int l = heightLeft(root);
    int r = heightRight(root);

    if(l == r)
        return (2<<l)-1;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    return 0;
}