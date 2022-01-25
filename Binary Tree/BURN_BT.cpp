// Minimum time required to BURN a Binary tree

// TC - O(2N) ~ O(N)    {ignored logN of Hashmap}
// SC - O(3N) ~ O(N)

#include <bits/stdc++.h>
using namespace std;

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

void markParent(Node *root, unordered_map<Node *, Node *> &m)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *cur = q.front();
            q.pop();
            if (cur->left)
            {
                m[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right)
            {
                m[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
}

int BURN(Node *root, Node *start)
{
    unordered_map<Node *, Node *> map; // child-parent
    markParent(root, map);
    queue<Node *> q;
    q.push(start);
    unordered_map<Node *, bool> visited;
    visited[start] = true;
    int time = 0;
    while (!q.empty())
    {
        int n = q.size();
        // time++;          agr phle hi time++ kr denge then jb kisi traverseral pe koi node burn nhi hoga phir bhi uski value increase ho jayegi isliye ek flag variable lena padea
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            Node *cur = q.front();
            q.pop();
            if (cur->left && !visited[cur->left])
            {
                flag = 1;
                q.push(cur->left);
                visited[cur->left] = true;
            }
            if (cur->right && !visited[cur->right])
            {
                flag = 1;
                q.push(cur->right);
                visited[cur->right] = true;
            }
            if (map[cur] && !visited[map[cur]])
            {
                flag = 1;
                q.push(map[cur]);
                visited[map[cur]] = true;
            }
        }
        if (flag)
            time++;
    }
    return time; // because starting node also counts itself
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

    int ans = BURN(root, root->right->right->right);
    cout << " Minimum time required to burn the given tree is " << ans << endl;
    return 0;
}