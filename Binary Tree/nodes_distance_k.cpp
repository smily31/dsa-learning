// Print all Nodes which are at distance of k with the given node

// TC - O(2N) ~ O(N)    {ignored logN of Hashmap}
// SC - O(3N) ~ O(N)
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

// Algorithm approach
// 1. Using bfs traversal and a map link every node to its parent in reverse order
// 2. Start from the given node and radially traverse upward , left and right one step at time
// 4. Store every node (i.e of upward, left, right) in a queue
// 5. Har jis node pe visit kr rhe use visited ds me dal denge
// 6. step ahead one by one until distance k is reached
// 7. and the remaining nodes in queue is the answer

// marking parent upward
void markParent(Node *root, unordered_map<Node *, Node *> &m)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *newnode = q.front();
            q.pop();
            if (newnode->left != NULL)
            {
                q.push(newnode->left);
                m[newnode->left] = newnode;
            }

            if (newnode->right != NULL)
            {
                q.push(newnode->right);
                m[newnode->right] = newnode;
            }
        }
    }
}

vector<int> nodeDisK(Node *root, Node *node, int k)
{
    unordered_map<Node *, Node *> m; // child, parent
    markParent(root, m);
    unordered_map<Node *, bool> visited;
    queue<Node *> q; // this queue will have answer at the end
    int curr_distance = 0;
    visited[node] = true;
    q.push(node);
    while (!q.empty()) // another bfs to reach nodes
    {
        int n = q.size();
        if (curr_distance == k)
            break;
        curr_distance++;
        for (int i = 0; i < n; i++)
        {
            Node *cur_node = q.front();
            q.pop();
            // going left
            if (cur_node->left && !visited[cur_node->left])
            {
                q.push(cur_node->left);
                visited[cur_node->left] = true;
            }
            // going right
            if (cur_node->right && !visited[cur_node->right])
            {
                q.push(cur_node->right);
                visited[cur_node->right] = true;
            }
            // going upward
            if (m[cur_node] && visited[m[cur_node]])
            {
                q.push(m[cur_node]);
                visited[m[cur_node]] = true;
            }
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        
        ans.push_back(q.front()->data);
            q.pop();
    }
    return ans;
}

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

    vector<int> ans = nodeDisK(root, root->right->right, 1);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}
