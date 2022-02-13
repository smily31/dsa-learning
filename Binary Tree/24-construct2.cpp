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

Node *build(vector<int> &postorder, int poststart, int postend, vector<int> &inorder, int instart, int inend, map<int, int> in)
{
    if (poststart > postend || instart > inend)
        return NULL;

    Node *root = new Node(postorder[postend]); // since preorder me start me root hota h to uska root bana diya
    int inroot = in[postorder[postend]];       // finding location of root in inorder
    int left = inroot - instart;               // no of elements in left subtree
    // recursively solving for smaller trees(left subtree and right subtree)
    root->left = build(postorder, poststart, poststart + left-1, inorder, instart, inroot - 1, in);
    root->right = build(postorder, poststart + left , postend-1, inorder, inroot + 1, inend, in);

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
    cout << root->data << " ";
    check(root->left);
    check(root->right);
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9,15,7,20,3};
    Node *root = buildTree(postorder, inorder);
    cout << "Since our tree is being constructed \n To check if same unique tree is constructed printing inorder \n";
    check(root);
}