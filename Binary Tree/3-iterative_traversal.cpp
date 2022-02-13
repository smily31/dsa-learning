// Binary Tree implementation in C++

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

// Tree traversal      {N  = number of nodes}

// DFS -> Depth First Search
// It is also of three types:

// Here we implement all traversal in iterative method

// In-Order Traversal   => Left-Root-Right
// TC-O(N)
// Auxiallary SC - O(N)
// go to the left most until null is hitted then print that or pop it and then go to its right and then repeat(i.e. go to its leftmost untilll)

vector<int> inorder(struct Node *root)
{
    stack<Node *> s;
    vector<int> ans;
    Node *node = root;
    while (true)
    {
        if (node != NULL)
        {
            s.push(node);
            node = node->left;
        }
        else
        {
            if (s.empty())
                break;
            node = s.top();
            s.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}

// Pre-order traversal   => Root-Left-Right
// TC - O(N)
// Auxiallary SC - O(N) ~~ O(H)
vector<int> preorder(struct Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *node = s.top();
        s.pop();
        ans.push_back(node->data);
        if (node->right != NULL)
            s.push(node->right);
        if (node->left != NULL)
            s.push(node->left);
    }
    return ans;
}

// Post-order traversal   => Left-Right-Root
// TC - O(N)
// Auxiallary SC - O(2N) because there are two stacks
// This one is using two stacks
vector<int> postorder_2(struct Node *root)
{
    stack<Node *> s1;
    stack<Node *> s2;
    vector<int> ans;
    if (root == NULL)
        return ans;
    s1.push(root);
    while (!s1.empty())
    {
        Node *node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left != NULL)
            s1.push(node->left);
        if (node->right != NULL)
            s1.push(node->right);
    }
    while (!s2.empty())
    {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}
// Post-order traversal using single stack
// TC - O(2N)
// ASC - O(N)
vector<int> postorder_1(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = s.top()->right;
            if (temp == NULL)
            {
                temp = s.top();
                s.pop();
                ans.push_back(temp->data);
                while (!s.empty() && temp == s.top()->right) // O(N)
                {
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return ans;
}

// main function
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(7);
    root->left->left = new Node(4);
    // call traversal function according to your wish
    vector<int> v = inorder(root);
    for (auto i : v)
        cout << i << " ";
    return 0;
}