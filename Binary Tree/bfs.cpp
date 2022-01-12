// BFS = Breadth First Search Traversal = Level Order Traversal(left to right)
// TC - O(N)
// Auxiallary SC - O(N)

#include <bits/stdc++.h>
using namespace std;

// Defining the tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// storing the node level wise in ds {2D vector}
vector<vector<int>> bfs(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans; // if there is empty tree then answer would be empty ds
    queue<node *> q;  // queue to store every node of same level so that we can traverse it for their child
    q.push(root);  
    while (!q.empty())
    {
        int n = q.size();     // getting size of particular level
        vector<int> level; 
        for (int i = 0; i < n; i++)
        {
            node *newnode = q.front(); 
            q.pop();
            if (newnode->left != NULL)
                q.push(newnode->left);
            if (newnode->right != NULL)
                q.push(newnode->right);
            level.push_back(newnode->data);
        }
        ans.push_back(level);     // level wise entering data
    }
    return ans;
}

// main function
int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    // print level wise order
    vector<vector<int>> res = bfs(root);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}