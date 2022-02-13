// Print the Length of the Diameter of a Binary Tree
// Diameter - longest path between any two node and path does not need to pass through root

// TC - O(N)
// SC - O(N)

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int diameter(Node *root, int &d)
{
    if (!root)
        return 0;

    int left = diameter(root->left, d);
    int right = diameter(root->right, d);

    d = max(d, left + right);

    return 1 + max(left, right);
}

// main function
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->left->left = new Node(22);

    int d = 0;
    diameter(root, d);
    cout << "Diameter of the given binary tree is " << d;
    return 0;
}