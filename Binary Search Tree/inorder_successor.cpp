// Leetcode Premium Question

// Find the inorder successor of following BST
// i.e. according to inorder traversal find the node which is just greater than the given node

// Method 1 :
// store inorder traversal in vector then find the next greater element
// TC - O(n)+O(log n)
// SC - O(1)

// Method 2 :
// during inorder traversal, the first node which is greater than given node is encounter
// then return that node
// TC - O(n)
// SC - O(1)

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

// Method 3 :
// use the basic concept of bst and whenever the node is less than the given node value go right 
// and when bigger element encounters then go left in search of nearest bigger element and update the successor variable
// whenever you reach null return the successor
// TC - O(h)
// SC - O(1)
Node* inorder_successor(Node* root, Node* p)
{
    Node* successor = NULL;
    while(root != NULL)
    {
        if(p->data >= root->data)
            root = root->right;
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return successor;
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

    Node* successor = inorder_successor(root, root);
    cout<<"The inorder successor of given node is "<<successor->data<<'\n';

    return 0;
}