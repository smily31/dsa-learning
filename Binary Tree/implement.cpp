// Binary Tree implementation in C++

#include<bits/stdc++.h>
using namespace std;

// Defining the tree node
struct Node {
    int data;
    struct Node* left;   
    struct Node* right;   
    // constructor
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Tree traversal      {N  = number of nodes}

// DFS -> Depth First Search
// It is also of three types: 

// In-Order Traversal   => Left-Root-Right
// TC-O(N)
// Auxiallary SC - O(N)
void inorder(struct Node* node)
{
    if(node == NULL)
        return ;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}


// Pre-order traversal   => Root-Left-Right
// TC - O(N)               
// Auxiallary SC - O(N)
void preorder(struct Node* node)
{
    if(node == NULL)
        return ;
    cout<<node->data<<"->";
    preorder(node->left);
    preorder(node->right);
}


// Post-order traversal   => Left-Right-Root
// TC - O(N)               
// Auxiallary SC - O(N)
void postorder(struct Node* node)
{
    if(node == NULL)
        return ;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<"->";
}

// main function
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    // call traversal function according to your wish
    postorder(root);
    return 0;
}