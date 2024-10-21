//link- https://www.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest
// Given an array arr, return the second largest distinct element from an array. If the second largest element doesn't exist then return -1.

// Examples:

// Input: arr = [12, 35, 1, 10, 34, 1]
// Output: 34
// Explanation: The largest element of the array is 35 and the second largest element is 34.
// Input: arr = [10, 10]
// Output: -1
// Explanation: The largest element of the array is 10 and the second largest element does not exist so answer is -1.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2 ≤ arr.size() ≤ 105
// 1 ≤ arri ≤ 105


#include<bits/stdc++.h>
using namespace std;
class Solution {   
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int largest=arr[0],secLargest=-1;
    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]>largest) 
        {
            secLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]>secLargest&&arr[i]!=largest)
        {
            secLargest=arr[i];
        }
    }
    return secLargest;
        
    }
};