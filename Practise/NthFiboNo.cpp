#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
using namespace std;
int Fibonacci( int n)
{
    int prev=0, curr=1,fibo;
    for(int i=0;i<n-2;i++){
        fibo=prev+curr;
        prev=curr;
        curr=fibo;
    }
    return fibo;
}
int main()
{
int nnum,n;
cin>>n;
 nnum=Fibonacci(n);
cout<<"Nth fibonaaci no "<<nnum;
return 0;
}