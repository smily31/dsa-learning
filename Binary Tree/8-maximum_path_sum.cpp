// Find Maximum path sum in a Binary Tree
// Path - from node A to node B , not necessary to pass through root
// The path sum of a path is the sum of the node's values in the path.

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

int maxPathSum(Node *root, int &pathSum)
{
    if (!root)
        return 0;

    int left = max(0, maxPathSum(root->left, pathSum));
    int right = max(0, maxPathSum(root->right, pathSum));

    pathSum = max(pathSum, root->data + left + right);

    return root->data + max(left, right);
}

// main function
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    int pathSum = 0;
    maxPathSum(root, pathSum);
    cout << "Maximum path sum in given binary tree is " << pathSum << endl;

    return 0;
}