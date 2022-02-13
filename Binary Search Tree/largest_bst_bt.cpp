// Leetcode Premium Question

// Find the number of largest BST in a Binary Tree

// TC - O(N)
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

class nodeValue
{
    public:
        int minValue;
        int maxValue;
        int maxSize;
    nodeValue(int minValue, int maxValue, int maxSize)
    {
        this->minValue =  minValue;
        this->maxValue = maxValue;
        this->maxSize = maxSize;
    }
};

// applying postorder to first calculate min, max , size from left and right then checking for root
class bstlargest
{
    public:
        nodeValue largestBst(Node* root)
        {
            if(root == NULL)
                return nodeValue(INT_MAX, INT_MIN, 0);
            auto  left = largestBst(root->left);
            auto  right = largestBst(root->right);
            if(left.maxValue < root->data && right.minValue > root->data)
                return nodeValue(min(left.minValue, root->data), max(right.maxValue, root->data), left.maxSize+right.maxSize+1);
            else
                return nodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
        }
};


int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left = new Node(2);
    root->left->left->right = new Node(3);
    root->right = new Node(9);
    root->right->right = new Node(10);
    root->right->left = new Node(8);

    return 0;
}