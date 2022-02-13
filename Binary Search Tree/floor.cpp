// Find the floor of given number(node) in binary search tree
// TC - O(logN)   - height of binary tree

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

int floor(Node* root, int val)
{
    int floor = -1;
    while(root)
    {
        if(root->data == val)
        {
            floor = root->data;
            return floor;
        }
        if(val < root->data)
            root = root->left;
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}


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

    cout<<"Floor of given number is "<<floor(root, 70);
    return 0;
}
