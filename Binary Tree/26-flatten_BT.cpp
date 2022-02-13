// Flatten a Binary Tree to a Linked List
// without creating a new node instead rearranging the available one
// i.e inplace

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

// First Approach -> Reverse postorder -> right left root
// TC - O(N)
// SC - O(N)

Node *prevNode = NULL;
void flat1(Node *root)
{
    if (root == NULL)
        return;
    flat1(root->right);
    flat1(root->left);

    root->right = prevNode;
    root->left = NULL;

    prevNode = root;
}

// Second Approach -> Using stack , no better or worse than recursion one
// TC - O(N)
// SC - O(N)
Node *flat2(Node *root)
{
    if (root == NULL)
        return NULL;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *cur = s.top();
        s.pop();
        if (cur->right)
            s.push(cur->right);
        if (cur->left)
            s.push(cur->left);
        if (!s.empty())
        {
            cur->right = s.top();
            cur->left = NULL;
        }
    }
    return root;
}

// Linked list traversal
void print(Node *root)
{
    while (root)
    {
        cout << root->data << " ";
        root = root->right;
    }
}

// Third Approach - Using morris traversal approach
// TC - O(N)
// SC - O(1)

// abhi padhe nhi h 

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

    // print(flat2(root));
    flat1(root);
    print(root);

    return 0;
}
