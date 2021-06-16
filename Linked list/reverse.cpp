#include<bits/stdc++.h>
using namespace std;

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


// Reversing a linked list

// iterative method
node* reverse(node* &head)
{
    node* prev = NULL;
    node* cur = head;
    node* nxt;
    while(cur != NULL)  //when cur node reach to null and prev to last node
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    // pointing head to prev as prev is pointing to last node which is now first node
    return prev;
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
    insertAtTail(head,4);
    display(head);
    node* newhead = reverse(head); 
    display(newhead);
    return 0;
}