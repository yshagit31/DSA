// Problem statement
// You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.



// Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.



// Note :
// 1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
// 2. 'arr' may contain duplicate elements.


// Example:
// Input: 'arr' = [0,1,1,5] , 'k' = 1

// Output: 1 2

// Explanation:
// If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 8 2
// 0 0 1 1 2 2 2 2


// Sample output 1:
// 4 7


// Explanation of Sample output 1:
// For this testcase the first occurrence of 2 in at index 4 and last occurrence is at index 7.


// Sample Input 2:
// 4 2
// 1 3 3 5


// Sample output 2:
// -1 -1


// Expected Time Complexity:
// Try to do this in O(log(n)).


// Constraints:
// 1 <= n <= 10^5
// 0 <= k <= 10^9
// 0 <= arr[i] <= 10^9

// Time Limit : 1 second

#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int>& arr ,int n , int k)
{
    int low=0,mid,high=n-1,ans=-1;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==k)
        {
             ans=mid;
             high=mid-1;
        } 
        else if(arr[mid]>k)
        {
            high=mid-1;
        }
     else {
         low=mid+1;
     }
    }
    return ans;
}
int lastOcc(vector<int>& arr ,int n , int k)
{
    int low=0,mid,high=n-1,ans=-1;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==k)
        {
            ans=mid;
             low=mid+1;
        } 
        else if(arr[mid]>k)
        {
            high=mid-1;
        }
     else {
         low=mid+1;
     }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
     pair<int,int> p;
      p.first=firstOcc(arr , n , k);
      p.second=lastOcc(arr, n, k);

    return p;

}

// Soln 2


class Solution {
public:
    int firstOcc(vector<int>& nums, int target)
    {
        int low=0,high=nums.size()-1,mid,ans=-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
      int lastOcc(vector<int>& nums, int target)
    {
        int low=0,high=nums.size()-1,mid,ans=-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> ans;
      ans.push_back(firstOcc(nums,target));
      ans.push_back(lastOcc(nums,target));
    return ans;
        
    }
};