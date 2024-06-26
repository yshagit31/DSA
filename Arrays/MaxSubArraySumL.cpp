// link-https://leetcode.com/problems/maximum-subarray/description/
// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
 

// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

//In this one we take sum as negative when it is less than 0.




#include<bits/stdc++.h>
using namespace std;

//Brute force 
//will give TLE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int max=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
       int sum=0;
    for(int j=i;j<nums.size();j++)
    {
        sum=sum+nums[j];
        if(sum>max)
        {
            max=sum;
        }
    }
    }
    return max;
    }
};



//Inplace approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxS=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum=max(nums[i],sum+nums[i]);
            maxS=max(sum,maxS);
        }
        return maxS;
    }
};

//Array sum approach

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxS=INT_MIN,n=nums.size();
       int currSum[n];
    for(int i=0;i<nums.size();i++)
    {
    if(i==0) currSum[i]=nums[i];
    else currSum[i]=max(nums[i],nums[i]+currSum[i-1]);
    maxS=max(currSum[i],maxS);
    }
    return maxS;
    }
};


//Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxS=INT_MIN,sum=0,n=nums.size();
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>sum && sum<0) {sum=0; }
        sum=sum+nums[i];
        if(sum>maxS)
        {
            maxS=sum;
        }

    }
    return maxS;
    }
};