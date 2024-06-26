//total no of set bits in given 
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
using namespace std;
int Setbits(int n)
{
    int bit,count=0;
    while(n!=0)
    {
        bit=n&1;
        if(bit==1) count++;
        n=n>>1;
    }
    return count;
}
int main()
{
 int a,b,i=0;
 cin>>a>>b;
 cout<<"Total set bits "<<Setbits(a)+Setbits(b);

}