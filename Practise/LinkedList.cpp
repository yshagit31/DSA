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
    if(A.empty()) return nullptr;
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
Node* InsertAfter(Node *head,int val, int pos)
{
    //My method
    Node*p=head;
   if(p==nullptr&&pos==0)
    {
        Node*temp=new Node(val,nullptr);
        head=temp;
        return head;
    }
    if(p==nullptr) return nullptr;
    int cnt=0;
    while(p->next)
    {
        cnt++;
        if(pos==cnt) break;
        p=p->next;
    }
    if(pos>cnt+1||pos<1)
    {
        cout<<"Invalid Position";
        return head;
    }
    if(p->next==nullptr) //last node
    {
        Node* temp=new Node(val,nullptr);
        p->next=temp;
    }
    else{
            Node* temp=new Node(val,p->next);
            p->next=temp;
    }
    return head;

}
int main()
{
    vector <int> A={2,4,6};
    // Node *p=new Node(A[2],nullptr);
    // Node q= Node(A[0],nullptr);
    // cout<<p->data;
    // cout<<endl<<q.data<<endl;
    Node *head=ArraytoLL(A);
    head=InsertAfter(head,1,1);
    cout<<endl;
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }

    return 0;

}