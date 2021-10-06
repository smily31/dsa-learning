#include<bits/stdc++.h>
using namespace std;

// Doubly Linked List implementation

// node using class -> whenever new node is made this will execute
class node
{
    public:
        int data;
        node* prev;
        node* next;

        node (int val)      // constructor
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
};


// Inserting a node at Head
node* insertAtBegin(node* &head, int data)
{
    node* temp = new node(data);  // creating a new node
    temp->next = head;
    if(head != NULL)  // if head is not NULL then we have to set previous also 
        head->prev = temp;
    return temp;    // returning new head
}

// Inserting a node at end 
node* insertAtEnd(node* &head, int data)
{
    node* temp = new node(data);   // creating a new node
    if(head == NULL)    // if empty linkedlist
        return temp;    // then our new head is temp
    node* curr = head;
    while(curr->next != NULL)
        curr = curr->next;     //  reaching the end to link new node
    curr->next = temp;
    temp->prev = curr;
    return head;
}

// Reversing a DLL -> idea is to swap next and prev of current node
// TC- O(n)   AS-O(1)
node* reverseDLL(node* head)
{
    if(head == NULL || head->next == NULL)  // covering corner cases of having 0 or 1 node
        return head;  
    node* prev = NULL;
    node* curr = head;
    while(curr != NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;       // swapping
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;    // returning new head
}

// Delete a node from front/head
node* deleteAtHead(node* head)
{
    if(head == NULL)      // if DLL is empty
        return NULL;
    if(head->next == NULL)    // if only 1 node is present
    {
        delete head;
        return NULL;
    }
    else 
    {
        node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;  // returning new head
    }
}


// Delete a node from end
node* deleteAtEnd(node* head)
{
    if(head == NULL)   // if DLL is empty
        return NULL;
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node* curr = head;
    while(curr->next != NULL)
        curr = curr->next;
    curr->prev->next = NULL;
    delete curr;
    return head;
}

//Displaying a doubly linked list
void display(node* head)
{
    node* temp=head;   // no need to take temp as head is pass by value
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
    head = insertAtEnd(head,10);
    head = insertAtEnd(head,20);
    head = insertAtEnd(head,30);
    display(head);

    // node* newhead  = reverseDLL(head);
    // display(newhead);
    // head = deleteAtHead(head);
    // head = deleteAtEnd(head);
    // display(head);

    return 0;
}
