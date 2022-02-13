// Zig-Zag Level-order traversal
// i.e., from left to right, then right to left for the next level and alternate between

// TC - O(N)
// SC - O(N)

#include <bits/stdc++.h>
using namespace std;

// Defining the tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> zigZag(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    bool ltor = true; // this indicate that we'll enter element into vector left to right or right to left
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        vector<int> l(n);
        for (int i = 0; i < n; i++)
        {
            int index = ltor ? i : n - i - 1;
            Node *node = q.front();
            q.pop();
            l[index] = node->data;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ltor = !ltor;
        ans.push_back(l);
    }
    return ans;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    // print level wise order
    vector<vector<int>> res = zigZag(root);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}