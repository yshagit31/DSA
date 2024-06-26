//Swap alternate nos in an array
//if array is a[1,2,3,4,5,6] then alternate swap becomes [2,1,4,3,6,5]
//we swap i and i+1 until i+1 is in range 

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
using namespace std;
void swapAlternate(int arr[],int n)
{
 int temp;
 for(int i=0;i+1<n;i+=2)
 {
    temp=arr[i];
    arr[i]=arr[i+1];
    arr[i+1]=temp;
 }
}
void printArray(int *arr,int n)
{
    cout<<endl<<"Swapped array";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
    
}
int main()
{
 int A[]={1,2,3,4,5,6},n;
  n=sizeof(A)/sizeof(A[0]);
 swapAlternate(A,n);
 printArray(A,n);

  int B[5]={1,2,3,4,5};
   swapAlternate(B,5);
 printArray(B,5);

}