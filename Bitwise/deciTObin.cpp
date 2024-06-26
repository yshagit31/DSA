//decimal to binary

#include<iostream>
#include<math.h>
// #include<stdio.h>
using namespace std;
int main()
{
   int n,i=0,bit;
   float bin=0;
   cout<<endl<<"Enter decimal number ";
   cin>>n;
   // if(n<0)
   // {
   //    bit=~(n&1);
   //    bin=(bit*pow(10,i)+bin);
      
   // }
   while(n!=0)
   {
    bit=n&1;   //gives last digit of binary form
    bin=(bit*pow(10,i)+bin);
    n=n>>1;
    i++;
   }
   cout<<endl<<bin;
   return 0;
}