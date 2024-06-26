//link- https://www.naukri.com/code360/problems/maximum-subarray-sum_630526?leftPanelTabValue=PROBLEM
// Problem statement
// You are given an array 'arr' of length 'n', consisting of integers.
// A subarray is a contiguous segment of an array. In other words, a subarray can be formed by removing 0 or more integers from the beginning and 0 or more integers from the end of an array.

// Find the sum of the subarray (including empty subarray) having maximum sum among all subarrays.
// The sum of an empty subarray is 0.

// Example :
// Input: 'arr' = [1, 2, 7, -4, 3, 2, -10, 9, 1]
// Output: 11

// Explanation: The subarray yielding the maximum sum is [1, 2, 7, -4, 3, 2].
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 9
// 1 2 7 -4 3 2 -10 9 1

// Sample Output 1 :
// 11

// Explanation for Sample 1 :
// The subarray yielding the maximum sum is [1, 2, 7, -4, 3, 2].

// Sample Input 2 :
// 6
// 10 20 -30 40 -50 60

// Sample Output 2 :
// 60

// Sample Input 3 :
// 3
// -3 -5 -6

// Sample Output 3 :
// 0

// Expected time complexity :
// The expected time complexity is O(n).

// Constraints :
// 1 <= 'n' <= 10 ^ 6
// -10 ^ 6 <= 'arr[i]' <= 10 ^ 6

// Time limit: 1sec

//In this one if sum is <0 then sum is given as 0

#include<bits/stdc++.h>
using namespace std;


//Brute Force
//This will give TLE
long long maxSubarraySum(vector<int> arr, int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
       int sum=0;
    for(int j=i;j<n;j++)
    {
        sum=sum+arr[j];
        if(sum<0) sum=0;
        if(sum>max)
        {
            max=sum;
        }
    }
    }
    if(max==INT_MIN) max=0;
    return max;
}



//Kadane's Algorithm
long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum=0,maxS=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(sum>maxS)
        {
            maxS=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
  
    return maxS<0 ? 0:maxS ;
}


//INPLACE Approach

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where N is the length of the array.
*/

long long maxSubarraySum(vector<int> arr, int n)
{
    long long maxSum = 0, curSum = 0;

    for(int i=0; i<n; i++)
    {
        curSum = max(0ll, curSum + arr[i]);  //0 ll is for representing 0 as long long
        maxSum = max(maxSum, curSum);
    }

    return maxSum;
}

//Sum of array approach

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where N is the length of the array.
*/

long long maxSubarraySum(vector<int> arr, int n)
{
    long long curSum[n];
    long long maxSum = 0;

    for(int i=0; i<n; i++)
    {
        if(i == 0)
        {
            curSum[i] = max(0, arr[i]);
        }
        else
        {
            curSum[i] = max(0ll, curSum[i-1] + arr[i]);    
        }
    
        maxSum = max(maxSum, curSum[i]);
    }

    return maxSum;
}


//Divide and conquer approach is also there using recursion