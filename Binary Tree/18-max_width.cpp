// Maximum width of Binary Tree
// Width - Number of nodes in a level between any two nodes

// level order traversal with some indexing technique
// TC - O(N)
// ASC - O(N)

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

int max_width(Node *root)
{
    int ans = 0;
    if (!root)
        return ans;
    queue<pair<Node *, int>> q; // node, index
    q.push({root, 0});
    while (!q.empty())
    {
        int min_index = q.front().second;
        int n = q.size();
        int first, last;
        for (int i = 0; i < n; i++)
        {
            int cur_index = q.front().second - min_index;
            Node *node = q.front().first;
            q.pop();
            if (i == 0)
                first = cur_index;
            if (i == n - 1)
                last = cur_index;
            if (node->left)
                q.push({node->left, cur_index * 2 + 1});
            if (node->right)
                q.push({node->right, cur_index * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

// main function
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

    cout << "Maximum width in this tree is " << max_width(root) << "\n";

    return 0;
}