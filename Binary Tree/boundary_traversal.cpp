// Boundary Traversal   - Also leetcode premium question
// anti-clockwise direction

// Algo-> print in manners like
// 1* left boundary excluding leaf nodes
// 2* all leaf nodes using inorder or preoder traversal
// 3* right boundary in reverse order excluding leaf nodes

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

// for checking the node is leaf node or not
bool isLeaf(Node *root)
{
    if (!root->left && !root->right)
        return true;
    return false;
}

// for traversing left boundary excluding leaf nodes
void leftB(Node *root, vector<int> &ans)
{
    Node *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            ans.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

// for traversing right boundary in reverse excluding leaf nodes
void rightB(Node *root, vector<int> &ans)
{
    Node *cur = root->right;
    vector<int> temp;
    while (cur)
    {
        if (!isLeaf(cur))
            temp.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
        ans.push_back(temp[i]);
}

// for leaf nodes
void leaf(Node *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        leaf(root->left, ans);
    if (root->right)
        leaf(root->right, ans);
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    if (!isLeaf(root))
        ans.push_back(root->data);
    leftB(root, ans);
    leaf(root, ans);
    rightB(root, ans);
    return ans;
}

// main function
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    vector<int> BT = boundaryTraversal(root);
    for (auto i : BT)
        cout << i << " ";

    return 0;
}