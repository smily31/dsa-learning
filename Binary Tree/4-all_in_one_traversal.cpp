// Preorder  Inorder  Postorder Traversal in One Traversal code

#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Here we have stack which contains node as well as a num
// if num == 1
// add node->val to preorder and then num++ and if(node->left exists) then insert into stack with num=1
// if num == 2
// add node->val to inorder and then num++ and if(node->right exists) then insert into stack with num=1
// if num == 3
// add node->val to postorder and pop it from stack

// TC - O(3N)
// ASC - O(3N)
vector<int> allTraversal(Node* root)
{
    vector<int> pre, in, post;
    if(root == NULL)
        return pre;
    stack<pair<Node*, int> > s;
    s.push({root,1});
    while(!s.empty())
    {
        auto it = s.top();
        s.pop();
        if(it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->left != NULL)
                s.push({it.first->left,1 });
        }
        else if(it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->right != NULL)
                s.push({it.first->right,1 });
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    return in;
}

// main function
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    // call traversal function according to your wish
    vector<int> v = allTraversal(root);
    for(auto i:v)
        cout<<i<<" ";
    return 0;
}

