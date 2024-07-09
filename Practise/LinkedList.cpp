#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node* next;
     public:
     Node(int data1,Node *next1)
     {
        data=data1;
        next=next1;
     }
     Node(int data1)
     {
        data=data1;
        next=nullptr;
     }

};
Node * ArraytoLL(vector <int> &A)
{
    Node * head =new Node(A[0]);
    Node * mover=head;
    for(int i=1;i<A.size();i++) 
    {
        Node *temp=new Node(A[i],nullptr);
        mover->next=temp;
        mover=temp;

    }
    return head;
}
int main()
{
    vector <int> A={2,3,4,5};
    Node *p=new Node(A[2],nullptr);
    Node q= Node(A[0],nullptr);
    cout<<p->data;
    cout<<endl<<q.data<<endl;
    Node *head=ArraytoLL(A);
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }

    return 0;

}