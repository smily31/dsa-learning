// Vertical Traversal
// print vertically from left to right
// TC - O(N)logN    logN for multiset
// SC - O(N)

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

vector<vector<int>> verticalTraversal(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<pair<Node *, pair<int, int>>> q; // node, vertical, level
    map<int, map<int, multiset<int>>> m;   // vertical, level, node->value

    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        Node *node = p.first;
        int x = p.second.first;     // vertical
        int y = p.second.second;    // level
        m[x][y].insert(node->data); // map me vertical,level pe value dal rhe
        if (node->left)
            q.push({node->left, {x - 1, y + 1}}); // left jayenge to vertical -1 hoga and level +1
        if (node->right)
            q.push({node->right, {x + 1, y + 1}}); // right jayenge to vertical +1 hoga and level +1
    }
    for (auto v : m)
    {
        vector<int> col;
        for (auto w : v.second)
        {
            col.insert(col.end(), w.second.begin(), w.second.end());
        }
        ans.push_back(col);
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

    vector<vector<int>> VT = verticalTraversal(root);
    for (auto i : VT)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
