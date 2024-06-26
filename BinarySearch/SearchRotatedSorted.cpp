//link - https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554
// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104'

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1,mid;
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(nums[mid]==target)   return mid;
             if(nums[mid]>=nums[s]) {   //If left half is sorted
                if(target>=nums[s]&&target<=nums[mid]) e=mid-1;
                else  s=mid+1;
            }
            else
            {   //If right half is sorted
                 if(target>=nums[mid]&&target<=nums[e])   s=mid+1;   
                else  e=mid-1;
            }
        }
        return -1;

        
    }
};


// search in array with duplicates 
// link- https://www.naukri.com/code360/problems/search-in-a-rotated-sorted-array-ii_7449547?leftPanelTabValue=PROBLEM
// Problem statement
// You are given a rotated sorted array 'a' of length 'n' and a 'key'. You need to determine if the 'key' exists in the array 'a'.

// The given sorted array is rotated from an unknown index 'x'. Such that after rotation the array became [a[x], a[x+1]...., a[n-1], a[1]..., a[x-1]], (0-based indexing). For example, if the array is [1, 2, 3, 4, 5] and x = 2 then the rotated array will be [3, 4, 5, 1, 2, 3].
// Return True if the 'key' is found in 'a'. Otherwise, return False.

// Note: Array ‘a’ may contain duplicate elements.
// Example:

// Input: a = [6, 10, 1, 3, 5], key = 3

// Output: True

// Explanation: The array 'a' contains the 'key' = 3, so we return True.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 7 4
// 3 4 5 0 0 1 2

// Sample Output 1:
// True

// Explanation Of Sample Input 1:
// Input: a = [3, 4, 5, 0, 0, 1, 2], key = 4

// Output: True

// Explanation: The array 'a' contains the 'key' = 3, so we return True.

// Sample Input 2:
// 6 47
// 31 44 56 0 10 13


// Sample Output 2:
// False

// Expected Time Complexity:
// Try to solve this with average time complexity O(log(n)).
// Constraints:
// 1 <= 'n' <= 10^5
// 0 <= 'a[i]', 'key' <= 10^9
// Time Limit: 1 sec

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    int s=0,e=A.size()-1,mid;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(A[mid]==key) return true;
        else if(A[mid]==A[s]&&A[mid]==A[e])
        {
            s++;e--;
            continue;
        }
        if(A[mid]>=A[s])
        {
            if(A[mid]>=key&&key>=A[s]) e=mid-1;
            else s=mid+1;
        }
        else if(A[mid]<=A[e])
        {
            if(key>=A[mid]&&key<=A[e]) s=mid+1;
            else e=mid-1;
        }
    }
    return false;
}
