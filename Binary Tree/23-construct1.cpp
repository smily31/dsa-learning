// Construct a Binary Tree using given inorder and preorder traversal
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


Node *build(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map<int, int> in)
{
    if (prestart > preend || instart > inend)
        return NULL;

    Node *root = new Node(preorder[prestart]); // since preorder me start me root hota h to uska root bana diya
    int inroot = in[preorder[prestart]];       // finding location of root in inorder
    int left = inroot - instart;               // no of elements in left subtree
    // recursively solving for smaller trees(left subtree and right subtree)
    root->left = build(preorder, prestart + 1, prestart + left, inorder, instart, inroot - 1, in);
    root->right = build(preorder, prestart + left + 1, preend, inorder, inroot + 1, inend, in);

    return root;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> in;
    for (int i = 0; i < inorder.size(); i++)
        in[inorder[i]] = i;
    Node *root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size(), in);
    return root;
}

void check(Node *root)
{
    if (root == NULL)
        return;
    check(root->left);
    check(root->right);
    cout << root->data << " ";
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};
    Node *root = buildTree(preorder, inorder);
    cout << "Since our tree is being constructed \n To check if same unique tree is constructed printing inorder \n";
    check(root);
}