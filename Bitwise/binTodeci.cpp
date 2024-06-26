#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
using namespace std;
int main()
{
    int dgt=0,n,i=0;
    cout<<"Enter the binary number";
    cin>>n;
    while(n!=0)
    {
        dgt=n%10;
        if(dgt==1)
        {
            dgt=dgt+pow(2,i);
        }
        n=n/10;
        i++;
     
    }
    cout<<"Decimal value is"<<dgt;
}