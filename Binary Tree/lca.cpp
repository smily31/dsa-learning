// Lowest Common Ancestor

// Brute-Force Approach
// find root to node path for both given node
// and then check for similar path value until it gets mismatched
// so the last matched node value is the answer
// TC - O(N) ASC - O(2N)

// Optimal Approach
// recursive traversal and whenever we find node->value equals one of given node we will return that Node else return NULL
// and if from left subtree we get node and from right we get NUll
// then we will return node
// TC - O(N)
// ASC - O(N)

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

Node *lca(Node *root, Node *p, Node *q)
{
    if (root == NULL || root == p || root == q)
        return root;

    Node *left = lca(root->left, p, q);
    Node *right = lca(root->right, p, q);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}

// main function
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
    Node *ans = lca(root, root->right->left, root->right->right->right);
    cout << " Lowest common ancestor of " << root->right->left->data << " and " << root->right->right->right->data << " is " << ans->data << endl;
    return 0;
}