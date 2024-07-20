#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int data1)
    {
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
     Node(int data1,Node* next1, Node* prev1)
    {
        data=data1;
        next=next1;
        prev=prev1;
    }
};
Node * ArraytoDLL(vector <int> &A)
{
     if(A.size()==0) return nullptr;
    Node*head=new Node(A[0]);
    Node*p=head;
    for(int i=1;i<A.size();i++)
    {
        Node* temp=new Node(A[i],nullptr,p);
        p->next=temp;
        p=temp;

    }
    return head;
}
Node* DeleteHead(Node*head)
{
    if(head==nullptr)
    {
        return nullptr;
    }
    Node*p=head;
    head=head->next;
    head->prev=nullptr;
    p->next=nullptr;
    delete p;

    return head;
}
Node* DeleteTail(Node* head)
{
    if(head==nullptr) return nullptr;
    Node*tail=head;
    while (tail->next)
    {
        tail=tail->next;
    }
    Node*p=tail->prev;
    tail->prev=nullptr;
    p->next=nullptr;
    free(tail);
    return head;
}

Node* DeleteK(Node *head,int pos)
{
    if(head==nullptr) return nullptr;
    Node*p=head;
    int cnt=0;
    while(p->next)
    {
        cnt++;
        if(pos==cnt) break;
        p=p->next;
    }
    if((pos>cnt&&cnt!=0)||pos<1) 
    {
        cout<<"Enter valid index"<<endl;
        return head;
    }
     Node*back=head->prev,*front=head->next;

    if(!front&&!back) 
    {
        p->prev=nullptr;
        p->next=nullptr;
        delete p;
         cout<<"Single node deleted";
         return nullptr;
    }
    else if(!front)
    {
        back->next=nullptr;
        p->prev=nullptr;
        delete p;
    }
    else if(!back)
    {
        p->next=nullptr;
        front->prev=nullptr;
        head=front;
        delete p;
    }
    else{
        back->next=front;
        front->prev=back;
        p->next=nullptr;
        p->prev=nullptr;
    }
    return head;
    
}
Node *DeletebyValue(Node *head, int val)
{
  Node* p=head;
  if(head==nullptr) return nullptr;
  while(p->next)
  {
    if(p->data==val) break;
    p=p->next;
  }
  if(val!=p->data) 
  {
    cout<<endl<<"Enter correct value";
    return head;
  }
  if(head->next==nullptr) //only one node
  {
    head->next=nullptr;
    return nullptr;
  }
  else if(p->next==nullptr)  //last node
  {
    p->prev->next=nullptr;
    p->prev=nullptr;
    delete p;
  }
else if(p->prev==nullptr) //first node and more than one node present
{
    head=head->next;
    head->prev=nullptr;
    p->next=nullptr;
    free(p);
}
else {
    p->prev->next=p->next;
    p->next->prev=p->prev;
    p->next=nullptr;
    p->prev=nullptr;
    delete p;
}  
    return head;
}
int main()
{
    vector <int> A({11,12,13,14});
    Node*head=ArraytoDLL(A);
    //  head=DeleteHead(head);
    //  head=DeleteTail(head);

    //  head=DeleteK(head,1);
     head=DeletebyValue(head,11);

    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }

}