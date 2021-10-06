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

// Circular Linked List Implementation


// inserting a node at head 

// O(N)  approach -> traversing the LL and reaching the tail and then adding the head and changing the link
// Upper approach can be improved by maintaining a tail pointer and thus we only need to change the next pointer 
// then it has TC=O(1)
// but maintaining a tail pointer is burdensome
// We can achieve O(1) ->another approach-> inserting node after head and then swapping their data
node* insertAtHead(node* head, int data)
{
    node* temp = new node(data);   // creating a new node
    if(head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    node* curr = head;
    while(curr->next != head)      // reaching the tail
        curr = curr->next;
    curr->next = temp;
    temp->next = head;
    return temp;
}

node* insertAtHead2(node* head, int data)
{
    node* temp = new node(data);   // creating a node
    if(head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;    // inserting new node after head
    head->next = temp;
    // swappong the value
    int t = head->data;
    head->data = temp->data;
    temp->data = t; 
    return head;
}

// Inserta node at end
// TC - O(N)   it can be optimised to O(1) by maintaing tail pointer
node* insertAtEnd(node* head, int data)
{
    node* temp = new node(data);   // creating a node
    if(head == NULL)    // if LL is empty
    {
        temp->next = temp;
        return temp;
    }
    node* curr = head;
    while(curr->next != head)
        curr = curr->next;
    curr->next = temp;
    temp->next = head;
    return head;
}
// insert at end can also be optimised to O(1) without maintaining tail pointer
// approach -> insert node after head then swap it and return temp as head
node* insertAtEnd2(node* head, int data)
{
    node* temp = new node(data);   // creating a node
    if(head == NULL)    // if LL is empty
    {
        temp->next = temp;
        return temp;
    }
    else{
        temp->next = head->next; 
        head->next = temp;
        return temp;
    }
}

// DELETION

// delete a node from head
// Approach -> reach the tail-change the link-delete head-return new head
// TC-O(N)
node* deleteAtHead(node* head)
{
    if(head == NULL)   // if CLL is empty
        return NULL;
    if(head->next == head)   // if only 1 node is present
    {
        delete head;
        return NULL;
    }
    node* curr = head;
    while(curr->next != head)
        curr = curr->next;
    curr->next = head->next;
    delete head;
    return curr->next;
}
// Upper deletion method can be optimised to O(1)
// approach->copy the data of second node to head and then delete second node
node* deleteAtHead2(node* head)
{
    if(head == NULL)   // if CLL is empty
        return NULL;
    if(head->next == head)   // if only 1 node is present
    {
        delete head;
        return NULL;
    }
    head->data = head->next->data;
    node* temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

// delete node at kth position
// Approach-> we will find the (k-1)th node and then change its next to (k+1)th node and then delete the kth node
node* deleteAnywhere(node* head, int k)
{
    if(head == NULL) 
        return NULL;
    if(k == 1)
        return deleteAtHead2(head);
    else
    {
        node* curr = head;
        for(int i=1 ; i<k-1 ; i++)
            curr = curr->next;
        node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
    }
}

// circular traversal
void display(node* head)
{
    if(head == NULL)   // if CLL is empty
        return ;       // no display
    cout<<head->data<<"->";   // if CLL is not empty then display atleast one node
    for(node* p = head->next; p != head; p=p->next)     // start from second node and travel till before head 
    {
        cout<<p->data<<"->";
    }
}

int main()
{
    // node* head = new node(10);
    // head->next = new node(20);
    // head->next->next = new node(30);
    // head->next->next->next = new node(40);
    // head->next->next->next->next = head;

    node* head = NULL;
    head = insertAtHead(head , 50);
    head = insertAtHead2(head , 10);
    head = insertAtEnd2(head , 10);
    head = insertAtEnd2(head , 20);
    head = insertAtEnd2(head , 30);
    display(head);
    cout<<endl;
    head = deleteAnywhere(head,5);
    display(head);
    return 0;
}