// Top View of Binary Tree

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

// using vertical traversal technique to get top view
// TC - O(N)
// SC - O(N)

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<Node *, int>> q; // node, line
    map<int, int> m;            // line , node->value
    q.push({root, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node *node = p.first;
        int line = p.second;
        if (m.find(line) == m.end())
            m[line] = node->data;
        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}

// main function
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    vector<int> TV = topView(root);
    for (auto i : TV)
        cout << i << " ";

    return 0;
}