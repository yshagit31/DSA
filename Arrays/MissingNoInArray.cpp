//link - https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1?page=1&sortBy=submissions
// Ques

// Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

// Example 1:

// Input:
// N = 5
// A[] = {1,2,3,5}
// Output: 4
// Example 2:

// Input:
// N = 10
// A[] = {6,1,2,8,3,4,7,10,5}
// Output: 9

// Your Task :
// You don't need to read input or print anything. Complete the function MissingNumber() that takes array and N as input  parameters and returns the value of the missing number.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ N ≤ 106
// 1 ≤ A[i] ≤ 106



//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        int sum=0,actualsum=0;
        for(int i=0;i<n-1;i++)
        {
            sum=sum+array[i];
        }
        actualsum=(n*(n+1))/2;
        return actualsum-sum;
    }
};

// or

class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {

        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            ans=ans^array[i];   //XOR of all elements from 1 to n and array elements gives the missing element
        }
        for(int i=1;i<=n;i++)
        {
            ans=ans^i;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends