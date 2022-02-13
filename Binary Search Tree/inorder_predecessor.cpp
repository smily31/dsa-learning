// Find the inorder predecessor of following BST
// i.e. according to inorder traversal find the node which is just less than the given node

// Method 1 :
// store inorder traversal in vector then find the previous smaller element
// TC - O(n)+O(log n)
// SC - O(1)

// Method 2 :
// during inorder traversal store the previous node value in a variable and return that value
// when the current node becomes equal to given node
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
// use the basic concept of bst and whenever the node is greater than the given node value go left
// and when lesser element encounters then go right in search of nearest less element and update the predecessor variable
// whenever you reach null return the predecessor
// TC - O(h)
// SC - O(1)
Node *inorder_predecessor(Node *root, Node *p)
{
    Node *predecessor = NULL;
    while (root != NULL)
    {
        if (p->data <= root->data)
            root = root->left;
        else
        {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
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

    Node *predecessor = inorder_predecessor(root, root);
    cout << "The inorder predecessor of given node is " << predecessor->data << '\n';

    return 0;
}