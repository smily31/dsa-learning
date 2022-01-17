// Side View of Binary Tree
// Using recursive method as code is small and crisp
// Using preorder traversal
// TC - O(N)
// AS - O(H)   worst case when skew tree - O(N)
// the idea is : store the node value only when first time level is reached

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

// For Right View
// Reverse Preorder Traversal -> Root - Right - Left
void rightView(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    rightView(root->right, level + 1, ans);
    rightView(root->left, level + 1, ans);
}

// For Left View
// Preorder Traversal -> Root - Left - Right
void leftView(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    rightView(root->left, level + 1, ans);
    rightView(root->right, level + 1, ans);
}

// main function
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    vector<int> SV;
    // call right or left view function
    leftView(root, 0, SV);
    for (auto i : SV)
        cout << i << " ";

    return 0;
}