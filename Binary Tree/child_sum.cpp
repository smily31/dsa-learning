// Convert the Binary Tree to follow Children Sum Property
// Children Sum Property = node value = sum of left and right child node value

//  1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
//  2. You can not change the structure of the original binary tree.
//  3. You can assume the value can be 0 for a NULL node and there can also be an empty tree.

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

//             Algorithm Logic
//  if both children sum is less than parent, make children's value to parent's value.
//  if both children values sum is greater than or equal to parent, make parent's value to children's sum.
//  recursively go left and right. Traversal type: DFS.
//  when coming back up the tree, take children sum and replace it in parent.
//  at any point we reach null, just return (base case)

//  Intuition: while going down, increase the children values so we make sure to never fall short,
//  then all we have to do is sum both children and replace it in parent.

// TC - O(N)
// SC - O(H) ~ O(N) in case of skew tree

void childSumBT(Node *root)
{

    if (root == NULL)
        return; // base case
    int childSum = 0;
    if (root->left)
        childSum += root->left->data;
    if (root->right)
        childSum += root->right->data;

    if (childSum >= root->data) //children values sum is greater or equal to parent,make parent's value to children's sum.
        root->data = childSum;
    else
    { //  if both children sum is less than parent, make children's value to parent's value.
        if (root -> left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    //  recursively go left and right. Traversal type: DFS.
    childSumBT(root->left);
    childSumBT(root->right);

    // now when we have reached down then while going up
    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    if (root->left || root->right)
        root->data = tot;
}

void print(Node *root)
{
    if (root == NULL)
        return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

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

    cout << "Initial Binary Tree \n";
    print(root);
    cout << "After applying childSum function \n";
    childSumBT(root);
    print(root);

    return 0;
}