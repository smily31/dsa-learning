// Bottom View of Binary Tree

#include<bits/stdc++.h>
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
vector<int> bottomView(Node * root)
{
    vector<int> ans;
    if(!root)
        return ans;
    queue<pair<Node*,int>> q;   // Node, vertical line
    map<int,int>m;   // vertical line, node value
    q.push({root, 0});
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;
        m[line] = node->data;
        if(node->left)
            q.push({node->left, line-1});
        if(node->right)
            q.push({node->right, line+1});
    }
    for(auto i:m)
    {
        ans.push_back(i.second);
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

    vector<int> BV = bottomView(root);
    for (auto i : BV)
        cout << i << " ";

    return 0;
}