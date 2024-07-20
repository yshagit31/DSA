#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data1)
    {
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
    Node(int data1,Node* next1,Node*prev1)
    {
        data=data1;
        next=next1;
        prev=prev1;
    }

};
Node* ArrayToDLL(vector<int> &A)
{
    if(A.size()==0) return nullptr;
   Node*head=new Node(A[0]);
   Node*p=head;
   for(int i=1;i<A.size();i++)
   {
    Node*temp=new Node(A[i],nullptr,p);
    p->next=temp;
    p=p->next;  //p=temp;
   }
   return head;
}
void InsertBeforeHead(Node*&head,int val)  //takes reference of head so changes that only, not pass by value so original head changes
{
 Node*temp=new Node(val,head,nullptr);
 head=temp;
//  return head;
}
Node* InsertAfterTail(Node*head,int val)
{
    Node*p=head;
    while(p->next!=nullptr)
    {
        p=p->next;
    }
     Node*temp=new Node(val,nullptr,p);
     p->next=temp;
    return head;
}
Node* InsertAfter(Node *head, int val, int pos)
{
    Node*p=head;
    int cnt=0;
    if(p==nullptr&&pos==0)
    {
        Node*temp=new Node(val,nullptr,nullptr);
        head=temp;
        return head;
    }
    while(p->next!=nullptr)
    {
        cnt++;
        if(pos==cnt) break;
        p=p->next;
    }
    if(pos>cnt+1||pos<1) ///we are insering after so we have a position after pos
    {
        cout<<"Enter valid position";
        return head;
    }
    Node*rear=p->prev,*front=p->next;
    if(!rear&&!front)  //only one node
    {
    Node*temp=new Node(val,nullptr,p);
    p->next=temp;
    }
    else if(!rear) //first node
    {
    Node*temp=new Node(val,front,p);
    p->next=temp;
    }
    else if(!front) //last node
    {
    Node*temp=new Node(val,nullptr,p);
    p->next=temp;
    }
    else {
    Node*temp=new Node(val,front,p);
    p->next=temp;
    front->prev=temp;
    }
    return head;

}
int main()
{
    vector <int> A={1,4,8};
    Node*head=ArrayToDLL(A);
    // InsertBeforeHead(head,6);
    // head=InsertAfterTail(head,12);
    head=InsertAfter(head,5,3);
    cout<<endl;
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}