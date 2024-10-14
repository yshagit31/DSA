//link -https://www.naukri.com/code360/problems/pair-sum_697295?source=youtube&campaign=love_babbar_codestudio1
// Problem statement
// You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that 
//each sum of elements of each pair equals 'S'.

// Note:

// Each pair should be sorted i.e the first value should be less than or equals to the second value. 

// Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, 
//the pair with a smaller second value should come first.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= N <= 10^3
// -10^5 <= ARR[i] <= 10^5
// -2 * 10^5 <= S <= 2 * 10^5

// Time Limit: 1 sec
// Sample Input 1:
// 5 5
// 1 2 3 4 5
// Sample Output 1:
// 1 4
// 2 3
// Explaination For Sample Output 1:
// Here, 1 + 4 = 5
//       2 + 3 = 5
// Hence the output will be, (1,4) , (2,3).
// Sample Input 2:
// 5 0
// 2 -3 3 3 -2
// Sample Output 2:
// -3 3
// -3 3
// -2 2

//take one element then try its sum with all others, store min( of the nos whose sum is what we require) at first place in vector and bigger on second place
//sort the vector at last 


#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s){
 int num;
 vector <int> newrow;
 vector <vector<int>> vec;
   for(int i=0;i<arr.size();i++)
   {
    for(int j=i+1;j<arr.size();j++)
    {
       if(arr[i]+arr[j]==s)
       {
          newrow={min(arr[i],arr[j]),max(arr[i],arr[j])};
          vec.push_back(newrow);
       }
    }
   }
   sort(vec.begin(),vec.end());
   return vec;
}

//link - https://leetcode.com/problems/two-sum/description/
// 1. Two Sum
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 
// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
 

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?


//Brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                 return {i,j};
            }
        }
        return {-1};
    }
};

// two pass hash map

//one pass hash map soln

//two pointer soln
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
     {
       
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++)
        {
            arr.push_back({nums[i],i});
        }
         sort(arr.begin(),arr.end());
        vector<int> ans;
       int low=0,high=nums.size()-1;
       while(low<=high)
       {
        if(arr[low].first+arr[high].first>target) high--;
        else if(arr[low].first+arr[high].first<target) low++;
        else if(arr[low].first+arr[high].first==target) {
            ans.push_back(arr[low].second);
            ans.push_back(arr[high].second);
            return ans;
        }
       }
       return {-1,-1};
    }
};