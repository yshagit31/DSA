#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
using namespace std;
int AP(int n)
{
    return (3*n)+7;
}
int main()
{
int term=0,n,i=0;
cin>>n;
term=AP(n);
cout<<"Nth term is "<<term; 
}
