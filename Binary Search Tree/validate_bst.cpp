// Given a binary tree , you have to validate if the tree is binary search tree or not
// TC - O(N)
// ASC - (N)

// if have to check the node if it lies in valid range or not according bst rule

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

bool validate_bst(Node *root, long minVal, long maxVal)
{
    if (root == NULL)
        return true;
    if (root->data >= maxVal || root->data <= minVal)
        return false;
    return validate_bst(root->left, minVal, root->data) && validate_bst(root->right, root->data, maxVal);
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

    if (validate_bst(root, LONG_MIN, LONG_MAX))
        cout << "It is valid Binary Search Tree\n";
    else
        cout << "It is not valid Binary Search Tree\n";

    return 0;
}