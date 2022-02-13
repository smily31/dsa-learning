// Check the Binary Tree is Symmetrical or not
//    Approach
// From root->left take it as root for left tree and apply preorder
// Then take root->right as root of right tree and apply reverse preorder
// Because in mirror left becomes right and vice-versa
// so applying traversal at same time and then checking it value we got to know that tree is symmetrical or not
// TC - O(N)
// SC - O(N)

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

bool symmetrical(Node *leftRoot, Node *rightRoot)
{
    if (leftRoot == NULL || rightRoot == NULL)
        return leftRoot == rightRoot;
    return (leftRoot->data == rightRoot->data) && symmetrical(leftRoot->left, rightRoot->right) && symmetrical(leftRoot->right, rightRoot->left);
}

// main function
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->right = new Node(4);
    root->left->left = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    if (symmetrical(root->left, root->right))
        cout << "The tree is symmetrical \n";
    else
        cout << "The tree is not symmetrical \n";

    return 0;
}