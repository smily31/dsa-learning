// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree

// BSTIterator(TreeNode root) : Initializes an object of the BSTIterator class. The root of the BST is given as part
// of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.

// boolean hasNext()         : Returns true if there exists a number in the traversal to the right of
// the pointer, otherwise returns false.

// int next()                : Moves the pointer to the right, then returns the number at the pointer.

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

// TC - O(H)
// SC ~ O(1)
class BSTIterator
{
private:
    stack<Node *> s;
    void pushAll_left(Node *root)
    {
        for (; root != NULL; root = root->left)
            s.push(root);
    }
    void pushAll_right(Node *root)
    {
        for (; root != NULL; root = root->right)
            s.push(root);
    }
    

public:
    BSTIterator(Node *root)
    {
        pushAll_left(root);
    }

    bool hasnext()
    {
        return !s.empty();
    }

    int next()
    {
        Node *cur = s.top();
        s.pop();
        pushAll_left(cur->right);
        return cur->data;
    }

    // before ke liye stack alg hoga bs implementation dikha rhe
    int before()
    {
        Node *cur = s.top();
        s.pop();
        pushAll_right(cur->left);
        return cur->data;
    }
};
