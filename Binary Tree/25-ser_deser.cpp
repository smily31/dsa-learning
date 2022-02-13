// Serialize and Deserialize Binary Tree
// Tree gets serialize into string
// and this string gets deserialize into tree

// TC ~ O(N)
// SC ~ O(N)

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

// SERIALIZE
// to serialize we do level traversing and convert tree into string {for NULL we add '#'}
string serialize(Node *root)
{
    if (root == NULL)
        return "";
    string s = "";
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node == NULL)
            s.append("#,");
        else
        {
            s.append(to_string(node->data) + ",");
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

// DESERIALIZE
Node *deserialize(string st)
{
    if (st.size() == 0)
        return NULL;
    stringstream s(st); // creating string to treat as objects ->st string as object s me aa gya hai
    string str;
    getline(s, str, ',');   // everytime we do getline s se str me ek object aa jayega jo ki ',' ise distinguished h
    // root ke liye char nikl chuka
    Node *root = new Node(stoi(str)); // root banaya
    queue<Node *> q;
    q.push(root); // traverse ke liye store krke rkh rhe
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        // left ke liye char nikalo
        getline(s, str, ',');
        if (str == "#")
            node->left = NULL;
        else
        {
            Node *leftnode = new Node(stoi(str));
            node->left = leftnode;
            q.push(node->left); // queue me push kr de rhe taki aage iske left right insert kr ske
        }
        // right ke liye char nikalo
        getline(s, str, ',');
        if (str == "#")
            node->right = NULL;
        else
        {
            Node *rightnode = new Node(stoi(str));
            node->right = rightnode;
            q.push(node->right);
        }
    }
    return root;
}

void check(Node* nroot)
{
    if(nroot == NULL)
        return ;
    check(nroot->left);
    cout<<nroot->data<<" ";
    check(nroot->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);

    cout << serialize(root);

    Node *nroot = deserialize(serialize(root));
    check(nroot);

    return 0;
}