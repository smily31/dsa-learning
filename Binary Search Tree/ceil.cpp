// Find the ceil of given number(node) in binary search tree
// TC - O(logN)   - height of binary tree

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

// Approach -> if key is existed then answer is simply that otherwise
// if key is greater then node->data then go to right
// else if key is less then node->data then update ceil and go to left to find nearest bigger value

int ceil(Node* root, int val)
{
    int ceil = -1;
    while(root)
    {
        if(root->data == val)
        {
            ceil = root->data;
            return ceil;
        }
        if(val > root->data)
            root = root->right;
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
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

    cout<<"Ceil of given number is "<<ceil(root, 2);
    return 0;
}