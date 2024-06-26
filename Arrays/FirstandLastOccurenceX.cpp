// Given a sorted array having N elements, find the indices of the first and last occurrences of an element X in the given array.

// Note: If the number X is not found in the array, return '-1' as an array.

// Example 1:

// Input:
// N = 4 , X = 3
// arr[] = { 1, 3, 3, 4 }
// Output:
// 1 2
// Explanation:
// For the above array, first occurence
// of X = 3 is at index = 1 and last
// occurence is at index = 2.
// Example 2:

// Input:
// N = 4, X = 5
// arr[] = { 1, 2, 3, 4 }
// Output:
// -1
// Explanation: 
// As 5 is not present in the array,
// so the answer is -1.
// Your Task:
// You don't need to read input or print anything. Complete the function firstAndLast() that takes the array arr, its size N and the value X as input parameters and returns a list of integers containing the indices of first and last occurence of X.

// Expected Time Complexity: O(log(N))
// Expected Auxiliary Space: O(1)

// Constraints: 
// 1 <= N <= 10^5 

// 0 <= arr[i], X <= 109

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int first(vector <int> arr,int x)
    {
        int low=0,high=arr.size(),mid,ans=-1;
     while(low<=high)
     {
         mid=low+(high-low)/2;
         if(arr[mid]==x)
         {
            ans=mid;
            high=mid-1;
         }
         else if(arr[mid]<x)
         {
             low=mid+1;
         }
         else
         {
             high=mid-1;
         }
     }
     return ans;
    }
      int last(vector <int> arr,int x)
    {
        int low=0,high=arr.size(),mid,ans=1;
     while(low<=high)
     {
         mid=low+(high-low)/2;
         if(arr[mid]==x)
         {
            ans=mid;
            low=mid+1;
         }
         else if(arr[mid]<x)
         {
             low=mid+1;
         }
         else
         {
             high=mid-1;
         }
     }
     return ans;
    }
    
    
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        
     vector <int> ans;
     ans.push_back(first(arr,x));
     if(ans.back()==-1)
     return ans;
     ans.push_back(last(arr,x));
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}

// } Driver Code Ends