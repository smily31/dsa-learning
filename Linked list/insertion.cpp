#include<bits/stdc++.h>
using namespace std;

// Linked list implementation

// node using class -> whenever new node is made this will execute
class node
{
    public:
        int data;
        node* next;

        node (int val)      // constructor
        {
            data =val;
            next =NULL;
        }
};

void insertAtTail(node* &head, int val)
{
    //initialising new node
    node* n = new node(val);

    //if linked list is empty , insert at head or first pos
    if(head == NULL)
    {
        head = n;
        return;
    }
    //else inserting at tail
    node* temp =head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// inserting at starting of linkedlist
void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    head = n;
}

// displaying the linked list
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

//searching a node
bool search(node* head, int k)   //here head is passed by value hence it not alter linkedlist
{
    while(head!=NULL)
    {
        // node* temp=head;
        if(head->data == k)
            return true;
        head = head->next ;
    }
    return false;
}
// main function
int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,4);
    display(head);
    cout<<search(head,1);
    return 0;
}