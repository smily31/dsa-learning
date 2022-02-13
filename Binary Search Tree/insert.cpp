// Insert a given node at its right position
// Disclaimer : you are never asked to insert the already existed node

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

Node* insert(Node* root, int val)
{
    if (root == NULL)
        return new Node(val);
    Node *cur = root;
    while(true)
    {
        if(cur->data < val)
        {
            if(cur->right != NULL)
                cur = cur->right ;
            else{
                cur->right = new Node(val);
                break;
            }
        }
        else if(cur->data > val)
        {
            if(cur->left != NULL)
                cur = cur->left;
            else{
                cur->left = new Node(val);
                break;
            }
        }
    }
    return root;
}

void show(Node* root)
{
    if(root == NULL)
        return ;
    show(root->left);
    cout<<root->data<<" ";
    show(root->right);
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

    cout<<"Befor insertion : ";
    show(root);
    root = insert(root, 7);
    cout<<"\nAfter insertion : ";
    show(root);
    return 0;
}