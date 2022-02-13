// Check the binary tree is balanced or not
// Balanced BT = for every node , abs { height(left bt) - height(right bt ) } <= 1
// Concept -> height of binary tree - recursive method

// TC - O(N)
// SC - O(height of tree) ~ O(N)

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

int balanced(Node *root)
{
    if (!root)
        return 0;

    int left = balanced(root->left);
    if (left == -1)
        return -1; // ek baar glt ans mil gya to whi return kr do
    int right = balanced(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1) // if our balanced case condition gets false return -1
        return -1;

    return 1 + max(left, right);
}

// main function
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->right = new Node(7);

    if (balanced(root) == -1)
        cout << "The given binary tree is not balanced \n";
    else
        cout << "The given binary tree is balanced \n";

    return 0;
}