// Height of Binary Tree 
// Maximum depth in Binary Tree

// TC - O(N)
// SC - O(height of tree) ~ O(N)

// Another approach :-
// Can also use level order traversal to get height
// maintain a variable "level" which increments whenever you go left or right
// and the heightest level will be the answer

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int height(Node *root)
{
    if(!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);

    return 1+ max(left, right);
}

// main function
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
//  Getting height of the binary tree
    int h = height(root);
    cout<<"Height of Binary Tree is "<<h<<endl;
    return 0;
}