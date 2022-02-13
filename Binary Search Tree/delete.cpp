// Delete a given node in Binary Search Tree
// TC - O(log N)
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

// this function returns the rightmost node of given tree
Node* find_right(Node* root)
{
    if(root->right == NULL)
        return root;
    return find_right(root->right);
}

// deleting the node in process and rearranging the left and right subtree and then returning 
Node* helper(Node* root)
{
    if(root->left == NULL)
        return root->right;
    if(root->right == NULL)
        return root->left;
    Node* rightChild = root->right;
    Node* left_rightmost = find_right(root->left);
    left_rightmost->right = rightChild;
    return root->left;
}

// delete node function
Node* deleteNode(Node* root, int x)
{
    if(root == NULL)     // if bst is empty
        return NULL;
    if(root->data == x)
        return helper(root);
    Node* head = root;
    while(head != NULL)      // finding the node to be deleted
    {
        if(x < head->data)
        {
            if(head->left != NULL && head->left->data == x)
            { 
                head->left = helper(head->left);
                break;
            }
            else
                head = head->left;
        }
        else
        {
            if(head->right != NULL && head->right->data == x)
            {
                head->right = helper(head->right);
                break;
            }
            else
                head = head->right;
        }
    }
    return root;
}


// display tree
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
    root = deleteNode(root, 7);
    cout<<"\nAfter insertion : ";
    show(root);
    return 0;
}