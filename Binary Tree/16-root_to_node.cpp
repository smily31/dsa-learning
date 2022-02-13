// Print the path from root to given node value
// Algorithm used - preorder
// Approach - insert a node in data structure first 
// check if it is equal to given node or not
// if any times true occurs then return it 
// otherwise go either left or right
// if false is returned from both then it means path is not ahead so pop that element from 
// data structure and return false  and control will go to next step

// TC - O(N)
// ASC - O(H)

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

bool path_node(Node *root, int x, vector<int> &path)
{
    if (root == NULL)
        return false;
    path.push_back(root->data);

    if (root->data == x)
        return true;
    if (path_node(root->left, x, path) || path_node(root->right, x, path))
        return true;
    path.pop_back();
    return false;
}

// main function
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    // if path exits then return path
    vector<int> path;
    if (path_node(root, 1, path))
    {
        for (auto i : path)
            cout << i << " ";
    }
    else
        cout << "Path doesn't exists \n";
    return 0;
}