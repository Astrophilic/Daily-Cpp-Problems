#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// A linked list node
struct Node
{
  int data;
  struct Node *next;
};

Node *getNode(int value)
{
    Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=value;
    new_node->next=nullptr;
    return new_node;
}

void push(Node ** headRef, int x)
{
    Node *new_node=getNode(x);
    new_node->next=*headRef;
    *headRef=new_node;
}
void traverse(Node* root)
{

    while(root)
    {
        cout<<root->data<<" ";
        root=root->next;

    }
    cout<<"\n";


}

void append(Node **headRef,int value)
{

    Node* new_node=getNode(value);
    if(*headRef==nullptr)
    {
        *headRef=new_node;
        return;
    }

    Node *last=*headRef;
    while(last->next!=nullptr)
        last=last->next;

        last->next=new_node;

}

void insertAfter(Node* prev_node,int value)
{
    Node* new_node=getNode(value);

    if(prev_node==nullptr)
        return;
    new_node->next=prev_node->next;
    prev_node->next=new_node;

}
int main()
{
    struct Node* head=nullptr;
    append(&head,1);
    traverse(head);
    append(&head,2);
    traverse(head);
    insertAfter(head->next,3);
    traverse(head);
    push(&head,121);
    traverse(head);

    return 0;
}
