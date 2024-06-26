//link- https://www.naukri.com/code360/problems/sort-0-1-2_631055?source=youtube&campaign=LoveBabbar_Codestudiovideo1
// Problem statement
// You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.

// Note :
// Try to solve the problem in 'Single Scan'. ' Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 10
// 1 <= N <= (5 * (10 ^ 5))
// 0 <= ARR[i] <= 2

// Where 'N' is the size of the given array/list.
// And, ARR[i] denotes the i-th element in the array/list.

// Time Limit: 1sec 
// Sample Input 1 :
// 2
// 6
// 0 1 2 2 1 0
// 7
// 0 1 2 1 2 1 2
// Sample Output 1 :
// 0 0 1 1 2 2
// 0 1 1 1 2 2 2
// Sample Input 2 :
// 2
// 7
// 2 2 2 1 1 1 0
// 6
// 2 1 2 0 1 0
// Sample Output 2 :
// 0 1 1 1 2 2 2
// 0 0 1 1 2 2


#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
  int count0=0, count1=0,count2=0,i;
  for( i=0;i<n;i++)
  {
     if(arr[i]==0)
     {
        count0++;
     }
     else if(arr[i]==1)
     {
        count1++;
     }
     else 
     {
        count2++;
     }
  }
  for( i=0;i<count0;i++)
  {
     arr[i]=0;
  }
   for( i=count0;i<count0+count1;i++)
  {
     arr[i]=1;
  }
    for( i=count0+count1;i<count2+count1+count0;i++)
  {
     arr[i]=2;
  }
   }


   //Dutch national flag algorithm

   #include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
  int low,mid,high;
  low=mid=0;
  high=n-1;
 while(mid<=high)
 {
     if(arr[mid]==0)
     {
    //    swap(arr[low],arr[mid]);
       low++,mid++;
     }
     else if(arr[mid]==1)
     {
      mid++;
     }
     else 
     {
        // swap(arr[mid],arr[high]);
       high--;
     }
  }

   }