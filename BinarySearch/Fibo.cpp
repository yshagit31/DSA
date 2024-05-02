//code to fibonacci series

#include<iostream>
// #include<stdio.h>
using namespace std;
int main()
{
    int prev=0,pres=1,fib=0,n;
      cin>>n;
      for( int i=0;i<n;i++)
      {
        if(i==0){cout<<prev<<" "; continue;} 
        if(i==1) {cout<<pres<<" "; continue; }
        fib=pres+prev;
        prev=pres;
        pres=fib;
        cout<<fib<<" ";
        fib=prev+pres;

      }

    
}