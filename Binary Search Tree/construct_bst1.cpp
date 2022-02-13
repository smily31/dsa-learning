// Preorder traversal of bst is given we have to construct the bst

// Method 1 :
// in preorder first element is root then after that take element and insert to its right position
// TC - O(n*n)
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

// Method 2:
// store inorder in extra ds by sorting existing preorder
// then by using inorder and preorder form bst
// TC - O(nlogn)+O(n)
// SC - O(n)
Node *build(vector<int> &inorder, int ins, int ine, vector<int> &preorder, int pres, int pree, map<int, int> in)
{
    if (ins > ine || pres > pree)
        return NULL;
    Node *root = new Node(preorder[pres]);
    int inroot = in[root->data];
    int left = inroot - ins;
    root->left = build(inorder, ins, inroot - 1, preorder, pres + 1, pres + left, in);
    root->right = build(inorder, inroot + 1, ine, preorder, pres + left + 1, pree, in);
    return root;
}

Node *construct2(vector<int>& preorder)
{
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    map<int, int> in;
    for (int i = 0; i < inorder.size(); i++)
        in[inorder[i]] = i;
    Node *root = build(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, in);
    return root;
}

// Method 3:
// Using the concept of upper bound that we used in validate bst question
// TC - O(3n) ~ O(n)
// SC - O(1)  , ASC - O(n)
Node *construct(vector<int> &preorder, int &i, int bound)
{
    if (i == preorder.size() || preorder[i] > bound)
        return NULL;
    Node *root = new Node(preorder[i++]);
    root->left = construct(preorder, i, root->data);
    root->right = construct(preorder, i, bound);
    return root;
}

// Traversing the BST
void show(Node *root)
{
    if (root == NULL)
        return;
    show(root->left);
    cout << root->data << " ";
    show(root->right);
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    int i = 0;
    Node *root = construct2(preorder);
    show(root);
    return 0;
}