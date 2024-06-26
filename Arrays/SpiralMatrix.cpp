#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
using namespace std;
int main()
{
// int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int arr[5][5]={{1,2,3,4,22},{5,6,7,8,23},{9,10,11,12,24},{13,14,15,16,25},{18,19,20,21,26}};
int n=5,i=0,r,c,k,col,row;
  k=0;
for(i=0;i<n;i+=2)
{
  for(c=0+k;c<n-k;c++)
  {
    cout<<" "<<arr[k][c];
  }
  cout<<"  ";
  c--;
   for(r=k+1;r<n-k;r++)
  {
    cout<<" "<<arr[r][c];
  }
   cout<<"  ";
   r--;
   for(col=c-1;col>k-1;col--)
  {
    cout<<" "<<arr[r][col];
  }
   cout<<"  ";
   for(row=r-(k+1);row>k;row--)
  {
    cout<<" "<<arr[row][k];
  }
   cout<<"  ";
  k++;
}
return 0;
}