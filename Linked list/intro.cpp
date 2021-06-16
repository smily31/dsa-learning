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

// INSERTION -> inserting a node

//insert at end
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

//DELETION -> deleting a node

// deleting a node from start
void deleteAthead(node* &head)
{
    node* todelete = head;   
    head = head->next;
    delete todelete;
}

// deleting a node from any where
void deletion(node* &head, int val)
{
    //if linkedlist is empty
    if(head == NULL)
        return;
    
    //if only one node is present
    if(head->next == NULL)
    {
        deleteAthead(head);
    }
    // for inbetween delete
    //find n-1th node and link it to n+1th node
    node* temp = head;
    while(temp->next->data != val)
    {
        temp = temp->next;
    }// we'll reach to n-1th node
    node* todelete = temp->next; //storing nth node to be deleted
    temp->next = temp->next->next;
    delete todelete;

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
    cout<<search(head,5)<<endl;
    deletion(head,2);
    display(head);
    deleteAthead(head);
    display(head);
    return 0;
}